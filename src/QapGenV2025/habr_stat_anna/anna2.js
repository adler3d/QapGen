const fs = require('fs');
const path = require('path');

// Путь к входному JSON-файлу с данными
//const inputFile = path.resolve(__dirname, 'habr_hubs_stats_programming_monthly.json');
const inputFile = path.resolve(__dirname, 'habr_hubs_stats_programming_monthly.json');

// Путь к выходному JSON-файлу с результатами
const outputFile = path.resolve(__dirname, 'top_hubs_by_rating.json');

// Читаем и парсим JSON
const rawData = fs.readFileSync(inputFile, 'utf-8');
const data = JSON.parse(rawData);

const hubStats = {};

// Обрабатываем каждый хаб
for (var [hub, articles] of Object.entries(data)) {
  let totalRating = 0;
  let totalViews = 0;
  let count = 0;
  articles.length=20;
  //articles=[articles[19],articles[18],articles[17],articles[16]];
  for (const article of articles) {
    if(!article)continue;
    //if(article.hubs.includes("cpp"))console.log(JSON.stringify(article,0,2));
    //if(article.hubs.length!=1)continue;
    const rating = article.rating || 0;
    const views = article.views || 0;

    if (rating > 0) {
      totalRating += rating;
      totalViews += views;
      count++;
    }
  }

  if (count > 0) {
    const avgRating = totalRating / count;
    const viewsPerRating = totalRating > 0 ? totalViews / totalRating : 0;

    hubStats[hub] = {
      hub,
      average_rating: avgRating,
      avg_views: totalViews/count,
      views_per_rating: viewsPerRating,
      articles_count: count,
    };
  }
}

// Сортируем по среднему рейтингу по убыванию
var sortedHubs = Object.values(hubStats).filter(e=>e.articles_count>=3).sort((a, b) => (b.avg_views - a.avg_views));
//sortedHubs.length=30;
//sortedHubs=sortedHubs.sort((a, b) => (b.average_rating - a.average_rating));
//sortedHubs=sortedHubs.sort((a, b) => -(b.views_per_rating - a.views_per_rating));
sortedHubs.length=20;
sortedHubs=sortedHubs.sort((a, b) => (b.avg_views - a.avg_views));
// Выводим топ-20 в консоль                              
console.log(`Rank | Hub                  | Avg Rating  | avg_views   | Views/Rating | Articles`);
console.log('---------------------------------------------------------------------------------');
sortedHubs.slice(0, 20).forEach((hubInfo, idx) => {
  console.log(
    `${String(idx + 1).padEnd(4)} | ` +
    `${hubInfo.hub.padEnd(20)} | ` +
    `${hubInfo.average_rating.toFixed(2).padEnd(11)} | ` +
    `${String(hubInfo.avg_views.toFixed(2)).padEnd(11)} | ` +
    `${hubInfo.views_per_rating.toFixed(2).padEnd(12)} | ` +
    `${hubInfo.articles_count}`
  );
});

// Сохраняем полный результат в JSON
fs.writeFileSync(outputFile, JSON.stringify(sortedHubs, null, 2), 'utf-8');
console.log(`\nlist in ${outputFile}`);
