#include <iostream>

using namespace std;

class Rectangle
{
    //access specifier
    private:
        int length;
        int breadth;

    public:

        void setLength(int l)
        {
            if(l>0)
                length=l;
            else
                length=0;
        }

        void setBreadth(int b)
        {
            if(b>0)
                breadth=b;
            else
                breadth=0;
        }

        int getLength()
        {
            return length;
        }

        int getBreadth()
        {
            return breadth;
        }


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
    Rectangle r;

    //i can not write this
    //as i hide my data
    //using access specifiers like
    //public: and private:

    // we can not do this    
    // r.length=10;
    // r.breadth=10;

    // will return garbage value
    // cout<<r.area();

    r.setLength(-10);
    r.setBreadth(10);
    cout<<r.getLength()<<"\n";
    cout<<r.area()<<"\n";

    //property functions
    //accessors --> getLength(int l)
    //mutators --> setLength()

    return 0;
}