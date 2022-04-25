#include <iostream>

using namespace std;

int main()
{

    float a,b;
    cin>>a>>b;

    try
    {
        if(b == 0)
        {
            throw 101;
        }
        cout<<a/b;
    }

    catch(int e)
    {
        cout<<"error "<<e<<" do not divide any number by zero";
    }

    return 0;
}