//https://adler3d.github.io/test2013/
return POST.data.split("\nADDVAR(").map((e,i)=>{
  if(i==0)return e;
  var t=e.split(",");
  if((t[0]|0)+""!=t[0])
    throw new Error("fail:"+JSON.stringify(t[0])+":nope");
  t=t.slice(1);
  return t.join(",");
}).join("\nADDVAR(");