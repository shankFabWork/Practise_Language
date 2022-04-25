#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t t;
    cin>>t;
    while(t--)
    {
        long long int n,d;
        cin>>n>>d;
        long long int i = 0;
        long long int r = 0,nr = 0;
        for(long long int k=0;k<n;k++)
        {
            long long int val;
            cin>>val;
            if(val >= 80 && val <= 9)
            {
                r++;
            }
        }
        nr = n - r;
        if(d == 1)
        {
            long long int c = nr+r;
            cout<<c<<endl;
        }
        else
        {
            while(r > 0)
            {
                ++i;
                r = r - d;
            }
            while(nr > 0)
            {
                ++i;
                nr = nr - d;
            }

            cout<<i<<endl;
        }
    }

    return 0;
}