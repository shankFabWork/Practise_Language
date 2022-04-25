#include <iostream>
#include <climits>

using namespace std;

// I/P
// geeksforgeeks
// O/P
// 0 <-index    
// although "ee" is not left most occurance
// "g" is left most element occuring two times

// I/P
// abbcc
// O/P
// 1

// I/P
// abccb
// O/P
// 1


// I/P
// abcd
// O/P
// -1

// naive approach
void Leftmost_Repeating_Character_one(string str)
{
    for(int i=0;i<str.length();i++)
    {
        for(int j=i+1;j<str.length();j++)
        {
            if(str[i] == str[j])
            {
                cout<<"index-> "<<i<<" char-> "<<str[i];
                return;
            }
        }
    }
}


const int CHAR = 256;
// effiecient approach
void Leftmost_Repeating_Character_two(string str)
{
    // O(CHAR)
    int count[CHAR] = {0};

    // O(n)
    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }

    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]] > 1)
        {
            cout<<"index-> "<<i<<" char-> "<<str[i];
            break;
        }
    }
}


void Leftmost_Repeating_Character_three(string str)
{
    int n = str.length();
    int res = INT_MAX;
    const int CHAR = 256;
    int count[CHAR];
    // O(CHAR)  
    fill(count,count+CHAR,-1);
    int i;
    // O(n)
    for(i=0;i<n;i++)
    {
        if(count[str[i]] == -1)
        {
            count[str[i]] = i;
        }
        else
        {
            res = min(res,count[str[i]]);
        }
    }
    if(res == INT_MAX)
    {
        cout<<"no repeated value";
    }
    else
    {
        cout<<str[res]<<" "<<res<<endl;
    }
}


// more effiecient approach
void Leftmost_Repeating_Character_four(string str)
{
    bool visited[CHAR];

    // O(CHAR)
    fill(visited,visited+CHAR,false);
    int res = -1;

    // O(n)
    for(int i=str.length()-1;i>=0;i--)
    {
        if(visited[str[i]])
        {
            res = i;
        }
        else
        {
            visited[str[i]] = true;
        }
    }
    cout<<"index-> "<<res<<" char-> "<<str[res];
}

int main()
{
//     string str = "cabbad";
//     string str = "abbcc";
    string str = "geeksforgeeks";

    // do only 1st 2nd and 4th

    Leftmost_Repeating_Character_one(str);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    cout<<endl;

    Leftmost_Repeating_Character_two(str);
    // but in this case two loops are running
    // although Time Complexity of below 
    // algo is same as the above
    // Time Complexity -> O(CHAR + n)
    // Space Complexity -> O(CHAR)

    cout<<endl;

    // Do not do that
    Leftmost_Repeating_Character_three(str);
    // Time Complexity -> O(CHAR + n)
    // Space Complexity -> O(CHAR)


    cout<<endl;


    // in this we are using boolean array
    // previously we were using integer array
    // boolean array saves some space
    Leftmost_Repeating_Character_four(str);
    // Time Complexity -> O(CHAR + n)
    // Space Complexity -> O(CHAR)

    return 0;
}