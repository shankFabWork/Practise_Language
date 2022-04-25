#include <bits/stdc++.h>

using namespace std;

void left_rotation(int arr[],int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void reverse(int arr[],int s,int e)
{
    while(s <= e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void left_rotation_by_k(int arr[],int n,int k)
{   
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int arr[]={1,2,3,4,5};
    // 2 1 5 4 3
    // 3 4 5 1 2
    // 3 4 5 1 2
    int n=sizeof(arr)/sizeof(int);
    // left_rotation(arr,n);
    int k = 2;

    left_rotation_by_k(arr,n,k);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}