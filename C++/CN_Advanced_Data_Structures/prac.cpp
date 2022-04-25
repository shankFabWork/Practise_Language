#include <iostream>
#include <climits>

using namespace std;

int dp[100];
void min_step_to_1_bottom_up(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = dp[i - 1];
        if(i % 2 == 0)
        {
            b = dp[i/2];
        }
        if(i % 3 == 0)
        {
            c = dp[i/3];
        }
        int ans = min(a,min(b,c)) + 1;
        dp[i] = ans;
    }
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[n];
}

int main()
{
    int n = 10;
    fill(dp,dp+n+1,-1);
    min_step_to_1_bottom_up(n);
}