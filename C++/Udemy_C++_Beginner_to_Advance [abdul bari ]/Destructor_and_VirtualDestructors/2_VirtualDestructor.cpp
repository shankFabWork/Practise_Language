#include <iostream>

using namespace std;


class Base
{
    public:
        Base()
        {
            cout<<endl<<"constructor of Base "<<endl;
        }

        virtual ~Base()
        {
            cout<<endl<<"Destructor of Base "<<endl;
        }

};

class Derived:public Base
{
    public:
        Derived()
        {
            cout<<endl<<"constructor of Derived "<<endl;
        }

        ~Derived()
        {
            cout<<endl<<"Destructor of Derived "<<endl;
        }

};


int main()
{
    // Derived d;
    Base *b=new Derived();
    delete b;

    // only Destructor of Base is called 
    // not Destructor of Derived


    // int *arr=new int[10];
    // delete []arr;


    //contructors are called from top to bottom
    //destructors are called from bottom to top

    return 0;
}