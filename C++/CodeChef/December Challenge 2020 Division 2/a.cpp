#include <iostream>

using namespace std;

int a_pow_b(int a,int b)
{
    if(b == 0)
    {
        return 1;
    }
    return a*a_pow_b(a,b-1);
}

int main()
{
    float x = 0;
    if(x == (int)x)
    {
        cout<<"number is not in float";
    }
    else
    {
        cout<<"number is in float";
    }

    return 0;
}