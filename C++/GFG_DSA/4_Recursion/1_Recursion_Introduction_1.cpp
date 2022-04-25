#include <iostream>

using namespace std;

void fun2()
{
    cout<<"function 2"<<endl;
}

void fun1()
{
    cout<<"before function 2"<<endl;
    fun2();
    cout<<"after function 2"<<endl;
}

int main()
{
    cout<<"before function 1"<<endl;
    fun1();
    cout<<"after function 1"<<endl;

    return 0;
}