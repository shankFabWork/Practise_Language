#include <iostream>

using namespace std;

int dest_no=0;

class Rectangle
{
    private:
        int length,breadth;
    public:

    // constructors
        Rectangle()
        {
            length=1;
            breadth=1;
        }

        Rectangle(int l=1,int b=1)
        {
            setLength(l);
            setBreadth(b);
        }

        Rectangle(Rectangle &r)
        {
            length=r.length;
            breadth=r.breadth;
        }
    //mutators
        void setLength(int l)
        {
            length=l;
        }

        void setBreadth(int b)
        {
            breadth=b;
        }

    //accessors
        int getLength()
        {
            return length;
        }

        int getBreadth()
        {
            return breadth;
        }

    // facilitators
        int area()
        {
            return length*breadth;
        }

        int perimeter()
        {
            return 2*(length+breadth);
        }

    // enquires
        bool isSquare()
        {
            return length ==  breadth;
        }

    //destructor
        ~Rectangle()
        {
            dest_no=dest_no+1;
            cout<<dest_no<<" Rectangle destroyed "<<"\n";
        }
};




class Cuboid:public Rectangle
{
    private:
        int height;
    public:
        Cuboid(int h=1,int l=1,int b=1):Rectangle(l,b)
        {
            height=h;
        }

        int getHeight()
        {
            return height;
        }
        void setHeight(int h)
        {
            height=h;
        }
        int volume()
        {
            return getLength()*getBreadth()*height;
        }
};


int main()
{
    Rectangle r1(10,20);
    cout<<endl;
    cout<<"length is "<<r1.getLength()<<" breadth is "<<r1.getBreadth()<<"\n";
    cout<<"area is "<<r1.area()<<endl;

    cout<<endl;

    Cuboid c1(3);
    cout<<"length is "<<c1.getLength()<<" breadth is "<<c1.getBreadth()<<"\n";
    cout<<"volume is "<<c1.volume()<<endl;
    cout<<"area is "<<c1.area()<<endl;

    cout<<endl;


    return 0;
}