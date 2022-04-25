#include <iostream>

using namespace std;

float division(int a,int b)
{
    if(b == 0)
    {
        throw 1;
    }
    float c=(float)a/b;
    return c;
}

int main()
{

    float a,b;
    cin>>a>>b;

    try
    {
        cout<<division(a,b);
    }

    catch(int e)
    {
        cout<<"error "<<e<<" do not divide any number by zero";
    }

    return 0;
}