// Explanation of the Kadane's algorithm.

// what is subarray ?
// in {1,2,3}
// {1}
// {2}
// {3}
// {1,2}
// {2,3} 
// {1,2,3}
// {3,1} and {1,3} is not a subarray as it is not continous

// just find out the largest sum and they should be continuous
// I/P
// 2 3 -8 7 -1 2 3
// O/P
// 7 -1 2 3
// 11

// I/P
// 5 8 3
// O/P
// 16

// I/P
// -6 -1 -8
// O/P
// -1


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

int Maximum_subarray_sum_one(int arr[],int n)
{
    int res=0,curr=0;
    for(int i=0;i<n;i++)
    {
        curr=0;
        for(int j=i;j<n;j++)
        {
            curr += arr[j];
        }
        res = max_val(curr,res);
    }
    return res;
}

// Kadane's algorithm
int Maximum_subarray_sum_two(int arr[],int n)
{
    int maxEnding = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++)
    {
        maxEnding = max_val( (arr[i] + maxEnding) , arr[i]);
        res = max_val(res,maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {1,-2,3,-1,-2};
    int n=sizeof(arr)/sizeof(int);

    // cout<<Maximum_subarray_sum_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    cout<<Maximum_subarray_sum_two(arr,n);
    // Kadane's algorithm
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    // Important
    // -5 1 -2 3 -1 2 -2
    // -5 1 -1 3  2 4  2
    // write maximum of this 
    // 4

    // -3 8 -2 4 -5 6
    // -3 8  6 10 5 11
    // write maximum of this 
    // 11 

    // 1 -2 3 -1 2
    // 1 -1 3  2 4
    // write maximum of this 
    // 4

    // 2 3 -8 7 -1 2 3
    // 2 5 -3 7  6 8 11
    // write maximum of this 
    // 11

    return 0;
}