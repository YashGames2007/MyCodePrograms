const prompt=require("prompt-sync")({sigint:true});

let str = "Please give Rs 1000";
let a = Number.parseInt(str.slice(str.indexOf("Rs ")+3));

console.log(a);