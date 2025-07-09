const fs = require('fs');
const path = require('path');

const baseDir = path.resolve(__dirname, 'out');
const outputFile = path.resolve(__dirname, 'merged.json');

async function readDirRecursive(dir) {
  const entries = await fs.promises.readdir(dir, { withFileTypes: true });
  let files = [];

  for (const entry of entries) {
    const fullPath = path.join(dir, entry.name);
    if (entry.isDirectory()) {
      const nestedFiles = await readDirRecursive(fullPath);
      files = files.concat(nestedFiles);
    } else if (entry.isFile()) {
      files.push(fullPath);
    }
  }

  return files;
}

async function main() {
  try {
    const files = await readDirRecursive(baseDir);
    const result = [];

    for (const filePath of files) {
      try {
        const contentRaw = await fs.promises.readFile(filePath, 'utf-8');
        const content = JSON.parse(contentRaw);
        result.push({
          file: filePath,
          content,
        });
      } catch (err) {
        console.error(`parse error ${filePath}:`, err.message);
        // Можно продолжить или прервать выполнение, в зависимости от задачи
      }
    }

    await fs.promises.writeFile(outputFile, JSON.stringify(result, null, 2), 'utf-8');
    console.log(`done: ${outputFile}`);
  } catch (err) {
    console.error('error:', err);
  }
}

main();
