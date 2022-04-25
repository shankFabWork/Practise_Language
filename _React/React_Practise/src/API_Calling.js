import React,{useEffect,useState} from 'react'
function App() {

  useEffect(()=>{
    fetch("http://127.0.0.1:8000/passenger/").then((result)=>{
      result.json().then((resp)=>{
        console.warn(resp)
      })
    })
  },[])

  
  return (
    <div>

    </div>
  );
}
export default App;