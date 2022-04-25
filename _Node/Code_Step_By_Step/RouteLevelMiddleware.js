const reqFilter = (req,res,next)=>
{
    if(!req.query.age)
    {
        res.send("Please provide age")
        next()
    }
    else if(req.query.age > 18)
    {
        console.log("response send successfully")
        next()
    }
    else
    {
        res.send("your age is less than 18 sorry")
    }
}

module.exports = reqFilter