import { useState,useMemo } from "react";
import React from "react";

function FormData1() {
    return <div></div>;
}

// class FormData2 extends React.Component
class FormData2 extends React.PureComponent {
    constructor() {
        super();
        this.state = {
            counter: 0,
        };
    }
    increase_counter = () => {
        // this.setState({counter:this.state.counter+1})
        this.setState({ counter: 0 });
        console.log("it is rendering");
    };
    render() {
        // console.log("it is rendering");
        return (
            <div>
                {this.state.counter}
                <br />
                <button onClick={this.increase_counter}>Submit</button>
            </div>
        );
    }
}

function FormData3() {
    const [data, setData] = useState(0);

    useMemo(()=>
    {
        console.log("it is rendering");
                // setData(data+1)
                setData(0)
        return data*5;
    },[data])
    
    function show_counter()
    {   
        // setData(data+1)
        setData(0)
    }

    return (
        <div>
            {/* {console.log("it is rendering")} */}
            {data}
            <br />
            <button onClick={show_counter}>
                Submit
            </button>
        </div>
    );
}

export { FormData1, FormData2, FormData3 };
