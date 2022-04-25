#include <bits/stdc++.h>

using namespace std;

// 1   2   3   4
// 5   6   7   8
// 9   10 11 12
// 13 14 15 16
// 17 18 19 20

int main()
{
    int row = 4;
    int column = 3;
    int arr[row][column] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };
    int t = 0,b = row-1,l = 0,r = column-1;
    while(t <= b && l <= r)
    {
        for(int i=l;i<=r;i++)
        {
            cout<<arr[t][i]<<" ";
        }
        t++;
        for(int i=t;i<=b;i++)
        {
            cout<<arr[i][r]<<" ";
        }
        r--;
        for(int i=r;i>=l;i--)
        {
            cout<<arr[b][i]<<" ";
        }
        b--;
        for(int i=b;i>=t;i--)
        {
            cout<<arr[i][l]<<" ";
        }
        l++;
    }

    return 0;
}