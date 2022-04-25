import React, { createRef, useRef, forwardRef } from "react";
import PassingRef1 from './PassingRef';

class UseRefComp1 extends React.Component {
    constructor() {
        super();
        this.inputRef = createRef();
        this.work = createRef();
    }
    change_ref = () => {
        console.log(this.inputRef.current.value);
        this.inputRef.current.value = 100;
        this.inputRef.current.style.color = "red";
        this.inputRef.current.style.backgroundColor = "green";
    };

    render() {
        return (
            <div>
                <input type="text" ref={this.inputRef} />
                <button onClick={this.change_ref}>Submit</button>
            </div>
        );
    }
}

class UseRefComp2 extends React.Component {
    constructor() {
        super();
        this.inputRef = createRef();
    }

    change_val = () => {
        console.log(this.inputRef.current.value);
        this.inputRef.current.value = 100;
        this.inputRef.current.style.color = "red";
        this.inputRef.current.style.backgroundColor = "blue";
    };

    render() {
        return (
            <div>
                <input type="text" ref={this.inputRef} />
                <button onClick={this.change_val}>submit</button>
            </div>
        );
    }
}
function UseRefComp3() 
{
    let inputRef = useRef(null);
    return (
        <div>
            <PassingRef1 ref={inputRef} />
        </div>
    );
}


export { UseRefComp1, UseRefComp2, UseRefComp3 };
