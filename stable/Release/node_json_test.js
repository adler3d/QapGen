const fs = require("fs");

// Читаем файл синхронно
const fileBuffer = fs.readFileSync("test.json");
const fileSizeBytes = fileBuffer.length;
const fileSizeMB = fileSizeBytes / (1024 * 1024);

// Высокоточное измерение времени начала
const start = process.hrtime.bigint();

// Парсим JSON
JSON.parse(fileBuffer.toString());

// Высокоточное измерение времени конца
const end = process.hrtime.bigint();

// Вычисляем время в миллисекундах
const durationMs = Number(end - start) / 1e6;

// Вычисляем скорость в мегабайтах в секунду
const speedMBps = fileSizeMB / (durationMs / 1000);

console.log(`time: ${durationMs.toFixed(3)} ms`);
console.log(`speed: ${speedMBps.toFixed(3)} MB/s`);
