#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int sum = 0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            sum += pow(i,4);
        }

        // cout<<sum;

        int mul = 1;
        for(int i=1;i<=n;i++)
        {
            mul *= i;
        }
        // cout<<mul;
        if(sum > mul)
        {
            cout<<gcd(mul,sum)<<endl;
        }
        else
        {
            cout<<gcd(sum,mul)<<endl;
        }
    }
}