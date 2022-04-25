#include <iostream>

using namespace std;

int main()
{
    int d1,v1,d2,v2,p,i=1;
    cin>>d1>>v1>>d2>>v2>>p;
    int total_v1 = 0;
    int total_v2 = 0;
    while( (total_v1+total_v2) < p)
    {
        if(i >= d1)
        {
            total_v1 += v1;
        }
        if(i >= d2)
        {
            total_v2 += v2;
        }
        i++;
    }
    cout<<i-1;
    return 0;
}