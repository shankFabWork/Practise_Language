// An anagram of a string is another string that 
// contains the same characters, only the 
// order of characters can be different

// keep and peek are anagrams
// silent and listen are anagrams
// abb and bab are anagrams

#include <iostream>
#include <algorithm>

using namespace std;

bool Check_for_Anagram_one(string s1,string s2)
{
    if(s1.length() != s2.length() )
    {
        return false;
    }

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1 == s2);
}

// http://www.asciitable.com/
// refer this

const int CHAR = 256;

bool Check_for_Anagram_two(string s1,string s2)
{
    if(s1.length() != s2.length() )
    {
        return false;
    }

    int count[CHAR] = {0};

    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(int i=0;i<CHAR;i++)
    {
        if(count[i] != 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    string s1 = "listen";
    string s2 = "silent";

    cout<<Check_for_Anagram_one(s1,s2);
    // Time Complexity -> O(n.log(n))
    // Space Complexity -> O(1)

    cout<<Check_for_Anagram_two(s1,s2);
    // Time Complexity -> O(n+CHAR)
    // Space Complexity -> O(CHAR)

    return 0;
}