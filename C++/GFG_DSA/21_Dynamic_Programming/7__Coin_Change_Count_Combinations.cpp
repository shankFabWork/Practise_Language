// input ::
// coins[] = {1,2,3};
// sum = 4;
// output ::
// 4
// Explaination:
// 4 = 2+1+1 --> 1
// 4 = 1+1+1+1 --> 2
// 4 = 2+2 --> 3
// 4 = 1+3 --> 4

// input ::
// coins[] = {2,5,3,6};
// sum = 10;
// output ::
// 5
// Explaination:
// 10 = 2+2+2+2+2 --> 1
// 10 = 5+5 --> 2
// 10 = 5+2+3 --> 3
// 10 = 6+2+2 --> 4
// 10 = 3+3+2+2 --> 5

// we will begin from the end
// we have infinite number of coins
// if sum is 0 , there is one way to select the coin
// if n is 0 , there is zero way to select the coin
// n*sum 

#include <iostream>

using namespace std;

// Egg_Dropping_Puzzle_one
// dp[f+1][e+1]
// row -> floor
// column -> egg

// Palindrome_Partitioning_dynamic_sol
// int dp[n][n];
// gap = 1
// dp[i][i+1] = 0;
// k = i 

// Matrix_Chain_Multiplication
// int dp[n][n];
// gap = 2
// dp[i][i] = 0;
// k = i+1

// Optimal_Strategy_for_a_Game
// int dp[n][n];

// Maximum Cut
// int dp[n+1]; 

// 0-1 knapSack
// row -> n
// column -> w
// int dp[n + 1][W + 1]; 

// Allocate_Minimum_Pages__DP_Solution
// int dp[k+1][n+1];

// Subset_Sum_Problem__DP_Solution
// int dp[n+1][sum+1];
// 1 0 0
// 1
// 1
// row -> n
// column -> sum
// if(j < arr[i-1])    
// {
//     dp[i][j] = dp[i-1][j];
// }
// else
// {
//     dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
// }

// Coin_Change_Count_Combinations
// r -> sum
// c -> n
// int dp[sum+1][n+1];
// 1 1 1 
// 0
// 0
// dp[i][j] = dp[i][j-1];
// if(i >= coins[j-1] )
// {
//     dp[i][j] += dp[i-coins[j-1]][j];
// }

int getCount(int coins[],int n,int sum)
{
    // r -> sum
    // c -> n
    int dp[sum+1][n+1];
    
    // 1 1 1 
    // 0
    // 0

    // i start with 0
    for(int i=0;i<=n;i++)
    {
        dp[0][i] = 1;
    }
    // i start with 1
    for(int i=1;i<=sum;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];
            if(coins[j-1] <= i)
            {
                dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
    }
    return dp[sum][n];
}

int main()
{
    int coins[]={1, 2, 3}, sum=4, n=3;
    cout<<getCount(coins, n, sum);
    // Time Complexity - O(n*sum)
    // Space Complexity - O(n*sum)
    // we have optimized solution for it
    // it takes O(sum) space complexity
}