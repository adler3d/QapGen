const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');
const path = require('path');

const baseUrl = 'https://habr.com';

// Параметры из командной строки
// node script.js programming week
//const [,, startHub = 'programming', period = 1?'daily':(1?'yearly':(1?'monthly':'weekly'))] = process.argv;
const [,, startHub = 'programming', period = 'daily'] = process.argv;
console.log(period);
const visitedHubs = new Set();
const results = {};

async function fetchPage(url) {
  try {
    const { data } = await axios.get(url);
    return data;
  } catch (e) {
    console.error(`load err ${url}:`, e.message);
    return null;
  }
}

function parseNumber(str) {
  if (!str) return 0;
  str = str.toUpperCase();
  if (str.endsWith('K')) return parseFloat(str) * 1000;
  if (str.endsWith('M')) return parseFloat(str) * 1_000_000;
  return parseInt(str.replace(/\D/g, ''), 10) || 0;
}

async function parseHub(hubSlug) {
  if (visitedHubs.has(hubSlug)) return;
  visitedHubs.add(hubSlug);

  console.log(`hub pass #${visitedHubs.size}: ${hubSlug}`);

  const hubUrl = `${baseUrl}/ru/hubs/${hubSlug}/articles/top/${period}/`;

  const html = await fetchPage(hubUrl);
  if (!html) return;

  const $ = cheerio.load(html);

  const articles = $('article.tm-articles-list__item');
  if (articles.length === 0) {
    console.log(`Статей не найдено в хабе ${hubSlug}`);
    return;
  }

  results[hubSlug] = [];

  articles.each((_, el) => {
    const article = $(el);

    // Заголовок и ссылка
    const titleEl = article.find('a[data-test-id="article-snippet-title-link"]').first();
    const title = titleEl.text().trim();
    const urlPath = titleEl.attr('href');
    const url = urlPath ? baseUrl + urlPath : '';

    // Просмотры
    const viewsStr = article.find('span.tm-icon-counter__value').attr('title') || '';
    const views = parseNumber(viewsStr);

    const votesContainer = article.find('div.tm-votes-meter.tm-data-icons__item');

    let pluses = 0, minuses = 0, rating = 0;

    if (votesContainer.length) {
      const votesSpan = votesContainer.find('span[data-test-id="votes-meter-value"]').first();

      if (votesSpan.length) {
        const title = votesSpan.attr('title') || '';
        const innerText = votesSpan.text().trim();

        const plusMatch = title.match(/↑(\d+)/);
        if (plusMatch) pluses = parseInt(plusMatch[1], 10);

        const minusMatch = title.match(/↓(\d+)/);
        if (minusMatch) minuses = parseInt(minusMatch[1], 10);

        rating = parseInt(innerText.replace(/\+/g, '').trim(), 10) || 0;
      }
    }
    
    // Хабы статьи
    const hubs = [];
    article.find('a.tm-publication-hub__link').each((_, hubEl) => {
      const href = $(hubEl).attr('href');
      if (href && href.startsWith('/ru/hubs/')) {
        const slug = href.split('/').filter(Boolean).pop();
        hubs.push(slug);
      }
    });

    results[hubSlug].push({
      title,
      url,
      views,
      pluses,
      minuses,
      rating,
      hubs
    });

    // Рекурсивно добавляем новые хабы в очередь
    hubs.forEach(h => {
      if (!visitedHubs.has(h)) {
        hubsToProcess.add(h);
      }
    });
  });
}

// Очередь хабов для обработки
const hubsToProcess = new Set([startHub]);

async function main() {
  while (hubsToProcess.size > 0) {
    const [hub] = hubsToProcess;
    hubsToProcess.delete(hub);

    await parseHub(hub);
    //break;
  }

  const outPath = path.resolve(__dirname, `habr_hubs_stats_${startHub}_${period}.json`);
  console.log('\nhubs:', Array.from(visitedHubs).join(', '));
  console.log(`\ndone. see ${outPath}`);
  console.log(`\nhubs_total: ${visitedHubs.size}`);
  // Сохраняем результаты
  fs.writeFileSync(outPath, JSON.stringify(results, null, 2), 'utf-8');
}

main().catch(e => {
  console.error('Ошибка в основном процессе:', e);
});
