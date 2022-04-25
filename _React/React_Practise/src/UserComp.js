import React from "react";
import { withRouter } from "react-router-dom";

function UserComp(props) {
    console.log(props.match.params.id);
    return (
        <div key={props.match.params.id}>
            This is user number {props.match.params.id}
        </div>
    );
}

export default withRouter(UserComp);
