// Coin Change
// Count Combination
// Tabulation

#include <iostream>

using namespace std;

int getCoin(int coin[],int n,int sum)
{
    int dp[sum+1][n+1];
    for(int i=0;i<=sum;i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0;j<=n;j++)
    {
        dp[0][j] = 1;
    }
    for(int i=0;i<=sum;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if()
        }
    }
}

int main()
{
    int coin[] = {2,5,3,6};
    int n = sizeof(coin)/sizeof(coin[0]);
    int sum = 10;

    cout<<getCoin(coin,n,sum);

}