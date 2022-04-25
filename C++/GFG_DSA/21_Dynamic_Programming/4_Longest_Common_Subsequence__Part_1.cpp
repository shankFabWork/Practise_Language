// What is SubSequence ?
// Subsequence of "CDA"
// "","C","D","A","CD","DA","CA","CDA"

// I/P
// s1 = "ABCDGH"
// s2 = "AEDFHR"
// O/P
// 3
// ADH

// I/P
// s1 = AGGTAB 
// s2 = GXTXAYB
// O/P
// 4

// I/P
// s1 = XYZ
// s2 = XYZ
// O/P
// 3

// I/P
// s1 = ABC
// s2 = XY
// O/P
// 0

// in Dynamic Programming
// LCS - Longest Common Subsequence  

#include <iostream>
#include <cstring>

using namespace std;

int Longest_Common_Subsequence(string s1,string s2,int m,int n)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }
    if(s1[m-1] == s2[n-1])
    {
        return 1+Longest_Common_Subsequence(s1,s2,m-1,n-1);
    }
    else
    {
        return max(
                    Longest_Common_Subsequence(s1,s2,m-1,n),
                    Longest_Common_Subsequence(s1,s2,m,n-1)
                );
    }
}

// [m+1][n+1]
// why +1 because it reaches 0 
// when it reaches 0 we directly return 0
int memo[1000][1000];
int Longest_Common_Subsequence_memo(string s1,string s2,int m,int n)
{
    if(memo[m][n] != -1)    
    {
        return memo[m][n];
    }
    if(m == 0 || n == 0)
    {
        memo[m][n]=0;
    }
    else
    {
        if(s1[m-1] == s2[n-1])
        {
            memo[m][n]=1+Longest_Common_Subsequence_memo(s1,s2,m-1,n-1);
        }
        else
        {
            memo[m][n]=max(
                        Longest_Common_Subsequence_memo(s1,s2,m-1,n),
                        Longest_Common_Subsequence_memo(s1,s2,m,n-1)
                    );
        }
    }
    return memo[m][n];
}

int main()
{
    string s1 = "AGTAB";
    string s2 = "GXTXAYB";
    // string s1 = "AXYZ";
    // string s2 = "BAZ";
    int m = s1.length();
    int n = s2.length();
    memset(memo,-1,sizeof(memo));
    // cout<<Longest_Common_Subsequence(s1,s2,m,n);
    cout<<Longest_Common_Subsequence_memo(s1,s2,m,n);
    // memoization , it is top-down approach
    // Time Complexity -> O(m*n)
    // Space  Complexity -> O(m*n)
    return 0;
}