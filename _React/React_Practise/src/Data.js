import React,{useEffect, useState} from 'react';

function Data1(props)
{
    const [name,setName] = useState("shank")
    const [new_name,setNew_Name] = useState("")
    const [show_data,setShow_data] = useState(false)
    function changeName()
    {
        setName("gagan")
    }
    function change_new_name(e)
    {
        // console.log(e.target.value)
        setNew_Name(e.target.value)
    }

    function show_data_func()
    {
        setShow_data(!show_data)
    }

    return (
        <div>
            {/* {props.name}
            {name}
            <button onClick={changeName}>Submit</button> */}
            {
                show_data?
                <h1>Your Data is {new_name}</h1>
                :
                <h1> Your Data is hidden </h1>
            }
            {/* {new_name} */}
            <br />
            <input type="text" onChange={change_new_name} />
            <button onClick={show_data_func}>
                {show_data?<div>Hide Data</div>:<div>Show Data</div>}
            </button>
            
        </div>
    )
}

class Data2 extends React.Component
{
    constructor(props)
    {
        super(props);
        this.state={
            name:"shank",
            new_name:"",
            counter:0
        }
        {console.log("1")}
        {console.log(this.props.name)}
    }
    changeName=()=>
    {
        this.setState({name:"gagan"})
        this.setState({counter:this.state.counter+1})

        {console.log("3")}
    }
    show_data=(e)=>
    {
        // console.log(e.target.value)
        this.setState({new_name:e.target.value})
    }

    componentDidMount()
    {
        console.log("hello")
    }

    shouldComponentUpdate()
    {
        console.log("counter",this.state.counter)
        // return false;   
        return true;   
    }

    getSnapshotBeforeUpdate(prevProps, prevState) {
        if (this.state.counter < 5) {
            return "hello";
        }
        return "buffalo";
      }
    

    componentDidUpdate(prevProps,prevState,snapshot)
    {
        console.log("h")
        console.log("new counter"+this.state.counter)
        // if(this.state.counter < 10)
        // {
        //     this.setState({counter:this.state.counter+1})
        // }
        console.log(prevProps,prevState,snapshot)
    }

    componentWillUnmount()
    {
        console.log("component unmounted")
    }

    render()
    {
        return(
            <div>
                {/* {console.log("2")} */}
                {this.state.counter}
                {/* {this.props.name} */}
                {/* {this.state.name} */}
                {this.state.new_name}
                <br />
                <input type="text" onChange={(e)=>this.show_data(e)} />
                <br />
                <button onClick={()=>this.changeName()}>Submit</button>
            </div>                
        )
    }
}

class Form_Comp extends React.Component
{
    constructor()
    {
        super()
        this.state={name:"",options:"none",checkbox:false}
    }

    change_name=(e)=>
    {
        this.setState({name:e.target.value})
    }
    change_options=(e)=>
    {
        this.setState({options:e.target.value})
    }

    change_checkbox=(e)=>
    {
        this.setState({checkbox:e.target.checked})
    }

    form_submit_func=(e)=>
    {
        console.log(this.state.name+" "+this.state.options+" "+this.state.checkbox)
        e.preventDefault();
    }

    clear_form=(e)=>
    {
        console.log("clear")
        this.setState({name:"",options:"none",checkbox:false})
    }
    render()
    {
        return(
            <React.Fragment>
                <form onSubmit={(e)=>this.form_submit_func(e)}>
                    
                    <input type="text" onChange={(e)=>this.change_name(e)} value={this.state.name} />
                    
                    <select onChange={(e)=>this.change_options(e)}>
                        <option value="none">none</option>
                        <option value="work">work</option>
                        <option value="data">data</option>
                    </select>

                    <input type="checkbox" checked={this.state.checkbox} onChange={(e)=>this.change_checkbox(e)} />
                    
                    <button type="submit">Submit</button>
                    <button type="button" onClick={()=>this.clear_form()}>Clear</button>
                
                </form>
            </React.Fragment>
        )
    }
}

function Formvalidation()
{
    const [username,setUsername] = useState("")
    const [password,setPassword] = useState("")

    function change_username(e)
    {
        setUsername(e.target.value)
    }

    function change_password(e)
    {
        setPassword(e.target.value)
    }

    function form_submitted(e)
    {
        var str = ""
        var isFlag = 1;
        if(parseInt(username.length) === 0)
        {
            str += "username can not be empty \n";
            isFlag = 0;
        }
        if(username.length <= 5)
        {
            str += "username should be grater than 5 \n";
            isFlag = 0;
        }

        if(parseInt(password.length) === 0)
        {
            str += "password can not be empty \n";
            isFlag = 0;
        }

        console.log(parseInt(username))
        if(!isNaN(parseInt(username)))
        {
            str += "username must be string \n";
            isFlag = 0;
        }

        if(isFlag == true)
        {
            console.log(username+" "+password)
        }
        else
        {
            console.log(str)
        }
        e.preventDefault()
    }

    return(
        <div>
            <form onSubmit={form_submitted}>
                {username}
                <br />
                {password}
                <br />
                <input type="text" placeholder="User Name" value={username} onChange={change_username} />
                <br />
                <input type="text" placeholder="Password" value={password} onChange={change_password} />
                <br />
                <button type="submit">Submit</button>
            </form>
            
        </div>
    )
}

function Data_Work(props)
{
    return (
        <div>
            <button onClick={props.say_hello}>Say Hello</button>
        </div>
    )
}


function Hooks_component()
{
    const [counter,setCounter] = useState(0)
    useEffect(()=>
    {
        console.log("useEffect runs")
    })
    return(
        <div>
            Hello
            <br />
            {counter}
            <br />
            <button onClick={()=>setCounter(counter+1)}>
                Submit
            </button>
        </div>
    )
}


export 
{
    Data1,
    Data2,
    Form_Comp,
    Formvalidation,
    Data_Work,
    Hooks_component,
}
