#include <iostream>

using namespace std;

bool pallindrome_recursion(string &str,int start,int end)
{
    if(start >= end)
    {
        return true;       
    }
    return( (str[start]==str[end]) 
            && 
            pallindrome_recursion(str,start+1,end-1)
    );
}

int main() {

    string str="shsa";
    int start=0;
    int end=str.length();

    cout<<pallindrome_recursion(str,start,end-1);

    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    return 0;
}