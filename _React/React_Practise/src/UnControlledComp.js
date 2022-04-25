import React, { useRef } from "react";

function UnControlledComp(props) {
    let inputRef1 = useRef(null);
    function get_data(e) {
        console.log(inputRef1.current.value);
        let data = document.getElementById("work").value;
        console.log(data);
        e.preventDefault();
    }

    return (
        <div>
            <form onSubmit={get_data}>
                <input type="text" id="work" ref={inputRef1} />
                <button type="submit">Submit</button>
            </form>
        </div>
    );
}

export { UnControlledComp };
