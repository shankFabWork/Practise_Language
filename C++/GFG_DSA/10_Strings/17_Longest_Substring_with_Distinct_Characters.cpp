// I/P
// string str = "abcdabc"
// O/P
// 4
// -> abcd , bcda , cdab and dabc
// longest distinct substring has a length of 4

// I/P
// string str = "aaa"
// O/P
// 1


// I/P
// string str = ""
// O/P
// 0

// I/P
// string str = "abaacdbab"
// O/P
// 4
// -> acdb
// longest distinct substring has a length of 4

#include <iostream>
#include <vector>

using namespace std;

const int CHAR = 256;
bool isDistinct(string str,int i,int j)
{
    vector <bool> visited(CHAR);
    for(int k=i;k<=j;k++)
    {
        if(visited[str[k]] == true)
        {
            return false;
        }
        visited[str[k]] = true;
    }
    return true;
}

int max(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int Longest_Substring_with_Distinct_Characters_1(string str)
{
    int n = str.length();
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(isDistinct(str,i,j))
            {
                res = max(res,j-i+1);
            }
        }
    }
    return res;
}

int Longest_Substring_with_Distinct_Characters_2(string str)
{
    int n = str.length();
    int res = 0;
    for(int i=0;i<n;i++)
    {
        vector <bool> visited(CHAR);
        for(int j = i;j<n;j++)
        {
            if(visited[str[j]] == true)
            {
                break;
            }
            else
            {
                res = max(res,j-i+1);
                visited[str[i]] = true;
            }
        }
    }
    return res;
}

// cram it
int Longest_Substring_with_Distinct_Characters_3(string str) 
{ 
	int n = str.length(); 
	int res = 0;
	vector <int> prev(256,-1);
	int i=0;
	for (int j = 0; j < n; j++)
    {
	    i=max(i,prev[str[j]]+1);
	    int maxEnd=j-i+1;
	    res=max(res,maxEnd);
	    prev[str[j]]=j;
	} 
	return res; 
} 

int main()
{
    string str = "abac";
    // string str = "abcdabc";

    cout<<Longest_Substring_with_Distinct_Characters_1(str);
    // Time Complexity -> O(n^3)
    // Space Complexity -> O(CHAR)

    // cout<<Longest_Substring_with_Distinct_Characters_2(str);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(CHAR)

    // it is difficult 
    // but cram it as it is efficient solution
    cout<<Longest_Substring_with_Distinct_Characters_3(str);
    // Time Complexity -> O(n)
    // Space Complexity -> O(CHAR)

    return 0;
}