#include <iostream>
#include <limits.h>

using namespace std;

// I/P
// geeksforgeeks
// O/P
// 5
/// "f" is Leftmost Non-repeating Element

// I/P
// abcabc
// O/P
// -1
// no one
// every element is repeating

// I/P
// apple
// O/P
// 0
// "a"

int Leftmost_Non_repeating_Element_one(string str)
{
    for(int i=0;i<str.length();i++)
    {
        bool flag = false;
        for(int j=0;j<str.length();j++)
        {
            if(str[i] == str[j] && i != j)
            {
                flag = true;    
                break;
            }
        }
        if(flag == false)
        {
            return i;
        }
    }
    return -1;
}

int min_val(int a,int b)
{
    if(a > b)
    {
        return b;
    }
    return a;
}

// abbcbda
// i=0:count['a']= -2
// i=1:count['b']= -2
// i=2:count['b']= -2
// i=3:count['c']= 3   <--
// i=4:count['b']= -2
// i=5:count['d']= 5   <--
// i=6:count['a']= -2

const int CHAR = 256;
void Leftmost_Non_repeating_Element_two(string str)
{
    int res = INT_MAX;
    int count[CHAR];
    fill(count,count+CHAR,-1);
    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]] == -1)
        {
            count[str[i]] = i;
        }
        else
        {
            count[str[i]] = -2;
        }
    }
    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]] >= 0)
        {
            res = min(res,count[str[i]]);
        }
    }
    if(res == INT_MAX)
    {
        cout<<"all are repeating";
    }
    else
    {
        cout<<str[res]<<" "<<res;
    }
}


void Leftmost_Non_repeating_Element_three(string str)
{
    const int CHAR = 256;
    int count[CHAR];
    fill(count,count+CHAR,0);
    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]] == 1)
        {
            cout<<str[i]<<" "<<i<<endl;
            break;
        }
    }

}

int main()
{
    string str = "geeksforgeeks";

    cout<<Leftmost_Non_repeating_Element_one(str);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    cout<<endl;

    Leftmost_Non_repeating_Element_two(str);
    // Time Complexity -> O(n)
    // Space Complexity -> O(CHAR)

    cout<<endl;

    Leftmost_Non_repeating_Element_three(str);
    // Time Complexity -> O(n)
    // Space Complexity -> O(CHAR)

    return 0;
}