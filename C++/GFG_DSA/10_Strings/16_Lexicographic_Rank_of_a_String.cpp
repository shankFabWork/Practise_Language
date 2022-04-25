// ABC - 1
// ACB - 2
// BCA - 3
// BAC - 4
// CAB - 5
// CBA - 6

// Lexicographic Rank

// I/P
// str = "BAC"
// O/P
// 3

// I/P
// str = "CBA"
// O/P
// 6

// I/P
// str = "DCBA"
// O/P
// 24

// I/P
// str = "STRING"
// O/P
// 598

// S T R I N G

// 256
// 0 0 0 ... 0
// G  I   N   R   S   T 
// 1  1   1   1   1   1 
// 1  2   3   4   5   6 
// =>S (RIGHT SIDE CHARACTER LESS THAN S ) -> RING
// 1  2   3   4 <-5   6 
// =>T (RIGHT SIDE CHARACTER LESS THAN T ) -> RING
// 1  2   3   4   4   <-5
// =>R (RIGHT SIDE CHARACTER LESS THAN R ) -> ING
// 1  2   3 <-3   3     3
// =>I (RIGHT SIDE CHARACTER LESS THAN I ) -> G
// 1 <-1   2   2   2    2
// =>G (RIGHT SIDE CHARACTER LESS THAN G ) -> G
// 0   0   1   1   1    1


#include <iostream>

using namespace std;

const int CHAR = 256;

int fact(int n)
{
    int val = 1;
    for(int i=1;i<=n;i++)
    {
        val = val * i;
    }
    return val;
}

int lex_rank(string str)
{
    // O(CHAR)
    int count[CHAR] = {0};
    int n = str.length();

    // O(n)
    for(int i=0;i<n;i++)
    {
        count[str[i]]++;
    }

    // O(CHAR)
    for(int i=1;i<CHAR;i++)
    {
        count[i] = count[i] + count[i-1];
    }
    int mul = fact(n);
    int res = 0;

    // O(n*CHAR)
    for(int i=0;i<n-1;i++)
    {
        mul = mul / (n - i);
        res += count[str[i] - 1]*mul;
        for(int j=str[i];j<CHAR;j++)
        {
            count[j]--;
        }
    }
    return res+1;
}

int main()
{   
    string str = "STRING";
    cout<<lex_rank(str); 
    // Time Complexity -> O( CHAR+n+CHAR+n*CHAR ) = O(n)
    // as in n*CHAR , CHAR is "constant"
    // Space Complexity -> O(CHAR)

    return 0;
}