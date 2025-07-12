const fs = require('fs').promises;
const path = require('path');
const axios = require('axios');

async function savePage() {
  try {
    const url = 'https://habr.com/ru/users/Adler3D/articles/';
    const response = await axios.get(url);

    const now = new Date();
    const filename = now.getFullYear().toString() +
      String(now.getMonth() + 1).padStart(2, '0') +
      String(now.getDate()).padStart(2, '0') +
      String(now.getHours()).padStart(2, '0') +
      String(now.getMinutes()).padStart(2, '0') +
      String(now.getSeconds()).padStart(2, '0') + '.html';

    const outDir = path.resolve('out');
    await fs.mkdir(outDir, { recursive: true });

    const filePath = path.join(outDir, filename);
    await fs.writeFile(filePath, response.data, 'utf-8');

    console.log(`Page saved to ${filePath}`);
  } catch (err) {
    console.error('Error fetching or saving page:', err);
  }
}

savePage();
setInterval(savePage, 10 * 60 * 1000);
