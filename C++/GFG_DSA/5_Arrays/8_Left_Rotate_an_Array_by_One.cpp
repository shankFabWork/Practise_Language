#include <iostream>

using namespace std;

// I/P->
// 1 2 3 4 5
// O/P->
// 2 3 4 5 1

void left_rotate(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;  
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);

    left_rotate(arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

//Time Complexity -> O(n)
//Space Complexity -> O(1)
