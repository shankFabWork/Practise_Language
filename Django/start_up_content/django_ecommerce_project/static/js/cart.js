var all_btn = document.getElementsByClassName("fun");   
// console.log(all_btn[0].getAttribute('data_name'))
// console.log(all_btn[1].dataset.product)
// console.log(all_btn[1].dataset)

// for(var i = 0; i < all_btn.length; i++) 
// {
//     // console.log(i)
//     all_btn[i].addEventListener('click',()=>
//     {
//         console.log(i)
//         // console.log(all_btn[i].dataset)
//     })
// }    

console.log(user)

for(let i = 0; i < all_btn.length; i++) 
{
    all_btn[i].addEventListener('click',()=>
    {
        // console.log("shank"+i)
        console.log(all_btn[i].dataset.product+" "+all_btn[i].dataset.action)
    })
}

