// I/P
// str = "geek"
// O/P
// 2

// I/P
// str = "abbac"
// O/P
// 1

// I/P
// str = "abcde"
// O/P
// 4

// I/P
// str = "aaaa"
// O/P
// 0

// I/P
// str = "abbabbc"
// O/P
// 2

#include <iostream>
#include <limits.h>

using namespace std;

bool isPallindrome(string str,int s,int e)
{
    while(s <= e)
    {
        if(str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int Palindrome_Partitioning_recursive(string s,int i,int j)
{
    if(isPallindrome(s,i,j) )
    {
        return 0;
    }
    int res = INT_MAX;
    for(int k=i;k<j;k++)
    {
        res = min(res, 
        1 +
        Palindrome_Partitioning_recursive(s,i,k) +
        Palindrome_Partitioning_recursive(s,k+1,j)
        );
    }
    return res;
}

int Palindrome_Partitioning_dynamic_sol(string s,int n)
{
    int dp[n][n];
    // (n-1)*(n-1)

    for(int i=0;i<n;i++)
    {
        dp[i][i] = 0;
    }

    // there is no (less than equal to) (<=)
    // all are (less than) (<)
    
    // Palindrome_Partitioning
    // gap starts with 1
    // Matrix_Chain_Multiplication
    // gap starts with 2
    for(int gap = 1;gap < n;gap++)
    {
        // i starts with 0 in both
        for(int i=0;i+gap < n;i++)
        {
            int j = i + gap;
            if(isPallindrome(s,i,j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                // Palindrome_Partitioning
                // k = i
                // Matrix_Chain_Multiplication
                // k = i+1
                for(int k=i;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    string s = "geek";
    int n = s.length();
    cout<<Palindrome_Partitioning_recursive(s,0,n-1);
    cout<<endl;
    cout<<Palindrome_Partitioning_dynamic_sol(s,n);
}