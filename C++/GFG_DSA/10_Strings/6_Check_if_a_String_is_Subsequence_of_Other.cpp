// => Subsequence :
// ordered
// not contiguous

// => subarray , substring :
// contiguous

#include <iostream>

using namespace std;

// iterative solution
bool isSubstring1(string str1,string str2,int n,int m)
{
    int j=0;
    for(int i=0;i<str1.length() && j < str2.length();i++)
    {
        if(str1[i] == str2[j])
        {
            j++;
        }
    }
    if(j == str2.length())
    {
        cout<<str2<<" is a substring of "<<str1;
        return 1;
    }
    else
    {
        cout<<str2<<" is not a substring of "<<str1;
        return 0;
    }
}

// recursive solution
bool isSubstring2(string str1,string str2,int n,int m)
{
    if(m == 0)
    {
        return true;
    }
    if(n == 0)
    {
        return false;
    }
    if(str1[n-1] == str2[m-1])
    {
        return isSubstring2(str1,str2,n-1,m-1);
    }
    return isSubstring2(str1,str2,n-1,m);
}

int main()
{

    // string str1 = "ABCD";    
    // string str2 = "AD";    
    string str1 = "ABCD";    
    string str2 = "ADC";

    int n = str1.length();
    int m = str2.length();
    

    // Iterative Solution
    cout<<isSubstring1(str1,str2,n,m);
    // TC - O(m+n)
    // SC - O(1)
    
    // Recursive Solution
    cout<<isSubstring2(str1,str2,n,m);
    // TC - O(m+n)
    // SC - O(m+n)
}