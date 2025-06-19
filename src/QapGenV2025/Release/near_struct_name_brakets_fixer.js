const fs = require('fs');

// ������� ��� �������� ������� ����� ������� ����� ��������������
function fixSpacesBeforeParen(input) {
  // ���������: ����� + ������ + (
  // \b - ������� �����, \w+ - �������������, \s+ - �������, \( - ������
  return input.replace(/(\b\w+)\s+\(/g, '$1(');
}

// ������ �������������: ������ ���� ��� ������
const input = fs.readFileSync('t_line_lexer.qapdsl.hpp', 'utf8'); // ��� ������ ������ ��������

const output = fixSpacesBeforeParen(input);

fs.writeFileSync('t_line_lexer.qapdsl.hpp', output, 'utf8');

// ��� ����� ����� ������ ������� ���������
// console.log(output);
