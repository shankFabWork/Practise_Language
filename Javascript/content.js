function Circle(radius)
{

    this.radius=radius;
    this.draw=()=>
    {
        console.log(radius);
    }
    console.log(this)
}

another = new Circle(10)