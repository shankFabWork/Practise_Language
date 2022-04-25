#include <iostream>

using namespace std;

// nth number in fibonacchi series
int fib(int n)
{   
    // if(n == 0)
    // {
    //     return n;
    // }
    
    // if(n == 1)
    // {
    //     return n;
    // }

    if(n <= 1)
    {
        return n;
    }

    return fib(n-1)+fib(n-2);
}

int main()
{
    cout<<fib(5)<<" ";


    return 0;
}