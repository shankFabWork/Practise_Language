import React from "react";
import Table from "react-bootstrap/Table";
import "bootstrap/dist/css/bootstrap.min.css";
import show_work from "./Show_Table.module.css";

function ShowTable1(props) {
    return (
        <>
            {console.log(props.disp)}
            <Table
                className={`striped ${
                    props.disp
                        ? "table-responsive-sm table-dark table-striped"
                        : "none"
                }`}
            >
                {/* <Table responsive="sm"> */}
                <thead>
                    <tr>
                        <th>S.No</th>
                        <th>Name</th>
                        <th>email</th>
                        <th>address</th>
                    </tr>
                </thead>
                <tbody>
                    {props.users.map((elem, id) => {
                        return (
                            <tr key={id}>
                                <td>{id + 1}</td>
                                <td>{elem.name}</td>
                                <td>{elem.email}</td>
                                <td>
                                    <Table
                                        className={`striped ${
                                            props.disp
                                                ? "table-responsive-sm table-dark table-striped"
                                                : "none"
                                        }`}
                                    >
                                        <tbody>
                                            {elem.address.map((data) => {
                                                return (
                                                    <tr key={data.hm}>
                                                        <td>{data.hm}</td>
                                                        <td>{data.city}</td>
                                                        <td>{data.country}</td>
                                                    </tr>
                                                );
                                            })}
                                        </tbody>
                                    </Table>
                                </td>
                            </tr>
                        );
                    })}
                </tbody>
            </Table>
        </>
    );
}

export default ShowTable1;
