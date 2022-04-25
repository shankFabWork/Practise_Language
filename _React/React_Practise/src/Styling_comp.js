import React from 'react';
import './Styled_Comp.css'
import sty1 from './styled.module.css'
import { Button } from 'react-bootstrap';
import Carousel from 'react-bootstrap/Carousel'
import 'bootstrap/dist/css/bootstrap.css';

function Styled_Comp()
{
    return(
        <div>
           <div className='primary'>
                Hello
            </div> 
            <div style={{color:"red",backgroundColor:"green"}}>
                Data
            </div>
            <div className={sty1.primary}>Work</div>
            <Button onClick={()=>alert("helo")}>Work</Button>


            <Carousel fade>
                <Carousel.Item>
                    <img
                    className="d-block w-100"
                    src="https://cdn.pixabay.com/photo/2015/03/26/09/52/chain-link-690503_960_720.jpg"
                    alt="First slide"
                    />
                    <Carousel.Caption>
                    <h5>First slide label</h5>
                    <p>Nulla vitae elit libero, a pharetra augue mollis interdum.</p>
                    </Carousel.Caption>
                </Carousel.Item>
                <Carousel.Item>
                    <img
                    className="d-block w-100"
                    src="https://cdn.pixabay.com/photo/2015/03/26/09/41/chain-690088_960_720.jpg"
                    alt="Second slide"
                    />
                    <Carousel.Caption>
                    <h5>Second slide label</h5>
                    <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                    </Carousel.Caption>
                </Carousel.Item>
                <Carousel.Item>
                    <img
                    className="d-block w-100"
                    src="https://cdn.searchenginejournal.com/wp-content/uploads/2019/12/how-to-execute-a-link-conversion-strategy-5df792498b991-760x400.png"
                    alt="Third slide"
                    />
                    <Carousel.Caption>
                    <h5>Third slide label</h5>
                    <p>Praesent commodo cursus magna, vel scelerisque nisl consectetur.</p>
                    </Carousel.Caption>
                </Carousel.Item>
                </Carousel>

        


            <Button variant="flat" size="xxl">
                flat button
            </Button>
        </div>
    )
}

export default Styled_Comp