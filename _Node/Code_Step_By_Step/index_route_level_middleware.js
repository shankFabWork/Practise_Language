const express = require("express")
const app = express()
const path = require("path")


const publicPath = path.join(__dirname,"public")
app.use(express.static(path.join(publicPath)))
app.set("view engine","ejs")

const reqFilter = require('./RouteLevelMiddleware')

// app.use(reqFilter)
const route = express.Router()
route.use(reqFilter)

app.get("",(req,res)=>
{
    res.render("work/index")
})

app.get("/home",reqFilter,(req,res)=>
{
    const user = [
        {name:'shank',age:20,city:'delhi'},
        {name:'rahul',age:31,city:'goa'},
        {name:'gagan',age:23,city:'jaipur'},
    ]
    // res.sendFile(publicPath+"/home.html")
    context=
    {
        'user':user
    }
    console.log(req.query)
    res.render("work/home",context)
})

app.get("/about",(req,res)=>
{
    res.render("work/about")
})

route.get("/user",(req,res)=>
{
    res.render("work/user")
})  

// app.get("*",(req,res)=>
// {
//     res.sendFile(publicPath+"/error404.html")
// })

app.use('/',route)

port_no = 8080
app.listen(port_no,()=>
{
    console.log("app listening at port - ",port_no)
})