#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    // string s1 = "abbba";
    // string s2 = s1;
    // reverse(s2.begin(),s2.end());
    // if(s1 == s2)
    // {
    //     cout<<"same";
    // }
    // else
    // {
    //     cout<<"not smae";
    // }

    string s1 = "abbbab";
    int beg = 0;
    int end = s1.length()-1;
    int count = 1;
    while(beg < end)
    {
        if(s1[beg] != s1[end])
        {
            count = 0;
            break;
        }
        beg++;
        end--;
    }
    if(count == 1)
    {
        cout<<"pallindrome";
    }
    else
    {
        cout<<"not pallindrome";
    }
    

}