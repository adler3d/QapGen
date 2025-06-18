const fs = require('fs');

function parseCppToQapDSL(cppCode) {
  const lines = cppCode.split('\n');
  const output = [];

  let inClass = false;
  let className = '';
  let parentName = '';
  let fields = [];
  let afterGoLines = [];
  let goBodyLines = [];
  let inGoMethod = false;
  let braceLevel = 0;
  let inDefineBlock = false;

  function indent(line, level = 1) {
    return '  '.repeat(level) + line;
  }

  function flushClass() {
    if (!inClass) return;

    let header = className;
    if (parentName) header += '=>' + parentName;
    header += '{';

    output.push(header);

    for (const f of fields) {
      output.push(indent(`${f.type} ${f.name};`));
    }

    if (goBodyLines.length > 0) {
      output.push(indent('{'));
      for (const l of goBodyLines) {
        output.push(indent(l, 1));
      }
      output.push(indent('}'));
    }

    output.push(indent('[::]'));

    // Обработка многострочных блоков после go с аккумулированием
    let blockBuffer = [];
    let openCurly = 0;
    let openSquare = 0;
    let openRound = 0;

    function flushBuffer() {
      if (blockBuffer.length === 0) return;
      for (const line of blockBuffer) {
        // Отступ на уровень класса + вложенность по скобкам
        output.push(indent(line, 1 + openCurly));
      }
      blockBuffer = [];
    }

    for (const lineRaw of afterGoLines) {
      blockBuffer.push(lineRaw);

      openCurly += (lineRaw.match(/{/g) || []).length;
      openCurly -= (lineRaw.match(/}/g) || []).length;
      openSquare += (lineRaw.match(/\[/g) || []).length;
      openSquare -= (lineRaw.match(/]/g) || []).length;
      openRound += (lineRaw.match(/\(/g) || []).length;
      openRound -= (lineRaw.match(/\)/g) || []).length;

      // Если все скобки закрыты и строка заканчивается на ';' или пустая строка,
      // считаем, что блок завершён
      if (openCurly <= 0 && openSquare <= 0 && openRound <= 0 && (lineRaw.trim().endsWith(';') || lineRaw.trim() === '')) {
        flushBuffer();
      }
    }
    flushBuffer();

    output.push('}');

    // Сброс состояния
    inClass = false;
    className = '';
    parentName = '';
    fields = [];
    afterGoLines = [];
    goBodyLines = [];
  }

  function processGoLine(lineRaw) {
    const trimmed = lineRaw.trim();

    if (!trimmed.includes('go_')) return null;

    if (
      /^auto\b/.test(trimmed) ||
      /^if\s*\(/.test(trimmed) ||
      /^return\b/.test(trimmed) ||
      /^t_fallback\b/.test(trimmed) ||
      /^bool\b/.test(trimmed) ||
      /^const\b/.test(trimmed) ||
      /^static\b/.test(trimmed) ||
      /^struct\b/.test(trimmed) ||
      /^typedef\b/.test(trimmed) ||
      /^using\b/.test(trimmed) ||
      /^template\b/.test(trimmed) ||
      /^virtual\b/.test(trimmed) ||
      /^public:/.test(trimmed) ||
      /^private:/.test(trimmed) ||
      /^protected:/.test(trimmed)
    ) return null;

    return lineRaw.replace(/\bdev\./g, '');
  }

  for (let i = 0; i < lines.length; i++) {
    let lineRaw = lines[i];
    let line = lineRaw.trim();

    if (line.startsWith('class ')) {
      flushClass();

      let classLine = line;
      if (classLine.endsWith('{')) {
        classLine = classLine.slice(0, -1).trim();
      }
      let parts = classLine.split(/[:\s]+/).filter(Boolean);
      className = parts[1] || '';
      parentName = '';
      if (parts.length >= 4 && parts[2] === 'public') {
        parentName = parts[3];
      }

      inClass = true;
      continue;
    }

    if (!inClass) continue;

    if (!inGoMethod) {
      if (!inDefineBlock && line.startsWith('#define')) {
        inDefineBlock = true;
        if (!lineRaw.trimEnd().endsWith('\\')) {
          inDefineBlock = false;
        }
        if (line.includes('ADDVAR(')) {
          let params = line.slice(line.indexOf('ADDVAR(') + 'ADDVAR('.length, line.indexOf(')', line.indexOf('ADDVAR(')));
          let parts = params.split(',').map(p => p.trim());
          if (parts.length >= 2) {
            fields.push({ type: parts[0], name: parts[1] });
          }
        }
        continue;
      }

      if (inDefineBlock) {
        if (line.includes('ADDVAR(')) {
          let params = line.slice(line.indexOf('ADDVAR(') + 'ADDVAR('.length, line.indexOf(')', line.indexOf('ADDVAR(')));
          let parts = params.split(',').map(p => p.trim());
          if (parts.length >= 2) {
            fields.push({ type: parts[0], name: parts[1] });
          }
        }
        if (!lineRaw.trimEnd().endsWith('\\')) {
          inDefineBlock = false;
        }
        continue;
      }
    }

    if (!inGoMethod) {
      if (line.startsWith('#include') || line.startsWith('//')) {
        continue;
      }
    }

    if (!inGoMethod && line.startsWith('bool go(i_dev&dev)')) {
      inGoMethod = true;

      let openBracePos = lineRaw.indexOf('{');
      if (openBracePos !== -1) {
        braceLevel = 1;
        let afterBrace = lineRaw.slice(openBracePos + 1).trim();
        if (afterBrace.length > 0) {
          let processed = processGoLine(afterBrace);
          if (processed) goBodyLines.push(processed);
        }
      } else {
        while (i + 1 < lines.length) {
          i++;
          const nextLineRaw = lines[i];
          const nextLine = nextLineRaw.trim();
          if (nextLine === '{') {
            braceLevel = 1;
            break;
          }
        }
      }
      continue;
    }

    if (inGoMethod) {
      if (line.includes('{')) braceLevel += (line.match(/{/g) || []).length;
      if (line.includes('}')) braceLevel -= (line.match(/}/g) || []).length;

      if (line !== '{' && line !== '}') {
        let processed = processGoLine(lineRaw);
        if (processed) goBodyLines.push(processed);
      }

      if (braceLevel === 0) {
        inGoMethod = false;
      }
      continue;
    }

    // Фильтруем закрывающие скобки с точкой с запятой и служебные метки доступа
    if (
      line.trim() === '};' ||
      line.trim() === '}' ||
      ['public:', 'private:', 'protected:'].includes(line.trim())
    ) {
      continue;
    }

    afterGoLines.push(lineRaw);
  }

  flushClass();

  return output.join('\n');
}



// Пример использования:
const inputCpp = fs.readFileSync('input.cpp', 'utf8');
const outputQapDSL = parseCppToQapDSL(inputCpp);
console.log(outputQapDSL);
