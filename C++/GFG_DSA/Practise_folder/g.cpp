#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {10,10,10,25,30,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    int freq = 1;
    while(i < n)
    {
        while(i < n && arr[i] == arr[i+1])
        {
            freq++;
            i++;
        }
        cout<<arr[i]<<" "<<freq<<endl;
        freq = 1;
        i++;
    }

    return 0;
}