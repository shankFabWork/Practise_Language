// Find count of maximum consecutive 1s in a binary array. 
// Two approaches are discussed, one is O(n^2) and other is O(n). 
// Both of these approaches require O(1) auxiliary space.

#include <iostream>

using namespace std;

// I/P
// 1 0 1 1 1 1 0 1 1 1
// O/P
// 4

// I/P
// 1 1 1 1 
// O/P
// 4

// I/P
// 0 0 1 1 
// O/P
// 2

// I/P
// 0 0 0 0 
// O/P
// 0

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int maxConsecutiveOne_one(int arr[],int n)
{
    int res = 0;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        curr = 0;
        for(int j=i;j<n;j++)
        {
            if(arr[j] == 1)
            {
                curr = curr + 1;
            }
            else
            {
                break;
            }
        }
        res = max_val(res,curr);
    }
    return res;
}

int maxConsecutiveOne_two(int arr[],int n)
{
    int curr = 0;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 1)
        {
            curr = 0;
        }
        else
        {
            curr = curr + 1;
        }
        res = max_val(res,curr);
    }
    return res;
}

int main()
{
    int arr[] = {1,0,1,1,1,1,0,1,1,1};
    int n=sizeof(arr)/sizeof(int);
    
    // cout<<maxConsecutiveOne_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    cout<<maxConsecutiveOne_two(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    return 0;
}

