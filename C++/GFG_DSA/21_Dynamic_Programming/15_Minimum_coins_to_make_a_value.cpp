// we can have infinite number of coins
// we need to make value with minimum number of coins
// I/P
// coins[] = {25,10,5}
// val = 30
// O/P
// 2 => 25+5

// 3 => 10+10+10
// This is not minimum

// I/P
// coins[] = {9,6,5,1}
// val = 11
// O/P
// 2

#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;
    
int minCoins(int arr[], int n, int value) 
{ 
    int dp[value + 1];    
    dp[0] = 0; 
   
    for (int i = 1; i <= value; i++) 
    {
        dp[i] = INT_MAX; 
    }
   
    for (int i=1;i<=value;i++) 
    { 
        for (int j=0;j<n;j++)
        {
            if (arr[j] <= i) 
            { 
                int sub_res = dp[i - arr[j]]; 
                if (sub_res != INT_MAX) 
                {
                    dp[i] = min(dp[i],sub_res + 1); 
                }
            }             
        }
    } 
    return dp[value];    
}  


int main() 
{	
    int arr[] = {3, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 5;

    cout<<minCoins(arr, n, val);
}