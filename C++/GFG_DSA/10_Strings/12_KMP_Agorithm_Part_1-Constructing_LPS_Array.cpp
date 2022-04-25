#include <iostream>

using namespace std;

// -----------------------
// Prefix of "abc"
// "","a","ab","abc"
// -----------------------
// Suffix of "abc"
// "","c","bc","abc"
// -----------------------
// Proper prefix of "abc"
// "","a","ab"
// -----------------------

// LPS -> longest Proper Prefix Suffix Array

// I/P
// str = "ababc"
// O/P
// 0 0 1 2 0

// I/P
// str = "aaaa"
// O/P
// 0 1 2 3 

// I/P
// str = "abcd"
// O/P
// 0 0 0 0

// I/P
// str = "ababab"
// O/P
// 0 0 1 2 3 4


// do not do O(n^3) this solution big one
int LCP_function(string str,int n)
{
    for(int len = n-1;len>=0;len--)
    {
        bool flag = true;
        for(int i=0;i<len;i++)
        {
            if(str[i] != str[n-len+i])
            {
                flag = false;
            }
        }
        if(flag == true)
        {
            return len;
        }
    }
    return 0;
}

// len -> n-1 - 0
// i -> 0 - len-1
// str[i] != str[n-len+i]
void KMP_Agorithm_one(string str)
{   
    int n = str.length();
    // longest prefix suffix array
    int lps[n];
    for(int i=0;i<n;i++)
    {
        lps[i] = 0;
    } 
    for(int i=0;i<n;i++)
    {
        lps[i] = LCP_function(str,i+1);
    } 
    for(int i=0;i<n;i++)
    {
        cout<<lps[i]<<" ";
    }    
}


// if(str[i] == str[len])
// len++
// str[i] = len
// len++
void KMP_Agorithm_two(string str)
{
    int n = str.length();
    int len = 0;
    int i = 1;
    int lps[n]={0};

    while(i < n)
    {
        if(str[len] == str[i])
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
                len = lps[len - 1];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<lps[i]<<" ";
    }
}

int main()
{
    // LPS Array
    // Longest Common Prefix/Suffix array

    // string str = "abbabb";
    // string str = "aaabaaaac";
    string str = "abacabad";

    // do not do this
    KMP_Agorithm_one(str);
    // Time Complexity -> O(n^3)
    // Space Complexity -> O(n)

    // do this one only
    cout<<endl;
    KMP_Agorithm_two(str);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)


    return  0;
}