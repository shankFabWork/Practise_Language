import React from "react";

import { BrowserRouter as Router, Link, Route, Switch } from "react-router-dom";

function Router_Comp() {
    return (
        <div>
            <Router>
                <Link to="/" exact={true}>
                    Home Page
                </Link>
                <br />
                <Link to="/about">About Page</Link>
                <br />
                <Switch>
                    <Route path="/about">
                        <About />
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

function Error404() {
    return (
        <div>
            Page not found error
            <br />
            Error 404
        </div>
    );
}

function Home() {
    return (
        <div>
            <h1>This is Home Page</h1>
        </div>
    );
}

function About() {
    return (
        <div>
            <h1>This is About Page</h1>
        </div>
    );
}

export { Router_Comp };
