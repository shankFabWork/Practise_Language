#include <iostream>
#include <limits.h>

using namespace std;

int Egg_Dropping_Puzzle_one(int f,int e)
{
    int dp[f+1][e+1];

    // the first column i.e. 0th column will be dummy column
    // i.e. there will be no use of that column

    // if we have 1 egg so number of trails = number of floors
    for(int i=1;i<=f;i++)
    {
        dp[i][1] = i;
    }

    // if we have 0 floor so number of trails will be 0
    // if we have 1 floor so number of trails will be 1
    for(int i=1;i<=e;i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(int i=2;i<=f;i++)
    {
        for(int j=2;j<=e;j++)
        {
            dp[i][j] = INT_MAX;
            for(int x = 1;x<=i;x++)
            {
                dp[i][j] = min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}

int main()
{
    int f = 10;
    int e = 2;
    cout<<Egg_Dropping_Puzzle_one(f,e);
}
