#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {5,0,6,2,3};
    int n=sizeof(arr)/sizeof(int);

    int lMax[n];
    lMax[0] = arr[0];
    int rMax[n];
    rMax[n-1] = arr[n-1];
    for(int i=1;i<n;i++)
    {
        lMax[i] = max(lMax[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        rMax[i] = max(rMax[i+1],arr[i]);
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res += (min(lMax[i],rMax[i]) - arr[i]);
    }
    cout<<res;
    return 0;
}