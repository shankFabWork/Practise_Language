// anagram ::
// a word that is made by arranging 
// the letters of another word 
// or
// permutaition is present in the another string

// I/P
// txt = "geeksforgeeks";
// pat1 = "frog";
// O/P
// yes


// I/P
// txt = "geeksforgeeks";
// pat1 = "rseek";
// O/P
// no


// txt = "geeksforgeeks";
// pat1 = "frog";

//txt
// 0
// geek
// e f g k o r s
// 2   1 1
// 1
// eeks
// e f g k o r s
// 2     1     1 
// 2
// eksf
// e f g k o r s
// 1 1   1     1
// 3
// ksfo
// e f g k o r s
//   1   1 1    1
// 4
// sfor
// e f g k o r s
//   1     1 1 1 
// 5
// forg
// e f g k o r s
//   1 1   1 1 


// pattern =>
// frog
// e f g k o r s
//   1 1   1 1

#include <iostream>
#include <algorithm>

using namespace std;

const int CHAR = 256;

bool isAnagram(string txt,string pat,int start)
{
    int count[CHAR] = {0};
    for(int j=0;j<pat.length();j++)
    {
        count[txt[start+j]]++;
        count[pat[j]]--;
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

bool Anagram_Search_one(string txt,string pat)
{
    int n = txt.length();
    int m = pat.length();
    
    for(int i=0;i<=n-m;i++)
    {
        if(isAnagram(txt,pat,i) == true)
        {
            cout<<i<<endl;
            return true;
        }
    }
    return false;
}

bool areSame(int CT[],int CP[])
{
    for(int i=0;i<CHAR;i++)
    {
        if(CT[i] != CP[i])
        {
            return false;
        }
    }
    return true;
}

bool Anagram_Search_two(string txt,string pat)
{
    // CT - Count Of Text
    // CP - Count Of Pattern
    int CT[CHAR] = {0},CP[CHAR] = {0};
    for(int i=0;i<pat.length();i++)
    {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    int m = pat.length();
    for(int i=m;i<txt.length();i++)
    {
        if(areSame(CT,CP))
        {
            return true;
        }   
        CT[txt[i-m]]++;
        CT[txt[i]]++;
    }
    return false;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat1 = "geeks";
    string pat2 = "ksgee";
    string pat3 = "frog";

    // if(Anagram_Search_one(txt,pat3) == true)
    if(Anagram_Search_two(txt,pat2))
    {
        cout<<"Anagram found";
    }
    else
    {
        cout<<"Anagram not found";
    }
    // Time Complexity -> O((n-m+1)*m)
    // Space Complexity -> O(CHAR)

    // Time Complexity -> O( n*CHAR )
    // Space Complexity -> O(CHAR)


    return 0;
}