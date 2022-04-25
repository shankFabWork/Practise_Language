// An interesting array problem to find the length of the 
// longest subarray that has alternating even odd elements

// 10 12 14 7 8
// 3

// 7 10 13 14
// 4

// 10 12 8 4
// 1

// subarray is always continuous
#include <iostream>

using namespace std;

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int Longest_Even_Odd_Subarray_one(int arr[],int n)
{
    int res = 1;
    int curr = 1;
    for(int i=1;i<n;i++)
    {
        curr = 1;
        for(int j=i+1;j<n;j++)
        {
            if( 
                ((arr[j]%2 == 0) && (arr[j-1]%2 != 0)) 
                ||
                ((arr[j]%2 != 0) && (arr[j-1]%2 == 0)) 
             )
            {
                curr += 1;
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

int Longest_Even_Odd_Subarray_two(int arr[],int n)
{
    int curr = 1;
    int res = 1;
    for(int i=1;i<n;i++)
    {
            if( 
                ((arr[i]%2 == 0) && (arr[i-1]%2 != 0)) 
                ||
                ((arr[i]%2 != 0) && (arr[i-1]%2 == 0)) 
             )
             {
                 curr += 1;
             }
             else
             {
                 curr = 1;
             }
             res = max_val(res,curr);
    }
    return res;
}

int main()
{
    int arr[] = {5,10,20,6,3,8};
    int n=sizeof(arr)/sizeof(int);

    // cout<<Longest_Even_Odd_Subarray_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    // loop will start with 10
    // 5 10 20 6 3 8 
    // 1 2  1  1 2 3 -> curr
    // 1 2  2  2 2 3 -> res
    // maximum value
    // 3

    cout<<Longest_Even_Odd_Subarray_two(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    // loop will start with 10
    // 5 10 20 6 3 8
    // 1  2  1 1 2 3 -> curr
    // 1  2  2 2 2 3 -> res
    // maximum value
    // 3


    return 0;
}