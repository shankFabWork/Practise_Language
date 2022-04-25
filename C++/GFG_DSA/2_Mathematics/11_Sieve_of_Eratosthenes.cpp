#include <iostream>
#include <math.h>

using namespace std;


// Sieve_of_Eratosthenes :: 
// we are given a number 
// we need to find all the prime number 
// that is less than or equal to
// that number 

// I/P
// n = 10
// O/P
// 2 3 5 7

// I/P
// n = 23
// O/P
// 2 3 5 7 9 11 13 17 19 23

bool isPrime(int n)
{   
    int counter = 0;
    for(int i=2;i<=sqrt(n);i++)  // O( sqrt(n) )
    {
        if(n % i ==0)
        {
            counter+=1;
        }
    }
    if(counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void naive_approch(int n)    // O(n) )
{
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))  // O( sqrt(n) )
        {
            cout<<i<<" ";
        }
    }
}

void Sieve_Of_Eratosyhenes(int n)
{
    if(n <= 1) return ;
    bool isBool[n+1];
    fill(isBool,isBool+n+1,true);

    // for(int i=2;i<=sqrt(n);i++)
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime(i))
        {
            for(int j=2*i;j<=n;j+=i)
            {
                isBool[j] = false;
            }
        }   
    }

    for(int i=2;i<=n;i++)
    {
        cout<<isBool[i]<<" ";   
    }  

    cout<<endl;
    
    for(int i=2;i<=n;i++)
    {
        cout<<i<<" ";   
    }  

    cout<<endl;

    for(int i=2;i<=n;i++)
    {
        if(isBool[i] == true)
        {
            cout<<i<<" ";
        }
    }  
}

void optimized_Sieve_Of_Eratosyhenes(int n)
{
    if(n <= 1) return ;
    bool isBool[n+1];
    fill(isBool,isBool+n+1,true);

    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
            for(int j=i*i;j<=n;j+=i)
            {
                isBool[j] = false;
            }
        }
    }

}


int main()
{

    // given a number 'n' we need to find out all the prime number 
    // smaller than or equal to 'n'

    // Naive Approch
    int n=10;
    // int n=23;
    naive_approch(n);  
    // O( n.sqrt(n) )

    //fill is a method in c++ 
    // which is used fill an array with ap particular value
    int size=10;
    int arr[size];
    fill(arr,arr+size,0);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Sieve_Of_Eratosyhenes(n);
    // O( N.log(N).log(N) )  

    cout<<endl;
    
    optimized_Sieve_Of_Eratosyhenes(n);
    // O( N.log(N).log(N) )

    return 0;
}