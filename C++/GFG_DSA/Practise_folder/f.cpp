#include <bits/stdc++.h>

using namespace std;

int max_val(int a ,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int min_val(int a ,int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}


int main()
{
    int arr[]={30,10,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // sort(arr,arr+n);
    // cout<<arr[n-1]-arr[0];

    int maxDiff = arr[1] - arr[0];
    int minVal = arr[0];
    for(int i=1;i<n;i++)
    {
        maxDiff = max_val(maxDiff,arr[i]-minVal);
        minVal = min_val(minVal,arr[i]);
    }
    cout<<maxDiff;

    return 0;
}