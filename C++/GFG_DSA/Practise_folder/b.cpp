#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {10,10,20,30,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector <int> v;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] != arr[i+1])
        {
            v.push_back(arr[i]);
        }
    }
    v.push_back(arr[n-1]);
    for(int data:v)
    {
        cout<<data<<" ";
    }
    return 0;
}