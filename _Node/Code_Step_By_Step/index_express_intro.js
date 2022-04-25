const express = require("express")
const app = express()

app.get('',(req,res)=>
{
    res.send(`
    <h1> hello this is home page </h1> 
    <br />
    <input type="text" />
    <br />
    <a href="/get_json">Go to about page</a>
    <br />
    <button>Submit</button>
    <br />
    ${req.query.name}
    <br />
    ${req.query.age}
    `)
    console.log("data send by user => ",req.query.age)
})

app.get('/get_json',(req,res)=>
{
    res.send([
        {name:'shank',age:20},
        {name:'gagan',age:25},
    ])
})

app.get('/about',(req,res)=>
{
    res.send("hello this is about page ")
})

app.get('/help',(req,res)=>
{
    res.send("hello this is help page ")
})


port_no = 8080
app.listen(port_no,()=>
{
    console.log("app listening at port - ",port_no)
})