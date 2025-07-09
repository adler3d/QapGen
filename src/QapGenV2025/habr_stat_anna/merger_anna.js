var fs=require('fs');
var c=fs.readFileSync("merged.json")+"";var f=JSON.parse(c);

























var find=(h,s)=>h.filter(e=>e.url==s)[0];
var nfn=s=>s.split("C:\\Users\\Adler\\Desktop\\QapGen\\QapGen\\src\\QapGenV2025\\habr_stat_anna\\")[1];
var u=f[3].content.programming[0].url;
f.map((h,i)=>{return {s:find(h.content.programming,u),file:nfn(f[i].file)};}).filter(e=>(e.s));
find(