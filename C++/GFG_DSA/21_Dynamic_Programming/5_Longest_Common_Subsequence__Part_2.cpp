// we are going to follow tabulation
// and it uses top-down approach

#include <iostream>

using namespace std;

int Longest_Common_Subsequence_tabulation(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];   
    for(int i=0;i<=n;i++)
    {
        dp[0][i] = 0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[j][0] = 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.length();
    int n = s2.length();
    
    cout<<Longest_Common_Subsequence_tabulation(s1,s2,m,n);
    // Time Complexity -> (m*n)
    // Tabulation , it is bottom-down approach

    return 0;
}

