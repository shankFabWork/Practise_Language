#include <iostream>

using namespace std;

int sum(int a,int b=10)
{
    return a+b;
}

int main()
{   
    int c=sum(2,2);
    cout<<c<<"\n";
    int d=sum(2);
    cout<<d<<"\n";

    return 0;
}