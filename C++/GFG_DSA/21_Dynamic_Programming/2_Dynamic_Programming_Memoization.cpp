#include <iostream>
#include <cstring>

using namespace std;

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int memo[100];
int fib_memo(int n)
{
    int res;
    if(memo[n] == -1)
    {
        if(n == 0 || n == 1)
        {
            res = n;
        }
        else
        {
            res = fib_memo(n-1) + fib_memo(n-2);
        }
        memo[n] = res;
    }
    return memo[n];
}

int main()
{
    int n = 5;
    cout<<fib(5)<<" ";
    cout<<endl;
    // #include <cstring>
    fill(memo,memo+n+1,-1);
    cout<<fib_memo(5)<<" ";
    // Time Complexity -> O(n)
    // Auxilary Space -> O(n)
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<memo[i]<<" ";
    }

    return 0;
}