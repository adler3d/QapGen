const fs = require('fs');
const path = require('path');

const srcRoot = __dirname; // ./src/QapGenV2025/
const srcQapGen = path.join(srcRoot, 'QapGen');
const stableRoot = path.resolve(srcRoot, '../../stable'); // ../../stable относительно srcRoot
const stableQapGen = path.join(stableRoot, 'QapGen');

// Функция копирования файлов (не рекурсивно) из srcDir в destDir
function copyFilesNonRecursive(srcDir, destDir) {
  if (!fs.existsSync(destDir)) {
    fs.mkdirSync(destDir, { recursive: true });
  }
  const files = fs.readdirSync(srcDir, { withFileTypes: true });
  for (const file of files) {
    if (file.isFile()) {
      if(file.name.includes("copytostable.js"))continue;
      const srcFile = path.join(srcDir, file.name);
      const destFile = path.join(destDir, file.name);
      fs.copyFileSync(srcFile, destFile);
      console.log(`Copied file ${srcFile} -> ${destFile}`);
    }
  }
}

// Копируем из ./src/QapGenV2025/QapGen/ в ./stable/QapGen/
copyFilesNonRecursive(srcQapGen, stableQapGen);

// Копируем из ./src/QapGenV2025/ в ./stable/
copyFilesNonRecursive(srcRoot, stableRoot);
