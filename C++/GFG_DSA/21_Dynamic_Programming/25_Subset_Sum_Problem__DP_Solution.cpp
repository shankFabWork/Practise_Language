#include <iostream>

using namespace std;

int Subset_Sum_Problem_DP(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    // n=3
    // sum=5
    // 1 0 0 0 0 0 
    // 1
    // 1
    // 1
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j < arr[i-1])    
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[]= {2, 5, 3};
    int n = sizeof(arr)/sizeof(int); 
    int sum = 5;

    cout<<Subset_Sum_Problem_DP(arr,n,sum);
    // TC - 0(n*sum)
}