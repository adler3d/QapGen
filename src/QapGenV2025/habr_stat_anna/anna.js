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
  // Преобразует "36K" в 36000, "1.2K" в 1200 и т.п.
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

  let page = 1;
  let hasNextPage = true;
  results[hubSlug] = [];

  while (hasNextPage) {
    const url = page === 1 ? hubUrl : `${hubUrl}page${page}/`;
    const html = await fetchPage(url);
    if (!html) break;

    const $ = cheerio.load(html);

    const articles = $('article.tm-articles-list__item');
    if (articles.length === 0) break;

    articles.each((_, el) => {
      const article = $(el);

      // Собираем хабы статьи
      const hubs = [];
      article.find('a.tm-publication-hub__link').each((_, hubEl) => {
        const href = $(hubEl).attr('href');
        if (href && href.startsWith('/ru/hubs/')) {
          const slug = href.split('/').filter(Boolean).pop();
          hubs.push(slug);
        }
      });

      // Просмотры
      const viewsStr = article.find('span.tm-icon-counter__value').attr('title') || '';
      const views = parseNumber(viewsStr);

      // Плюсы/минусы
      const votesTitle = article.find('span.tm-votes-meter__value').attr('title') || '';
      // Пример title: "Всего голосов 205: ^198 и v7"
      let pluses = 0, minuses = 0;
      const match = votesTitle.match(/^(\d+)/);
      if (match) pluses = parseInt(match[1], 10);
      const match2 = votesTitle.match(/v(\d+)/);
      if (match2) minuses = parseInt(match2[1], 10);

      results[hubSlug].push({
        title: article.find('a.tm-article-snippet__title-link').text().trim(),
        url: baseUrl + article.find('a.tm-article-snippet__title-link').attr('href'),
        views,
        pluses,
        minuses,
        hubs
      });

      // Рекурсивно обрабатываем новые хабы
      hubs.forEach(h => {
        if (!visitedHubs.has(h)) {
          // Добавим в очередь, но не здесь, чтобы избежать "зависания"
          hubsToProcess.add(h);
        }
      });
    });

    // Проверка на следующую страницу
    const nextBtn = $('.tm-pagination__page-link').filter((_, el) => {
      return $(el).text().trim() === String(page + 1);
    });
    hasNextPage = false;//nextBtn.length > 0;
    page++;
  }
}

// Очередь хабов для обработки
const hubsToProcess = new Set([startHub]);

async function main() {
  while (hubsToProcess.size > 0) {
    // Берём один хаб из множества
    const [hub] = hubsToProcess;
    hubsToProcess.delete(hub);

    await parseHub(hub);
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
