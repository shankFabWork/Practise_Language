//memoization

#include <iostream>
#include <cstring>

using namespace std;

int memo[100000];
int fib(int n)
{
    if(memo[n] == -1)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }
        else
        {
            int val = fib(n-1) + fib(n-2);
            memo[n] = val;
            return val;
        }
    }
    return memo[n];
}

int main()
{
    // int n = 4;
    int n = 5;
    memset(memo,-1,sizeof(memo));
    cout<<fib(n);


    return 0;
}