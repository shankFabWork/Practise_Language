#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]={8,5,0,10,0,20,0,30,40,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    // 8 5 0 10 0 20
    // 8 5 20 10 0 20

    int s = 0;
    int e = n-1;
    while(s <= e)
    {
        while(arr[s] != 0)
        {
            s++;
        }
        while(arr[e] == 0)
        {
            e--;
        }
        if(s > e)
        {
            break;
        }
        swap(arr[s],arr[e]);
    }



    // int counter = 0;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i] != 0)
    //     {
    //         swap(arr[i],arr[counter]);
    //         counter++;
    //     }
    // }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}