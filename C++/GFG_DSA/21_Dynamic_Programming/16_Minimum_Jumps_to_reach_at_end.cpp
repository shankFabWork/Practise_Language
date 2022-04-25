// I/P
// int arr[] = {3,4,2,1,2,1}
// O/P
// 2

// I/P
// int arr[] = {4,1,5,3,1,3,2,1,8}
// O/P
// 3

#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int arr[] = {4,1,5,3,1,3,2,1,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n];

    // if u have array of size => "1" 
    // u need 0 steps
    
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        dp[i] = INT_MAX;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] + j >= i && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[n-1];
}