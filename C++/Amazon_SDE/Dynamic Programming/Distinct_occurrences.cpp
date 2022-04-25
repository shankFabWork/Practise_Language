#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "abcbac";
    map <char,int> mp;
    int dis_cou = 0;
    int n = str.length();
    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        char ch = str[i-1];
        dp[i] = 2*dp[i-1];
        if(mp.find(ch) != mp.end())
        {
            dp[i] = dp[i] - dp[mp[ch]-1];
        }
        mp[ch]=i;
        // mp.insert({str[i],i});
    }   
    cout<<dp[n]-1;


    return 0;
}