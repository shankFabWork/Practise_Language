import React, { forwardRef } from "react";

const PassingRef1=forwardRef((props,inputRef)=>
{
    const change_ref = () =>
    {
        console.log(this.work.current.value);
        this.work.current.value = 100;
        this.work.current.style.color = "red";
        this.work.current.style.backgroundColor = "green";
    };

    return(
        <div>
            <input ref={inputRef} />
            <button onChange={change_ref}>Submit</button>
        </div>
    )
})



export default PassingRef1;
