const fs = require('fs');
const path = require('path');

const inputFile = path.resolve(__dirname, 'habr_hubs_stats_programming_monthly.json');//monthly
const outputFile = path.resolve(__dirname, 'top_hubs_by_rating_filtered.json');

const rawData = fs.readFileSync(inputFile, 'utf-8');
const data = JSON.parse(rawData);

// Фильтруем хабы с количеством статей >= 16
const filteredHubsByCount = {};
for (const [hub, articles] of Object.entries(data)) {
  if (articles.length >= 3) {
    filteredHubsByCount[hub] = articles;
  }
}
//console.log(`hub with >=16 articles: ${Object.keys(filteredHubsByCount).length}`);

// Функция для подсчёта статистики по хабам
function calculateHubStats(data) {
  const hubStats = {};
  for (const [hub, articles] of Object.entries(data)) {
    let totalRating = 0;
    let totalViews = 0;
    let count = 0;
    //const limitedArticles = articles.slice(0, 20);
    for (const article of articles) {
      if (!article) continue;
      const rating = article.rating || 0;
      const views = article.views || 0;
      if (rating > 0) {
        totalRating += rating;
        totalViews += views;
        count++;
      }
    }
    if (count > 0) {
      hubStats[hub] = {
        hub,
        average_rating: totalRating / count,
        avg_views: totalViews / count,
        views_per_rating: totalRating > 0 ? totalViews / totalRating : 0,
        articles_count: count,
      };
    }
  }
  return hubStats;
}

var tracet_hubs={cpp:1,c:1,programming:1,algorithms:1};
// Считаем статистику по отфильтрованным хабам
const hubStats = calculateHubStats(filteredHubsByCount);
for(var k in tracet_hubs){
  console.log(JSON.stringify(Object.values(hubStats).filter(e=>e.hub==k)));
}
// Создаём словарь avg_views по хабам
const avgViewsByHub = {};
for (const [hub, stats] of Object.entries(hubStats)) {
  avgViewsByHub[hub] = stats.avg_views;
}

const threshold = 1.05; // 5% запас

// Фильтруем статьи внутри каждого хаба
const filteredData = {};
var hub2a={};
for (const [hub, articles] of Object.entries(filteredHubsByCount)) {
  const hubAvgViews = avgViewsByHub[hub];
  if (hubAvgViews === undefined) {
    filteredData[hub] = articles;
    continue;
  }
  filteredData[hub] = articles.filter(article => {
    if (!article || !Array.isArray(article.hubs)) return false;
    const hasMorePopularHub = article.hubs.some(h => {
      const otherAvgViews = avgViewsByHub[h];
      return otherAvgViews !== undefined && otherAvgViews > hubAvgViews * threshold;
    });
    if(!hasMorePopularHub){if(!(hub in hub2a))hub2a[hub]=[];hub2a[hub].push(article);}
    return !hasMorePopularHub;
  });
  //console.log(`${hub}: src ${articles.length}, after ${filteredData[hub].length}`);
}
let filteredHubStats = calculateHubStats(filteredData);
for(var k in tracet_hubs){
  console.log(JSON.stringify(Object.values(filteredHubStats).filter(e=>e.hub==k)));
  console.log(hub2a[k]);
}
// Сортируем по avg_views по убыванию
const sortedHubs = Object.values(filteredHubStats)
  .filter(h => h.articles_count >= 0)
  .sort((a, b) => b.avg_views - a.avg_views);
// Выводим результаты
console.log(`Rank | Hub                  | Avg Rating  | avg_views   | Views/Rating | Articles`);
console.log('---------------------------------------------------------------------------------');
sortedHubs.slice(0, 46).forEach((hubInfo, idx) => {
  console.log(
    `${String(idx + 1).padEnd(4)} | ` +
    `${hubInfo.hub.padEnd(20)} | ` +
    `${hubInfo.average_rating.toFixed(2).padEnd(11)} | ` +
    `${String(hubInfo.avg_views.toFixed(2)).padEnd(11)} | ` +
    `${hubInfo.views_per_rating.toFixed(2).padEnd(12)} | ` +
    `${hubInfo.articles_count}`
  );
});

// Сохраняем результат
fs.writeFileSync(outputFile, JSON.stringify(sortedHubs, null, 2), 'utf-8');
console.log(`\nFiltered list saved to ${outputFile}`);
