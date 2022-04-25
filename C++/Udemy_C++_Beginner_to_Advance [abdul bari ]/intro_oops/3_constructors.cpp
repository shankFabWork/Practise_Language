//constructors
//default constructors
//non-parameterized constructors
//parameterized constructors
//copy constructors

#include <iostream>

using namespace std;

class Rectangle
{

    private:
        int length;
        int breadth;
    
    public:

        Rectangle()
        {
            length=0;
            breadth=0;
        }

        Rectangle(int l=0,int b=0)
        {
            setLength(length=l);
            setBreadth(breadth=b);
        }

        Rectangle(Rectangle &r)
        {
            length=r.length;
            breadth=r.breadth;
        }

        void setLength(int l)
        {
            length=l;
        }
        void setBreadth(int b)
        {
            breadth=b;
        }
        int getLength()
        {
            return length;
        }
        int getBreadth()
        {
            return breadth;
        }

        int perimeter()
        {
            return 2*(length+breadth);
        }
};

int main()
{
    Rectangle r1(10);
    Rectangle r2(r1);
    cout<<r2.getLength()<<"\n";
    cout<<r2.perimeter()<<"\n";

    return 0;
}