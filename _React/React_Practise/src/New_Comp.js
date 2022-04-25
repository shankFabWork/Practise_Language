import React, { useState } from 'react';


function New_Comp()
{
    return(
        <div>
            <Hoc_red comp={Counter} />
            <Hoc_green comp={Counter} />
        </div>
    )
}

function Hoc_red(props)
{
    return(
        <div>
            <h1 style={{backgroundColor:'red'}}><props.comp /></h1>
        </div>
    )
}

function Hoc_green(props)
{
    return(
        <div>
            <h1 style={{backgroundColor:'green'}}><props.comp /></h1>
        </div>
    )
}

function Counter()
{
    const [data,setData] = useState(0);
    return(
        <div>
            {data}
            <br />
            <button onClick={()=>setData(data+1)}>Submit</button>
        </div>
    )
}


export {New_Comp}