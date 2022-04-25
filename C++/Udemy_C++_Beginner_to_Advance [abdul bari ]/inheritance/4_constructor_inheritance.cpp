#include <iostream>

using namespace std;

class Base
{
    private:
    public:
        Base()
        {
            cout<<endl<<" Default Constructor of Base"<<endl;
        }

        Base(int x)
        {
            cout<<endl<<"params of base class-->"<<x<<endl;
        }


};

class Derived:public Base
{
    private:
    public:
        Derived()
        {
            cout<<endl<<" Default Constructor of Derived"<<endl;
        }

        Derived(int x)
        {
            cout<<endl<<"params of Derived class-->"<<x<<endl;
        }

        Derived(int x,int a):Base(x)
        {
            cout<<endl<<"params of Derived class-->"<<a<<endl;
        }


};


int main()
{
    Derived d1(10,20);


    return 0;
}