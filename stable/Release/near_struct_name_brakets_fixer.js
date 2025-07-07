const fs = require('fs');

// ������� ��� �������� ������� ����� ������� ����� ��������������
function fixSpacesBeforeParen(input) {
  // ���������: ����� + ������ + (
  // \b - ������� �����, \w+ - �������������, \s+ - �������, \{ - ������
  return input.replace(/(\b\w+)\s+\{/g, '$1{');
}

// ������ �������������: ������ ���� ��� ������
const fn="t_line_lexer.qapdsl.hpp";
const input = fs.readFileSync(fn, 'utf8'); // ��� ������ ������ ��������

const output = fixSpacesBeforeParen(input);

fs.writeFileSync(fn, output, 'utf8');

// ��� ����� ����� ������ ������� ���������
// console.log(output);
