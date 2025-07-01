var fs=require("fs");
var s=""+fs.readFileSync("test.json");
JSON.parse(s);