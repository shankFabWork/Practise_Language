// time complexity is O(n^3*k)
// space complexity is O(n*k)
// but we can optimize it  
// by prefix sum array , so then
// time complexity is O(n^2*k)
// space complexity is O(n^2*k)+O(n*n)


#include <iostream>
#include <limits.h>

using namespace std;

int sum(int arr[],int s,int e)
{
    int sum = 0;
    for(int i=s;i<=e;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int getMin_dp_sol(int arr[],int n,int k)
{
    int dp[k+1][n+1];
    for(int i=1;i<=n;i++)
    {
        dp[1][i] = sum(arr,0,i-1);
    }
    for(int i=1;i<=k;i++)
    {
        dp[i][1] = arr[0]; 
    }
    for(int i=2;i<=k;i++)
    {
        for(int j=2;j<=n;j++)
        {
            int res = INT_MAX;
            for(int p=1;p<j;p++)
            {
                res = min( res,max( dp[i-1][p],sum(arr,p,j-1) ));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[] = {10,5,30,1,2,5,10,10};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    cout<<getMin_dp_sol(arr,n,k);
}
