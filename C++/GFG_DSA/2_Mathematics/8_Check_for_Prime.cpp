#include <iostream>
#include <math.h>

using namespace std;

bool Check_for_Prime_one(int n)
{
    int c = 0;
    for(int i=2;i*i<n;i++)
    {
        if(n % i == 0)
        {
            c++;
        }
    }
    if(c == 0)
    {
        return true;
    }
    return false;
}


bool Check_for_Prime_two(int n)
{
	if(n==1)
		return false;

	if(n==2 || n==3)
		return true;

	if(n%2==0 || n%3==0)    
		return false;

	for(int i=5; i*i<=n; i=i+6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false; 
	}

    // or
    // for (i = 2; i <= sqrt(n); i++) { 
    //     if (n % i == 0) { 
    //         flag = 0; 
    //         break; 
    //     } 
    // } 
  
    // if(n<=1) 
    // flag=0; 
    // else if(n==2) 
    // flag=1;  
  
    // if (flag == 1) 
    // { 
    //     printf("%d is a prime number", n); 
    // } 
    // else 
    // { 
    //     printf("%d is not a prime number", n); 
    // } 

	return true;
}


int main()
{
    int n=5;
    // int n=27;
    // int n=29;
    // int n=31;

    // if(Check_for_Prime_one)
    //O( n )
    if(Check_for_Prime_two)
    //O( Sqrt(n) )
    {
        cout<<n<<" is prime";
    }
    else
    {
        cout<<n<<" is not prime";
    }
   
    //40 ->  2,2,2,5
    //sqrt(40) -> 6
    // all prime factors of 40 are less than or equal to sqrt(40)

    //for(int i=2;i<n;i++)  
    //O(n)

    return 0;
}