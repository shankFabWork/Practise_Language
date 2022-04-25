#include <iostream>

using namespace std;

int fib_dynamic_programming(int n)
{
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++)
    {
        fib[i] = fib[i-1] + fib[i-2]; 
    }
    return fib[n];
}

int main()
{
    int n = 5;
    cout<<fib_dynamic_programming(n);
    // Time Complexity -> O(n)
    // Auxilary Space -> O(n)

    return 0;
}