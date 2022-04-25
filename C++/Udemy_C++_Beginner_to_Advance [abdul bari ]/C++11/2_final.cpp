#include <iostream>

using namespace std;

//final keyword restricts inheritance
// class Fun1 final
class Fun1
{
    //final keyword restricts function overriding
    // virtual void disp() final
    virtual void disp()
    {
        cout<<"fun1 function";
    }

};


class Fun2:public Fun1
{
    void disp()
    {
        cout<<"fun2 function";
    }
    
};

int main()
{



    return 0;
}