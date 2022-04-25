#include <bits/stdc++.h>

using namespace std;

void swap(char &a,char &b)
{
    char c;
    c = a;
    a = b;
    b = c;
}

void reverse(string &str,int low,int high)
{
    str = str+" ";
    while(low <= high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void Reverse_words_in_a_string_two(string &str)
{   
    int n = str.length();
    int start = 0;
    for(int end=0;end<n;end++)
    {
        // do not write " "
        // this is char
        if(str[end] == ' ') 
        {
            reverse(str,start,end-1);
            start = end + 1;
        }
    }
    reverse(str,start,n-1);
    reverse(str,0,n-1); 

    for(int i=0;i<n;i++)
    {
        cout<<str[i];
    }
}


int main()
{

    string str="welcome to gfg";
    Reverse_words_in_a_string_two(str);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
  

    return 0;
}