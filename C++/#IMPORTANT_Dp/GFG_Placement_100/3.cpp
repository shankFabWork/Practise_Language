// LCS - Longest Common Substring
// Memoization

#include <iostream>
#include <cstring>

using namespace std;

int memo[100][100];
int lcs(string s1,string s2,int m,int n)
{
    if(memo[m][n] == -1)
    {
        if(m == 0 || n == 0)
        {
            memo[m][n] = 0;
        }
        else
        {
            if(s1[m-1] == s2[n-1])
            {
                memo[m][n] = 1+lcs(s1,s2,m-1,n-1);
            }
            else
            {
                memo[m][n] = max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
            }
        }
    }
    return memo[m][n];
}


int main()
{
    string s1 = "ABC";
    string s2 = "BCD";
    int m = s1.length();
    int n = s2.length();
    memset(memo,-1,sizeof(memo));

    cout<<lcs(s1,s2,m,n);
    // TC - O(n*m)
    // SC - O(n*m)

}