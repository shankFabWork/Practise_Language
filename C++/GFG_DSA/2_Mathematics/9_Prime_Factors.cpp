#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    int counter=1;
    for(int i=2;i<n;i++)
    {
        if(n % i == 0)
        {
            counter = 0;
            break;
        }
    }

    if(counter == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void efficientPrimeFactor(int n)  // at last -> n^2.log(n)
{
    if(n <= 1)
    {
        return;
    }

    for(int i=2;i<=sqrt(n);i++)  //O(n)
    {
        if(isPrime(i))  //O(n)
        {
            while(n % i == 0)   //O(log(n))
            {
                cout<<(i)<<" ";
                 n = n/i;
            }
        }
    }    
    
    if(n > 1)
    {
        cout<<n;
    }
}


void optimizedEfficientPrimeFactor(int n)  
{
    if(n <= 1)
    {
        return;
    }
    while(n % 2 == 0)
    {
        cout<<2<<" ";
        n=n/2;
    }
    
    while(n % 3 == 0)
    {
        cout<<3<<" ";
        n=n/3;
    }

    int i;
    for(i=5;i<sqrt(n);i=+6)
    //O(sqrt(n))
    {
        while(n % i == 0)
        {
            cout<<i<<" ";
            n=n/i;
        }
        
        while(n % (i+2) == 0)
        {
            cout<<(i+2)<<" ";
            n=n/(i+2);
        }
    }

    if(n > 3)
    {
        cout<<n;
    }
}


int main()
{

    // int n=12;
    // int n=13;
    // int n=315;
    int n=40;

    efficientPrimeFactor(n);
    cout<<endl;
    //  O( n^2.log(n) )
    optimizedEfficientPrimeFactor(n);  
    //O(sqrt(n))

    // Number :: 
    // 40
    // Prime Factors
    // 2 2 2 5
    // Divisors of a number
    // 1 2 4 5 8 10 20 40

    return 0;
}