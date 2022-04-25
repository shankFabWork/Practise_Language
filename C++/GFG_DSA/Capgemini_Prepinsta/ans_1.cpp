#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "Move#Hash#to#Front";
    int s = 0;
    int e = str.length()-1;
    // while(s < e)
    // {
    //     if(str[e] == '#')
    //     {
    //         swap(str[s],str[e]);
    //         s++;
    //     }
    //     e--;
    // }
    // cout<<str;

    string new_str = "";
    int no_of_hash = 0;
    string hash_str = "";
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '#')
        {
            hash_str += "#";
        }
        else
        {
            new_str += str[i];
        }
    }
    cout<<hash_str<<new_str;
    return 0;
}