// Given a string of parenthesis
// (     {, }, (, ), [ and ]    ) 
// we need to check if this string is 
// balanced or not.

// I/P
// s = "([])"
// O/P
// yes

// I/P
// s = "((())"
// O/P
// no

// I/P
// s = "[{]}"
// O/P
// no

// I/P
// s = "{}[()]"
// O/P
// yes

#include <iostream>
#include <stack>

using namespace std;

bool is_matching(char ch1,char ch2)
{
    return (
                (ch1 == '(' && ch2 == ')') ||
                (ch1 == '[' && ch2 == ']') ||
                (ch1 == '{' && ch2 == '}') 
            );  
}

bool Balanced_Parenthesis(string str)
{
    stack <char> s;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty() == true)
            {
                return false;
            }
            else if(is_matching(s.top(),str[i]) == false)
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty() == true);
}

int main()
{   
    string str = "([])";
    // string str = "((())";
    // string str = "[{]}";
    // string str = "{}[()]";

    if(Balanced_Parenthesis(str))
    {
        cout<<endl;
        cout<<"Parenthesis is balanced";
        cout<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Parenthesis is not balanced";
        cout<<endl;
    }
    return 0;
}