#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r = 4;
    int c = 4;
    int arr[r][c] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<r;i++)
    {
        int s = 0;
        int e = c-1;
        while(s < e)
        {
            swap(arr[s][i],arr[e][i]);
            s++;
            e--;
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}