// 3) Maximum Length Bitonic Subsequence
// What is Bitonic Subsequence ?
// A Subsequence which is first increasing
// and then decreasing

// I/P
// int arr[] = {1,11,2,10,4,5,2,1}
// O/P
// 6
// 1 2 10 5 2 1
// or
// 1 2 10 4 2 1

// I/P
// int arr[] = {12,11,40,5,3,1}
// O/P
// 5


// I/P
// int arr[] = {30,20,10}
// O/P
// 3

#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

void LIS_bitonic(int arr[],int n,int lis[])
{
    lis[0] = 1;
    for(int i=1;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
            {
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<lis[i]<<" ";
    }
}

void LDS_bitonic(int arr[],int n,int lds[])
{
    lds[n-1] = 1;
    int l = 1;
    for(int i=n-2;i>=0;i--)
    {
        lds[i] = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {   
                lds[i] = max(lds[i],lds[j]+1);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<lds[i]<<" ";
    }
}

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    // int arr[] = {12,11,40,5,3,1};
    int arr[] = {1,11,2,10,4,5,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    // cout<<LIS_one(arr,n);
    int lis[n],lds[n];
    LIS_bitonic(arr,n,lis);
    cout<<endl;
    LDS_bitonic(arr,n,lds);
    cout<<endl;
    int res = INT_MIN;
    for(int i=0;i<n;i++)
    {
        res = max_val(res, (lis[i]+lds[i]-1) );
    }
    cout<<res<<endl;

    // Time Complexity - O(n^2)
    // Space Complexity - O(n)
}