#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "aabbbbeeeeffggg";
    int n = str.length();
    int c = 1;
    for(int i=0;i<n-1;i++)
    {
        if(str[i] == str[i+1])
        {
            c++;
        }
        else
        {
            cout<<str[i-1]<<c;
            c = 1;
        }
    }
    cout<<str[n-1]<<c;
    return 0;
}