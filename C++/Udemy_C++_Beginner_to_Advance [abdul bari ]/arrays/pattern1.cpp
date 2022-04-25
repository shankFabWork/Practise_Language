#include <iostream>

using namespace std;

int main()
{

    int arr[100][100];
    int n=5;
    int m=5;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<i;j++)
            {
                cout<<"*"<<" ";                
            }
        cout<<endl;
    }


    return 0;
}