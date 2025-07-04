var fs=require("fs");
const os = require('os');
const uptimeSeconds = os.uptime();
const ms0 = uptimeSeconds*1000;
//console.log("["+formattedDate+"] : "+ms);
var s=""+fs.readFileSync("test.json");
JSON.parse(s);
const ms1 = os.uptime()*1000;
console.log(ms1-ms0);