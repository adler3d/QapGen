const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');

const startId = 916006;
const baseUrl = 'https://habr.com/ru/articles/';
const maxEmptyTries = 5; // how many consecutive missing articles to wait before stopping

async function parseArticle(id) {
  const url = `${baseUrl}${id}/`;
  try {
    const { data } = await axios.get(url);
    const $ = cheerio.load(data);

    // Views
    const viewsText = $('span.tm-icon-counter__value').attr('title') || $('span.tm-icon-counter__value').text();
    const views = viewsText ? parseInt(viewsText.replace(/\D/g, '')) : null;

    // Rating
    //const article = $('article');
    //var r=article.find('span[data-test-id="votes-score-counter"]').first();//;
    var ratingText = ""+($('span[data-test-id="votes-score-counter"]'));//.text();
    var befp='data-test-id=\"votes-score-counter\">+';
    var befm='data-test-id=\"votes-score-counter\">-';
    var f=e=>{var a=ratingText.split(e);if(a.length==1)return null;return a[1].split("<")[0]|0;};
    var p=f(befp);
    var m=f(befm);
    var r=m;
    if(p!==null)r=p;
    const rating = r;//+" "+ratingText;//.substr(1)|0;

    // Bookmarks
    const bookmarksText = $('span.bookmarks-button__counter').text();
    const bookmarks = bookmarksText ? parseInt(bookmarksText.replace(/\D/g, '')) : null;

    // Comments
    const commentsText = $('span.tm-article-comments-counter-link__value').text();
    const comments = commentsText ? parseInt(commentsText.replace(/\D/g, '')) : null;

    // Since pluses and minuses are not displayed, we set them to null
    const pluses = null;
    const minuses = null;

    // If all main stats are null, consider article missing
    if ([views, rating, bookmarks, comments].every(v => v === null)) {
      return null;
    }

    return {
      id,
      url,
      views,
      rating,
      bookmarks,
      comments
    };
  } catch (e) {
    if (e.response && e.response.status === 404) {
      // Article not found
      return null;
    }
    console.error(`Error parsing article ID=${id}:`, e.message);
    return null;
  }
}

async function main() {
  let currentId = startId;
  const results = [];
  let emptyCount = 0;

  while (currentId<=923358) {
    console.log(`Parsing article ID=${currentId}...`);
    const data = await parseArticle(currentId);
    if (data) {
      results.push(data);
      emptyCount = 0;
      console.log(`Article ID=${currentId} added.`);
    } else {
      emptyCount++;
      console.log(`Article ID=${currentId} not found or no data available.`);
    }
    currentId++;//break;
    if(currentId%200==199)fs.writeFileSync('habr_articles_stats2.json', JSON.stringify(results, null, 2), 'utf-8');
    //break; //https://habr.com/ru/articles/923358/
  }

  fs.writeFileSync('habr_articles_stats2.json', JSON.stringify(results, null, 2), 'utf-8');
  console.log(`Finished. Total articles saved: ${results.length}`);
}

main();
