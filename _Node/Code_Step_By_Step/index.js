const {MongoClient} = require('mongodb')
const url = "mongodb://localhost:27017"
const client = new MongoClient(url)
const database = "e_comm"

async function getData()
{
    let result = await client.connect()
    let db = result.db(database)
    let collection = db.collection("items")
    let res = await collection.find({}).toArray()
    console.log(res)
}   
getData()                             

// var myobj = { name: "HeadPhones", address: "Customer" };
// dbo.collection("customers").insertOne({ name: "HeadPhones", address: "Customer" })
// db("e-commm").collection("items").insertOne({ name: "HeadPhones", address: "Customer" })