const fs = require('fs');

// Функция для удаления пробела перед скобкой после идентификатора
function fixSpacesBeforeParen(input) {
  // Регулярка: слово + пробел + (
  // \b - граница слова, \w+ - идентификатор, \s+ - пробелы, \{ - скобка
  return input.replace(/(\b\w+)\s+\{/g, '$1{');
}

// Пример использования: читаем файл или строку
const fn="t_asmcpplike_lexers.qapdsl_v2.hpp";
const input = fs.readFileSync(fn, 'utf8'); // или вставь строку напрямую

const output = fixSpacesBeforeParen(input);

fs.writeFileSync(fn, output, 'utf8');

// Для теста можно просто вывести результат
// console.log(output);
