// I/P
// s1 = "CAT"
// s2 = "CUT"
// O/P
// 1

// I/P
// s1 = "GEEK"
// s2 = "GEEKS"
// O/P
// 1

// I/P
// s1 = "SATURDAY"
// s2 = "SUNDAY"
// O/P
// 3

// we can do three operations in it 
// to convert s1 to s2

// Insert a character
// Delete a character
// Replace a character
// we have to do it with minimum number of operations

#include <iostream>
#include <string.h>

using namespace std;

const int m = 3;
const int n = 3;
int eD(string s1, string s2, int m, int n)
{
    if(m==0)
        return 0;
    if(n==0)
        return 0;
        
    if(s1[m-1]==s2[n-1])
        return eD(s1,s2,m-1,n-1);
    else
    {
        return 1 + min(eD(s1,s2,m,n-1), min(eD(s1,s2,m-1,n), eD(s1,s2,m-1,n-1)));
    }
}

int memo[m+1][n+1];
int eD_memo(string s1, string s2, int m, int n)
{
    if(memo[m][n] != -1)
    {
        return memo[m][n];
    }
    if(m==0)
    {
        memo[m][n] = 0;
        return 0;
    }
    if(n==0)
    {
        memo[m][n] = 0;
        return 0;
    }
    if(s1[m-1]==s2[n-1])
    {
        memo[m][n] = eD(s1,s2,m-1,n-1);
    }
    else
    {
        memo[m][n] = 1 + min(eD(s1,s2,m,n-1), min(eD(s1,s2,m-1,n), eD(s1,s2,m-1,n-1)));
    }
    return memo[m][n];
}

int main() 
{		
    // string s1="CAT", s2="CUT";
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    cout<<eD(s1,s2,m,n);
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            memo[i][j] = -1;
        }
    }
    cout<<eD_memo(s1,s2,m,n);
}