// Longest Increasing Subsequence
// I/P
// int arr[] = {3,4,2,8,10};
// O/P
// 4
// 3 4 8 10

// I/P
// int arr[] = {4,10,6,5,8,11,2,20};
// O/P
// 5

// I/P
// int arr[] = {10,20,30};
// O/P
// 3

// I/P
// int arr[] = {30,20,10};
// O/P
// 1

#include <iostream>
#include <limits.h>

using namespace std;

int Longest_Increasing_Subsequence_Problem(int arr[],int n)
{
    int lis[n];
    lis[0] = 1;
    for(int i=1;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    int res = INT_MIN;
    for(int i=0;i<n;i++)
    {
        res = max(lis[i], res);
    }
    
    return res;
}

int main()
{
    int arr[] = {4,10,6,5,8,11,2,20};
    int n = sizeof(arr)/sizeof(int);

    cout<<Longest_Increasing_Subsequence_Problem(arr,n);
    // TC - O(N^2)
    // SC - O(N)
}