#include <iostream>

using namespace std;

int main()
{

    int arr[100][100];
    int n=5;
    int m=5;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-i;j++)
            {
                cout<<" ";                
            }

        for(int k=0;k<i;k++)
            {
                cout<<"*";                
            }
        cout<<'|'<<endl;
    }

    cout<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
            {
                if(i+j>m-1)
                {
                    cout<<"*";
                }
                else
                {
                    cout<<" ";
                }
                
            }
        cout<<'|'<<endl;
    }


    return 0;
}