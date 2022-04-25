let a = 10;
let b = 0;

const getData = new Promise((resolve,reject)=>
{
    setTimeout(()=>
    {
        resolve(20)
    },2000)
})


getData.then((data)=>
{
    b = data
    console.log(a+b)
})


