const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');
const path = require('path');

const baseUrl = 'https://habr.com';

// Параметры из командной строки
// node script.js programming week
const [,, startHub = 'programming', period = 'monthly'] = process.argv;

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
    const titleEl = article.find('a.tm-article-snippet__title-link');
    const title = titleEl.text().trim();
    const urlPath = titleEl.attr('href');
    const url = urlPath ? baseUrl + urlPath : '';

    // Просмотры
    const viewsStr = article.find('span.tm-icon-counter__value').attr('title') || '';
    const views = parseNumber(viewsStr);

    // Плюсы, минусы и финальная оценка (рейтинг)
    const votesSpan = article.find('span.tm-votes-meter__value');
    let pluses = 0, minuses = 0, rating = 0;
    if (votesSpan.length) {
      const votesTitle = votesSpan.attr('title') || '';
      const plusMatch = votesTitle.match(/^(\d+)/);
      if (plusMatch) pluses = parseInt(plusMatch[1], 10);
      const minusMatch = votesTitle.match(/v(\d+)/);
      if (minusMatch) minuses = parseInt(minusMatch[1], 10);

      // Финальная оценка — чаще всего это текст внутри span, например "+222"
      const ratingText = votesSpan.text().trim();
      // Убираем знак "+" и пробелы, парсим число
      rating = parseInt(ratingText.replace(/\+/g, '').trim(), 10) || 0;
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
    break;
  }

  // Сохраняем результаты
  const outPath = path.resolve(__dirname, `habr_hubs_stats_${startHub}_${period}.json`);
  fs.writeFileSync(outPath, JSON.stringify(results, null, 2), 'utf-8');
  console.log('\nhubs:', Array.from(visitedHubs).join(', '));
  console.log(`\ndone. see ${outPath}`);
  console.log(`\nhubs_total: ${visitedHubs.size}`);
}

main().catch(e => {
  console.error('Ошибка в основном процессе:', e);
});
