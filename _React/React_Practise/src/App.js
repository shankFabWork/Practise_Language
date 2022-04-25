import React, { useState } from "react";

import Table from "react-bootstrap/Table";
import "bootstrap/dist/css/bootstrap.min.css";
import ShowTable1 from "./Show_Table";
import { UseRefComp1, UseRefComp2, UseRefComp3 } from "./UseRefComp";
import { UnControlledComp } from "./UnControlledComp";
import { FormData1, FormData2, FormData3 } from "./FormData.js";
import { New_Comp } from "./New_Comp";
import {Router_Comp} from './Router_Comp'
import {DynamicRouting} from './DynamicRouting'
import API_Calling from "./API_Calling";
function App() {
    return (
        <div>
            {/* <button onClick={() => setDisp(!disp)}>
                {disp ? "Light" : "Dark"}
            </button> */}

            {/* <ShowTable1 disp={disp} users={users} /> */}
            {/* <FormData1 give_me_data={give_me_data} /> */}
            {/* <FormData2 /> */}
            {/* <FormData3 /> */}
            {/* <UseRefComp1 /> */}
            {/* <UseRefComp2 /> */}
            {/* <UseRefComp3 /> */}
            {/* <UnControlledComp /> */}
            {/* <New_Comp /> */}
            {/* <Router_Comp /> */}
            {/* <DynamicRouting /> */}
            <API_Calling />

        </div>
    );
}

export default App;
