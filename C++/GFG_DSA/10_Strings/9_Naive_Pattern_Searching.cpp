// => Overview_of_Pattern_Searching

// txt = "GEEKSFORGEEKS";
// pattern = "EKS"
// o/p
// 2 10

// txt = "AAAAA";
// pattern = "AAA"
// o/p
// 0 1 2

// txt = "ABCABCD";
// pattern = "ABD"
// o/p
// Pattern not present

#include <iostream>

using namespace std;

// => Naive Approach
// works whether the string in the pattern
// is distict or not
// => improved Naive Approach
// works only if string pattern
// is distict
// works in linear time complexity

// => following algorithm 
// is better than naive based algorithm ->
// 1) Rabin Karp
// 2) KMP (Knuth Morris Algorithm)

void Pattern_Searching_one(string txt,string pattern)
{
    // string txt = "AAAAA";
    // string pattern = "AAA";
    // n = 5
    // m = 3
    // loop should ends at 2 (n-m)


    int n = txt.length();
    int m = pattern.length();
    // loop will run n-m+1
    for(int i=0;i<=n-m;i++)
    {
        // task will run n-m
        int j;
        for(j=0;j<m;j++)
        {
            if(txt[i+j] != pattern[j])
            {
                break;
            }
        }
        
        if(j == m)
        {
            cout<<i<<" ";
        }

    }
}

int main()
{
    string txt = "GEEKSFORGEEKS";
    string pattern = "EKS";

    // string txt = "AAAAA";
    // string pattern = "AAA";

    // string txt = "ABCABCD";
    // string pattern = "ABD";

    // "m" is pattern length
    // "n" is sting length

    Pattern_Searching_one(txt,pattern);
    // Time Complexity -> O( (n-m+1)*m )
    // Space Complexity -> O(1)
    
    // in worst case when all elements are distict
    // O(n)
    // we nedd to improve it

    return 0;
}

// for(int i=0;i<n;i++)
// loop will run n+1
// {
    // task
    // task will run n
// }