const fs = require("fs");

// ������ ���� ���������
const fileBuffer = fs.readFileSync("test.json");
const fileSizeBytes = fileBuffer.length;
const fileSizeMB = fileSizeBytes / (1024 * 1024);

// ������������ ��������� ������� ������
const start = process.hrtime.bigint();

// ������ JSON
JSON.parse(fileBuffer.toString());

// ������������ ��������� ������� �����
const end = process.hrtime.bigint();

// ��������� ����� � �������������
const durationMs = Number(end - start) / 1e6;

// ��������� �������� � ���������� � �������
const speedMBps = fileSizeMB / (durationMs / 1000);

console.log(`time: ${durationMs.toFixed(3)} ms`);
console.log(`speed: ${speedMBps.toFixed(3)} MB/s`);
