#include <iostream>

using namespace std;

class Rectangle
{
    private:
        int length,breadth;
    public:

    // constructors
        Rectangle();

        Rectangle(int,int);

        Rectangle(Rectangle &r);

    //mutators
        void setLength(int);

        void setBreadth(int);

    //accessors
        int getLength();

        int getBreadth();

    // facilitators
        int area();

        int perimeter();

    // enquires
        bool isSquare();

    //destructor
        ~Rectangle();
};

    // constructors
        Rectangle::Rectangle()
        {
            length=1;
            breadth=1;
        }

        Rectangle::Rectangle(int l=1,int b=1)
        {
            setLength(l);
            setBreadth(b);
        }

        Rectangle::Rectangle(Rectangle &r)
        {
            length=r.length;
            breadth=r.breadth;
        }

    //mutators
        void Rectangle::setLength(int l)
        {
            length=l;
        }

        void Rectangle::setBreadth(int b)
        {
            breadth=b;
        }

    //accessors
        int Rectangle::getLength()
        {
            return length;
        }

        int Rectangle::getBreadth()
        {
            return breadth;
        }

    // facilitators
        int Rectangle::area()
        {
            return length*breadth;
        }

        int Rectangle::perimeter()
        {
            return 2*(length+breadth);
        }

    // enquires
        bool Rectangle::isSquare()
        {
            return length ==  breadth;
        }

    //destructor
        Rectangle::~Rectangle()
        {
            cout<<"Rectangle destroyed";
        }


int main()
{
    Rectangle r1(10,20);
    cout<<" length is "<<r1.getLength()<<" breadth is "<<r1.getBreadth()<<"\n";
    cout<<r1.area()<<"\n";

    Rectangle r2(r1);
    cout<<" length is "<<r2.getLength()<<" breadth is "<<r2.getBreadth()<<"\n";
    cout<<r2.area()<<"\n";


    Rectangle r3(20,20);
    cout<<" length is "<<r3.getLength()<<" breadth is "<<r3.getBreadth()<<"\n";
    cout<<r3.area()<<"\n";

    if(r3.isSquare() )
    {
        cout<<" it is square "<<endl;
    } 
    else
    {
        cout<<" it is not square "<<endl;
    }

cout<<endl;
cout<<"destructor wil be called three times as the object is called three times";
cout<<endl;
cout<<endl;

    return 0;
}