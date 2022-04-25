const fs =  require("fs")

const path = require("path")

// const folder_name = path.join(__dirname,'files')

// fs.mkdir(folder_name, (err) => {
//     if (err) {
//         return console.error(err);
//     }
//     console.log('Directory created successfully!');
// });

// const files_path = 

// for(var i=0;i<5;i++)
// {
//     fs.writeFileSync(path.join(__dirname,'files',i.toString()+".txt"),`file no ${i}`)
// }

// fs.readdir(folder_name,(err,files)=>
// {
//     files.forEach((data)=>
//     {
//         console.log(data)
//     })
// })

// const fileName = path.join(__dirname,"")
// fs.writeFileSync("")

const folderName = path.join(__dirname,"crud")
// fs.mkdir(folderName,(err)=>
// {
//     if(err) console.log("folder not made")
//     else console.log("foler made successfully")
// })
// fs.writeFileSync(folderName+"/a.txt","hello are u ok ? ")
// fs.appendFile(path.join(folderName,"a.txt"),"\n yes i am ok !!",(err)=>
// {
//     if(err) console.log("data not appended")
//     else console.log("data appended",path.join(folderName,"a.txt"))
// })
// fs.readFile(folderName+"/a.txt",'utf-8',(err,data)=>
// {
//     console.log(data)
// })

// fs.rename(folderName+"/a.txt",folderName+"/shank.txt",(err)=>
// {
//     console.log("file rename successfully")
// })

// fs.unlinkSync(folderName+"/shank.txt",(err)=>
// {
//     console.log("file deleted successfully")
// })