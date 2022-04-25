// console.log(process.argv[2])

const p = process.argv
const fs = require('fs')

// console.log(p[3])
// fs.writeFileSync(p[2],p[3])
if(p[2] == "add")
{
    fs.writeFileSync(p[3],p[4])
}
else if(p[2] == "del")
{
    fs.unlinkSync(p[3])
}
else 
{
    console.log("Invalid Input")
}