// we are given a rod of length 'n'
// we have to  do maximum cut 
// in such a way that each rod length
// must be either 'a' ,
// either 'b' & either 'c'

// I/P
// n = 5 , a = 1, b = 2 , c = 3
// O/P
// 5
// maximum we can do 5 cuts
// of 1+1+1+1+1

// I/P
// n = 23 , a = 12, b = 11 , c = 13
// O/P
// 2

// I/P
// n = 3 , a = 2, b = 4 , c = 2
// O/P
// -1

#include <iostream>
#include <string.h>

using namespace std;

int maxCuts(int n, int a, int b, int c) 
{ 
    int dp[n+1];  
    dp[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        dp[i] = -1;
        
        if(i-a >=0) dp[i] = max(dp[i],dp[i-a]);
        
        if(i-b >=0) dp[i] = max(dp[i],dp[i-b]);
        
        if(i-c >=0) dp[i] = max(dp[i],dp[i-c]);
        
        if(dp[i]!=-1)
        dp[i]++;
    }

    return dp[n];
} 


int main() 
{	
    int n = 5, a = 1, b = 2, c = 3;

    cout<<maxCuts(n, a, b, c);
}