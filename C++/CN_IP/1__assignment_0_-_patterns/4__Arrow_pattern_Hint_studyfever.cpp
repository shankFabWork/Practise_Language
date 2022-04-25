#include <iostream>

using namespace std;

int main()
{
    int n = 7;
    
    // int n = 4;
    // int n = 5;

    int n1 = (n+1)/2;
    // n1 = 4
    int n2 = n/2;
    // n2 = 3
    for(int i=0;i<n;i++)
    {
        if(i <= n1-1)
        {
            for(int k=0;k<=i;k++)
            {
                if(k != 0)
                {
                    cout<<" ";
                }
            }
            for(int k=0;k<=i;k++)
            {
                cout<<"* ";
            }
        }
        else
        {
            for(int k=n-i-1;k>=1;k--)
            {
                cout<<" ";
            }
            for(int k=n-i;k>=1;k--)
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }

    return 0;
}