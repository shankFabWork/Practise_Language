#include <iostream>

using namespace std;

class Rectangle
{
    //access specifier
    public:
        int length;
        int breadth;
        
        int area()
        {
            return length*breadth;
        }

        int perimeter()
        {
            return 2*(length+breadth);
        }

};

int main()
{
    Rectangle r,*p1;
    p1=&r;
    r.length=20;
    p1->breadth=30;
    cout<<r.area()<<"\n";
    cout<<r.perimeter()<<"\n";

    Rectangle *p2;
    p2=new Rectangle();
    p2->length=20;
    p2->breadth=30;
    cout<<p2->area()<<"\n";
    cout<<p2->perimeter()<<"\n";


    return 0;
}