// I/P
// s1 = "ABCD" 
// s2 = "CDAB"
// O/P
// Yes

// I/P
// s1 = "ABAAA"
// s2 = "BAAAA"
// O/P
// yes

// I/P
// s1 = "ABAB"
// s2 = "ABBA"
// O/P
// no

// s1 = ABCD
// s2 = CDAB
// s1 + s1
// ABCDABCD
// if "CDAB" is present 
// then true
// else false

#include <iostream>
#include <string>

using namespace std;

// temp = 'a'
// abcd
// bcda

void rotate(string &s)
{
    int n = s.length();
    char temp = s[0];
    for(int i=0;i<n-1;i++)
    {
        s[i] = s[i+1];
    }
    s[n-1] = temp;
}

bool Check_if_Strings_are_Rotations_one(string s1,string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(s1 == s2)
        {
            return true;
        }
        rotate(s1);
    }
    return false;
}

bool Check_if_Strings_are_Rotations_two(string s1,string s2)
{
    if(s1.length() != s2.length()) return false;
    return ((s1 + s1).find(s2) != string::npos);
}

int main()
{
    string s1 = "ABCD";
    string s2 = "CDAD";
    // string s2 = "CDFG";

    cout<<Check_if_Strings_are_Rotations_one(s1,s2);
    // TC - O(n^2)
    // SC - O(1)

    cout<<endl;
    // cout<<Check_if_Strings_are_Rotations_two(s1,s2);
    // TC - O(n)
    // SC - O(1)

    return 0;
}