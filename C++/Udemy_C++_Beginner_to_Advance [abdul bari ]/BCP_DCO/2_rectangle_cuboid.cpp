#include <iostream>

using namespace std;

class Rectangle
{

    public:
        void fun1()
        {
            cout<<endl<<"fun1 of Rectangle"<<endl;
        }
};

class Cuboid:public Rectangle
{
    public:
        void fun2()
        {
            cout<<endl<<"fun2 of Cuboid"<<endl;
        }


};

int main()
{
    Rectangle *b1,*b2;

    Cuboid c;
    b1=&c;
    b1->fun1();

    b2=new Cuboid();
    b2->fun1();

    // invalid conversion from 'Rectangle*' to 'Cuboid*'
    // Cuboid *r1;
    // r1=new Rectangle();
    // r1->fun1();

    



    return 0;
}

