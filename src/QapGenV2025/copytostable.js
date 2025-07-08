const fs = require('fs');
const path = require('path');

const srcRoot = __dirname; // ./src/QapGenV2025/
const srcQapGen = path.join(srcRoot, 'QapGen');
const stableRoot = path.resolve(srcRoot, '../../stable'); // ../../stable ������������ srcRoot
const stableQapGen = path.join(stableRoot, 'QapGen');

// ������� ����������� ������ (�� ����������) �� srcDir � destDir
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

// �������� �� ./src/QapGenV2025/QapGen/ � ./stable/QapGen/
copyFilesNonRecursive(srcQapGen, stableQapGen);

// �������� �� ./src/QapGenV2025/ � ./stable/
copyFilesNonRecursive(srcRoot, stableRoot);
