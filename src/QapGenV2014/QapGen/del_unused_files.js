var fs=require("fs");
var s=fs.readFileSync("full_dependencies.txt")+"";
var arr=s.split("\n");
var files=fs.readdirSync(".");
var to_del=files.filter(e=>!arr.includes(e)&&["h",'hpp','cpp','inl'].includes(e.split(".").pop()));
console.log(to_del);
to_del.map(e=>fs.unlinkSync(e));