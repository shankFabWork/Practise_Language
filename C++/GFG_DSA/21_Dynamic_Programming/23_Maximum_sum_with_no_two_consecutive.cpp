// I/P
// int arr[] = {1,10,2};
// O/P
// 2

// I/P
// int arr[] = {8,7,6,10};
// O/P
// 18

// I/P
// int arr[] = {10,5,15,20,2,30};
// O/P
// 60

// sum for which we are finding 
// the array elements should not be contiguous

#include <iostream>

using namespace std;

int Max_sum_with_NoTwoConsecutive_recur(int arr[],int n)
{
    if(n == 1)
    {
        return arr[0];
    }
    if(n == 2)
    {
        return max(arr[0],arr[1]);
    }
    return max(
            Max_sum_with_NoTwoConsecutive_recur(arr,n-1),
            Max_sum_with_NoTwoConsecutive_recur(arr,n-2)+
            arr[n-1]
    );
}


// tabulation
int Max_sum_with_NoTwoConsecutive_dp(int arr[],int n)
{
    int dp[n+1];
    dp[1] = arr[0];
    dp[2] = max(arr[0],arr[1]);

    for(int i=3;i<=n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+arr[n-1]);
    }
    return dp[n];
}

int Max_sum_with_NoTwoConsecutive_dp_optimized(int arr[],int n)
{
    int prev_prev = arr[0];
    int prev = max(arr[0],arr[1]);
    int res = prev;
    for(int i=3;i<= n;i++)
    {
        res = max(prev,prev_prev+arr[n-1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main()
{
    int arr[] = {10,5,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<Max_sum_with_NoTwoConsecutive_recur(arr,n);
    cout<<endl;
    cout<<Max_sum_with_NoTwoConsecutive_dp(arr,n);
    cout<<endl;
    cout<<Max_sum_with_NoTwoConsecutive_dp_optimized(arr,n);

}