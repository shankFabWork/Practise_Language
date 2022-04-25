#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {10,10,10,25,30,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    int freq = 1;
    int i = 1;
    while(i < n)
    {
        while(i<n && arr[i] == arr[i-1])
        {
            freq++;
            i++;
        }
        cout<<arr[i-1]<<" "<<freq<<endl;
        i++;
        freq = 1;
    }

    if(n == 1 || arr[n-1] != arr[n-2])
    {
        cout<<arr[n-1]<<" "<<1;
    }
    // Time Complexity is Clearly O(n)
    // Space Complexity - O(1)
}