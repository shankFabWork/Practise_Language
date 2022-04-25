// I/P
// int arr[] = {10,20,30,40};
// int k = 2;
// O/P
// 60

// I/P
// int arr[] = {10,20,30};
// int k = 1;
// O/P
// 60

// I/P
// int arr[] = {10,5,30,1,2,5,10,10};
// int k = 3;
// O/P
// 30

// array elements are pages in a book
// k is the no of studens

// Rules
// 1) Minize the maximum pages allocated
// 2) Only the contiguous pages can be allocated

#include <iostream>
#include <limits.h>

using namespace std;

int sum(int arr[],int s,int e)
{
    int sum = 0;
    for(int i=s;i<=e;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int getMin_recursive(int arr[],int n,int k)
{
    if(k == 1)
    {
        return sum(arr,0,n-1);
    }
    if(n == 1)
    {
        return arr[0];
    }
    int res = INT_MAX;
    for(int i=1;i<n;i++)
    {
        res = min(res,max(getMin_recursive(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}

int main()
{
    int arr[] = {10,5,30,1,2,5,10,10};
    // int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    cout<<getMin_recursive(arr,n,k);
}