// I/P
// 20 5 4 6
// O/P
// 25

// I/P
// 2 3 15 7
// O/P
// 17

// you have right to make first move
// after one move opponent will choose 
// the coin and then your will choose 
// and so on . Considering the maximum 
// value of choosing coins and 
// your opponent will choose

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {20,5,4,6};
    int n = sizeof(arr)/sizeof(int);

    int dp[n][n];
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }

    for(int gap = 3;gap < n;gap = gap + 2)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j = i+gap;
            dp[i][j] = max(
                arr[i]+min(dp[i+1][j],dp[i+1][j-1]),
                arr[i]+min(dp[i+1][j-1],dp[i][j-2])
                );
        }
    }
    cout<<dp[0][n-1];

    // TC - O(n^2)
    // SC - O(n^2)

}