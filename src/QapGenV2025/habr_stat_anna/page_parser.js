const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');
const path = require('path');

const results = {};

function parseNumber(str) {
  if (!str) return 0;
  str = str.toUpperCase();
  if (str.endsWith('K')) return parseFloat(str) * 1000;
  if (str.endsWith('M')) return parseFloat(str) * 1_000_000;
  return parseInt(str.replace(/\D/g, ''), 10) || 0;
}

var files=fs.readdirSync("out").filter(e=>e.includes("."));
var url2stat={};
function parsePage(fn) {

  console.log(`fn pass: `+fn);

  //const hubUrl = `${baseUrl}/ru/hubs/${hubSlug}/articles/top/${period}/`;

  const html = ""+fs.readFileSync("out/"+fn);
  if (!html) return;

  const $ = cheerio.load(html);

  const articles = $('article.tm-articles-list__item');
  if (articles.length === 0) {
    console.log(`Статей не найдено в хабе ${hubSlug}`);
    return;
  }

  results[fn] = [];

  articles.each((_, el) => {
    const article = $(el);

    // Заголовок и ссылка
    const titleEl = article.find('a[data-test-id="article-snippet-title-link"]').first();
    const title = titleEl.text().trim();
    const urlPath = titleEl.attr('href');
    const url = urlPath;

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

        const plusMatch = title.match(/^(\d+)/);
        if (plusMatch) pluses = parseInt(plusMatch[1], 10);

        const minusMatch = title.match(/v(\d+)/);
        if (minusMatch) minuses = parseInt(minusMatch[1], 10);

        rating = parseInt(innerText.replace(/\+/g, '').trim(), 10) || 0;
      }
    }
    var r={title,url,views,pluses,minuses,rating};
    if(!(url in url2stat))url2stat[url]=[r,[],[]];
    {
      var a=url2stat[url][1];var b={};
      "views,pluses,minuses,rating".split(",").map(e=>{b[e]=r[e]});
      a.push(b);
    }
    results[fn].push(r);

  });
}


async function main() {
  files.map(e=>parsePage(e));
  var ret={};
  //var arr=url2stat[url][2];
  for(var url in url2stat){
    var a=url2stat[url][1];
    let arr=a.map((e,i)=>{if(!i)return 0;return e.views-a[i-1].views;});
    url2stat[url][2]=""+arr;
    let c=0;
    url2stat[url][3]=arr.map((e,i)=>{c+=e;return c/(i+1);});
    var a=[];
    for(var i=0;i<arr.length;i+=6){
      var n=0;
      for(var j=0;j<6&&i+j<arr.length;j++)n+=arr[i+j];
      a.push(n);
    }
    ret[url]=JSON.stringify(a);
    if(!('log' in ret))ret.log={};
    ret.log[url]=arr+"";
  }
  const outPath = path.resolve(__dirname, `out_page_stats.json`);
  //console.log('\nhubs:', Array.from(visitedHubs).join(', '));
  //console.log(`\ndone. see ${outPath}`);
  //console.log(`\nhubs_total: ${visitedHubs.size}`);
  // Сохраняем результаты
  fs.writeFileSync(outPath, JSON.stringify(ret, null, 2), 'utf-8');
}

main().catch(e => {
  console.error('Ошибка в основном процессе:', e);
});
