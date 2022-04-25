// base class pointer 
// derived class object

#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class Base
{

    public:
        void fun1()
        {
            cout<<"fun1 of base";
        }
};

class Derived:public Base
{
    public:
        void fun2()
        {
            cout<<"fun2 of derived";
        }


};

int main()
{
    Base *b1;
    b1=new Derived();
    b1->fun1();

    // error: invalid conversion from 'Base*' to 'Derived*'
    // Derived *d1;
    // d1=new Base();
    // b1->fun1();

    //as i can cuboid a rectangle
    //as i can rectangle a cuboid
    //rectangle  ->base
    //cuboid     ->derived

    // b1->fun2();


    return 0;
}

