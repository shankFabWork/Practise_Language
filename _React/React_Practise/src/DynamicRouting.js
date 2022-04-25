import React from "react";
import {
    BrowserRouter as Router,
    Switch,
    Link,
    Route,
} from "react-router-dom";
import UserComp from "./UserComp";
function DynamicRouting() {
    let user = [
        { name: "anil", id: 1 },
        { name: "peter", id: 2 },
        { name: "bruce", id: 3 },
        { name: "tony", id: 4 },
    ];
    return (
        <div>
            <Router>
                {/* <Link to="/">Home Link</Link>
                <br />
                <Link to="/about">About Link</Link>
                <Switch>
                    <Route path="/" exact={true}>
                        <Home />
                    </Route>
                    <Route path="/about">
                        <About />
                    </Route>
                    <Route path="*">
                        <Error404 />
                    </Route>
                </Switch> */}
                <Link to="/"> Home Page </Link>
                <br />
                {user.map((elem) => {
                    return (
                        <>
                            <Link key={elem.id} to={"/user/" + elem.id +"/"+ elem.name}>
                                {elem.name} {elem.id}
                            </Link>
                            <br />
                        </>
                    );
                })}
                <Switch>
                <Route path="/user/:id/:name">
                    <UserComp />
                </Route>
                <Route path="/" exact={true}>
                    <Home />
                </Route>
                <Route path="*">
                    <Error404 />
                </Route>
                </Switch>
            </Router>
        </div>
    );
}

function Home() {
    return <div>Home Page</div>;
}

function About() {
    return <div>About Page</div>;
}

function Error404() {
    return (
        <div>
            Error 404 Page <br /> Not Found
        </div>
    );
}

export { DynamicRouting };
