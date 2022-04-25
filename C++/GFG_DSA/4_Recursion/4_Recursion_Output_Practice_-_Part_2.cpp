#include <iostream>

using namespace std;


int fun1(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return 1+fun1(n/2);
}

void fun2(int n)
{
    if(n == 0)
    {
        return;
    }   
    fun2(n/2);
    cout<<(n%2);
    return;
}

int main()
{
    cout<<fun1(7);  //log(n)
    cout<<endl;
    fun2(7);  //log(n)
    cout<<endl;
    fun2(13);  //log(n)


    return 0;
}
