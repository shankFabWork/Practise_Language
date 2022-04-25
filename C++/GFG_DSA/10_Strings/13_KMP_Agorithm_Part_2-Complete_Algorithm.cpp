#include <iostream>
    
using namespace std;

// I/P
// txt = "abcdefg"
// pat = "bcd"
// O/P
// 1

// I/P
// txt = "aaaaab"
// pat = "aaaa"
// O/P
// 0 1

// I/P
// txt = "abcd"
// pat = "ba"
// O/P
// "Not Found"


// ::::::::: Theory :::::::::

// m -> length of pattern
// n -> length of text

// Naive ->
    // Time Complexity -> O((n-m)*m)
    // Space Complexity -> O(1)
// Naive for distict characters ->
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
// Rabin Karp ->
    // Time Complexity -> O((n-m)*m)
    // Space Complexity -> O(1)
// Knuth Morris Pratt (KMP) ->
    // Time Complexity -> O(n)
    // Space Complexity -> O(m)

void lppsa(string pattern,int lps[])
{
    int m = pattern.length();
    lps[0] =  0;
    int i = 1;
    int len = 0;
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
    // for(int i=0;i<m;i++)
    // {
    //     cout<<lps[i]<<" ";
    // }
}

void kmp_algo(string txt,string pat)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    lppsa(pat,lps);
    int i=0,j=0;
    while(i < n)
    {
        if(pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout<<i-j;
            j = lps[j-1];
        }
        else if(pat[j] != txt[i] && i<n)
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
}

int main()
{

    string txt = "ababcababaad";
    string pattern = "ababa";
    kmp_algo(txt,pattern);
    return 0;
}