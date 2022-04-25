#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {7,10,4,10,6,5,2};
    int n=sizeof(arr)/sizeof(int);

    int curr = arr[n-1];
    cout<<curr<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(curr < arr[i])
        {
            cout<<arr[i]<<" ";
            curr = arr[i];
        }
    }
    return 0;
}