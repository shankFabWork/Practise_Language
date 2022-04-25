#include <iostream>

using namespace std;

// first we need to make prefix sum array
// 0 1  2 3  4  5  6 -> index
// 6 3 -2 4  -1 0 -5 -> orignal array
// 6 9  7 11 10 10 5 -> prefix sum array 
// calculate the sum between range [0,4] ?
// arr[4] = 11
// calculate the sum between range [0,6] ?
// arr[6] = 5

// calculate the sum between range [2,6] ?

// sum between range [0,6] = 
// sum between range [0,1] + sum between range [2,6]

// sum between range [2,6] =    
// sum between range [0,6] - sum between range [0,1] 

// (2,6) -> 6-(2-1)
// a=2 b=6
// (a,b) -> b-(a-1) 

void Prefix_Sum_two(int arr[],int n,int l,int r)
{
    // if l is 0 then it will become -1 according to this formula
    // cout<<(arr[r] - arr[l-1])<<" ";

    if(l == 0)
    {
        cout<<(arr[r])<<" ";
    }
    else
    {
        cout<<(arr[r] - arr[l-1])<<" ";
    }
}

void query(int arr[],int n)
{
    // n is size of array
    int a1=0,a2=2,b1=1,b2=3,c1=2,c2=6;
    
    Prefix_Sum_two(arr,n,a1,a2);
    Prefix_Sum_two(arr,n,b1,b2);
    Prefix_Sum_two(arr,n,c1,c2);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
}


int main()
{
    int arr[] = {2,8,3,9,6,5,4};
    int n=sizeof(arr)/sizeof(int);

    // making prefix sum array
    for(int i=1;i<n;i++)
    {
        arr[i] = arr[i-1] + arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Prefix_Sum_two(arr,n,4,6);
    // answer is 15

    query(arr,n);

    return 0;
}