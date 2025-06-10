const fs = require('fs');

let seenFiles = new Set(); // Множество для отслеживания просмотренных файлов

const cppFile = 'CommonUnit.cpp'; // Укажите путь к вашему C++ файлу
const outputFile = 'full_dependencies.txt';

function getDependencies(p,file) {
 try {
 // Читаем содержимое файла
   file=p+file;
   let c = "\n"+fs.readFileSync(file);
   c=c.split("\r").join("");
   if(c.includes("MetaTypeGraber"))console.log("---found");
   // Регулярное выражение для поиска #include директив
   //const includePattern = /#\s*include\s*"(^"+)"/g;
   var del=(c,a,b)=>{
     let c2=c.split(a);
     return c2[0]+c2.slice(1).map(e=>e.split(b).slice(1).join(b)).join("");
   }
   c=del(c,"/*","*/");
   c=del(c,"#if(0)","#endif");
   if(c.includes("MetaTypeGraber"))console.log("---+++found");
   //console.log(c.includes("\n#include \"QapPublicUberXImpl.cpp"));
   let arr=c.split("\n#include \"");
   //console.log(arr.map(e=>e.includes("MetaTypeGraber.inl")));
   arr=arr.map(e=>e.split("\n")[0]);
   //console.log(arr);
   arr=arr.slice(1);
   if(arr.filter(e=>e.includes("MetaTypeGraber.inl")).length==1)console.log("---found2");
   arr=arr.map(e=>e.split('"')[0]).filter(e=>!e.includes("../Macro"));
   let includes = arr;
    
   var f=include=>{
     include=include.split("C:\\").join("/c/");
     include=include.split("\\").join("/");
     return include;
   };
   includes=includes.map(f);
   // Удаляем дубликаты и сортируем
   includes =[...new Set(includes)].filter(e=>![...seenFiles].includes(e));//.sort();
   seenFiles.add(file);
   //includes.map(e=>seenFiles.add(p+e));
   /*if([...seenFiles].filter(e=>e.includes("QapType")).length){
     console.log({file,seenFiles,includes});
   }*/
   //console.log("seenFiles=["+Array.from(seenFiles).join('\n')+"]");
   console.log("[...]{"+file);
   includes.map(e=>console.log(p+e));
   console.log("[...]}"+file);

   includes.forEach(include => {
     let t=file.split("/");t.pop();
     let p2=t.join("/")+(t.length?"/":"");
     console.log(p+p2+include);
     console.log({p,p2,include});
     getDependencies(p+p2,include);
   });
   
 } catch (error) {
   console.error('Ошибка:', error);
 }
}

// Запускаем получение зависимостей
getDependencies("",cppFile);
fs.writeFileSync(outputFile,Array.from(seenFiles).join('\n'));