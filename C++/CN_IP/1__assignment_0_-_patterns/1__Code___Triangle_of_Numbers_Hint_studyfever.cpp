#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    for(int i=0;i<n;i++)
    {
        for(int j=n-i-1;j>=0;j--)
        {
            cout<<" ";
        }
        int counter1 = i+1;
        for(int j=0;j<=i;j++)
        {
            cout<<counter1;
            counter1++;
        }
        int counter2 = 2*i;
        for(int j=0;j<i+1;j++)
        {
            if(j != 0)
            {
                cout<<(counter2+1);
            }
            counter2--;
        }

        cout<<endl;
    }

    return 0;
}