// I/P
// ab cd ef
// O/P
// ef cd ab

// I/P
// abc bcd ef
// O/P
// ef bc abc

// abc bcd ef
// reverse each word
// cba dcb fe
// reverse whole string
// ef bcd abc

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void Reverse_words_in_a_string_one(char str[],int n)
{
    stack <string> s;
    string temp = "";
    for(int i=0;i<=n;i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            s.push(temp);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    while(s.empty() != true)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main()
{
    char str[] = "welcome to gfg";
    int n = strlen(str);

    // naive approach
    Reverse_words_in_a_string_one(str,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    // because stack storing character has 
    // total charater as n
    cout<<endl;


    return 0;
}