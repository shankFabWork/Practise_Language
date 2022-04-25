#include <iostream>

using namespace std;


//function overloading 
//redefining the function of parent of class 
//instead of a child class

//function overloading
//same function name but different parameter name passed 

//base class pointer 
//derived class object

class Base
{
    public:
        // void display()
        virtual void display()
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

    Base *b1=new Derived();
    b1->display();

    return 0;
}