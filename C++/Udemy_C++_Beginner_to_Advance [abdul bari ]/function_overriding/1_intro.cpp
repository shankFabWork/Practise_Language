#include <iostream>

using namespace std;


//function overloading 
//redefining the function of parent of class 
//instead of a child class

//function overloading
//same function name but different parameter name passed 
class Base
{
    public:
        void display()
        {
            cout<<endl<<" base class property"<<endl;
        }

};

class Derived:public Base
{
    public:
        //comment and see output
        //
        void display()
        {
            cout<<endl<<" derived class property"<<endl;
        }
        //

};

int main()
{

    Base b1;
    b1.display();

    Derived d1,d2;
    d1.display();

    d2.Base::display();
    d2.Derived::display();



    return 0;
}