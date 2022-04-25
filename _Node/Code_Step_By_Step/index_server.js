// console.log("hello world all")
// const obj = require('./second')
// console.log(obj)

// const fs = require("fs")
// fs.writeFileSync("shank.txt","hello")

const http = require("http")
const data = require('./data')
const colors = require("colors")

const dataControl = (req,res) =>
{
    // const txt = "Hello Beautiful People"
    res.writeHead(200,{'Content-Type':'application/json'})
    // res.write(JSON.stringify({'name':'shank','age':20}))
    res.write(JSON.stringify(data))
    // res.write(txt.green)
    res.end()
}

http.createServer(dataControl).listen(8080)
console.log(data)

console.log("hello world".blue)