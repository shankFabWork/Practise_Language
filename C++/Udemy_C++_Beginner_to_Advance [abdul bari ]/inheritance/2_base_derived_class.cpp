#include <iostream>

using namespace std;

class Base
{
    private:
        int val;
    public:
        void display()
        {
            cout<<" base class property";
        }
        void setVal(int v)
        {
            val=v;
        }
        void getVal()
        {
            cout<<" value is "<<val;
        }
};

class Derived:public Base
{
    public:

    private:

};

int main()
{
    Derived d1;
        d1.display();
    cout<<endl;
        d1.setVal(20);
    cout<<endl;
        d1.getVal();

    return 0;
}