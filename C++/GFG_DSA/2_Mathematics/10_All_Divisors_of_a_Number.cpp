#include <iostream>
#include <math.h>

using namespace std;

// I/P
// n = 15
// O/P
// 1 3 5 15

//  Sieve of Eratosthenes
// All divisors of a Number

void naive_baise(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(n % i == 0)
        {
            cout<<i<<" ";
        }
    }
}

void efficientSolution(int n)   
{
    for(int i=1;i*i <= n;i++)
    {
        if( n % i == 0)
        {
            cout<<i<<" ";
            if( n/i != i )
            // 5 != 25/5
            // works in perfect sqaure
            // 25 or 36 or 49
            {
                cout<<(n/i)<<" ";
            }
        }
    }
}

void optimizedEfficientSolution(int n)
{
    int i=1;
    int j=n;

    for(int i=1;i<=sqrt(n);i++)
    // for(int i=1;i*i<=(n);i++)
    {
        if(n % i == 0 )
        {
            cout<<i<<" ";
        }
    }

    for(;i>=1;i--)
    // for(int i=sqrt(n);i>=1;i--)
    {
        if( n%i == 0 && n%i != i)
        {
            cout<<(n/i)<<" ";
        }
    }

}

int main()
{

    // int n=40;
    int n=25;
    // naive_baise(n);
    // O(n)

    // efficientSolution(n);
    // [Not in sorted Order]
    // O( sqrt(N) ) 
    // 1 40 2 20 4 10 5 8  
    // 1 2 4 5 8 10 20 40

    optimizedEfficientSolution(n);
    // [in sorted Order]
    //Time Complexity -> O(sqrt(N))+O(sqrt(N)) = O(sqrt(N))
    //Space Complexity -> O(1)
    
    return 0;
}