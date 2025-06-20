const fs = require('fs');

// ������� ��� �������� ������� ����� ������� ����� ��������������
function fixSpacesBeforeParen(input) {
  // ���������: ����� + ������ + (
  // \b - ������� �����, \w+ - �������������, \s+ - �������, \{ - ������
  return input.replace(/(\b\w+)\s+\{/g, '$1{');
}

// ������ �������������: ������ ���� ��� ������
const fn="t_asmcpplike_lexers.qapdsl_v2.hpp";
const input = fs.readFileSync(fn, 'utf8'); // ��� ������ ������ ��������

const output = fixSpacesBeforeParen(input);

fs.writeFileSync(fn, output, 'utf8');

// ��� ����� ����� ������ ������� ���������
// console.log(output);
