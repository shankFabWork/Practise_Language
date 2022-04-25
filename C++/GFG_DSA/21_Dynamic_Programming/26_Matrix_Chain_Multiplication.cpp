#include <bits/stdc++.h>

using namespace std;

int Matrix_Chain_Multiplication_recursion(int arr[],int i,int j)
{
    if(i+1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        res = min(res ,
        Matrix_Chain_Multiplication_recursion(arr,i,k)+
        Matrix_Chain_Multiplication_recursion(arr,k,j)+
        arr[i]*arr[j]*arr[k]
        );
    }
    return res;
}

int Matrix_Chain_Multiplication_dp(int arr[],int n)
{
    int dp[n][n];
    // (n-1)*(n-1)
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1] = 0;
    }
    for(int gap=2;gap<n;gap++)
    {   
        for(int i=0;i+gap<n;i++)
        {
            int j = i+gap;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
            }
        }
    }
    return dp[0][n-1];
}

int main() 
{ 
	// int arr[] = {40, 20, 30, 10, 30}; 
    int arr[]= {2, 1, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout<<Matrix_Chain_Multiplication_recursion(arr, 0, n - 1); 
    cout<<endl;
    cout<<Matrix_Chain_Multiplication_dp(arr,n);
} 
