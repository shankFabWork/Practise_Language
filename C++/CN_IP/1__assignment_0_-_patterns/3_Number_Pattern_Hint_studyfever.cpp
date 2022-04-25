#include <iostream>

using namespace std;

int main()
{
    int n = 4;
    // int n = 5;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=i;k++)
        {
            cout<<k+1;
        }
        for(int j=0;j<(n-i-1)*2;j++)
        {
            cout<<" ";
        }
        for(int k=i;k>=0;k--)
        {
            cout<<k+1;
        }
        cout<<endl;
    }

    return 0;
}