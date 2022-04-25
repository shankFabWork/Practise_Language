#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "gaga";
    int s = 0;
    int e = str.length()-1;
    while(s < e)
    {
        if(str[s] != str[e])
        {
            break;
        }
        s++;
        e--;
    }
    if(s == e)
    {
        cout<<"string is pallindrome";
    }
    else
    {
        cout<<"string is not pallindrome";
    }
    return 0;
}