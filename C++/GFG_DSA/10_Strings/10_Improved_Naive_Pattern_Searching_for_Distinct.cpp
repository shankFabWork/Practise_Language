#include <iostream>

using namespace std;

// I/P
// txt = "ABCABCDABCD"
// pat = "ABCD"
// O/P
// 3 7

// I/P
// txt = "GEEKSFORGEEKS"
// pat = "EKS"
// O/P
// 2 10

// I/P
// txt = "ABCAAAD"
// pat = "ABD"
// O/P
// NO OUTPUT

// it will not give 0 1 2
// in this case
// string txt = "AAAAA";
// string pattern = "AAA";
// it will give
// 0 only

// what is distinct string ?
// Given a string, find the all distinct 
// (or non-repeating characters) in it.


void Improved_Pattern_Searching(string txt,string pattern)
{                                                                                   
    int n = txt.length();
    int m = pattern.length();

    for(int i=0;i<=n-m;)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(txt[i+j] != pattern[j])
            {
                break;
            }
        }
        if(j == m)
        {
            cout<<i<<" ";
        }
        if(j == 0)
        {
            i++;
        }
        else
        {
            i = i+j;
        }
    }
}

// it only works for dictinct 
// character in the pattern
// Improved Naive Pattern Searching for Distinct
// pattern = ABCD is distinct
// pattern = AAAA is not distinct
// this program do not work in same pattern
int main()
{

    // this is distict string
    // string txt = "GEEKSFORGEEKS";
    // string pattern = "EKS";

    // this is not distict string
    // as it is repeating 
    string txt = "ABCDDDABCD";
    string pattern = "ABCD";

    // string txt = "ABCABCD";
    // string pattern = "ABD";

    Improved_Pattern_Searching(txt,pattern);
    // Time Complexity -> O(n)    
    // Space Complexity -> O(1)
    
    return 0;
}