const fs = require('fs');

// Функция для удаления пробела перед скобкой после идентификатора
function fixSpacesBeforeParen(input) {
  // Регулярка: слово + пробел + (
  // \b - граница слова, \w+ - идентификатор, \s+ - пробелы, \( - скобка
  return input.replace(/(\b\w+)\s+\(/g, '$1(');
}

// Пример использования: читаем файл или строку
const input = fs.readFileSync('t_line_lexer.qapdsl.hpp', 'utf8'); // или вставь строку напрямую

const output = fixSpacesBeforeParen(input);

fs.writeFileSync('t_line_lexer.qapdsl.hpp', output, 'utf8');

// Для теста можно просто вывести результат
// console.log(output);
