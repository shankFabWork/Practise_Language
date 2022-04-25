#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

// I/P
// n = 4
// O/P
// yes

// I/P
// n = 6
// O/P
// no

bool isPowOfTwo_1(int n)
{
    if(n == 0)
    {
        return false;
    }
 
    while( n != 1)  
    {
        if( n % 2 != 0)
        {
            return false;
        }
        n=n/2;
    }
    return true;
}

bool isPowOfTwo_2(int n)
{
    if( (n&(n-1)) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPowOfTwo_3(int n)
{
    return (n != 0) && ( (n & ( n-1 )) == 0);
}

bool isPowOfTwo_4(int n)
{
    return (ceil(log2(n))) == (floor(log2(n)));
}

int main()
{
    //naive (Method - 1 )

    cout<<isPowOfTwo_1(3);    
    // cout<<isPowOfTwo_1(8);
    cout<<endl;
    // Time Complexity: O(set bit) -> O(1) 
    // Space Complexity: O(1). 
   

    // cout<<isPowOfTwo_2(3);   
    cout<<isPowOfTwo_2(8);   
    cout<<endl;
    // Time Complexity: O(1) 
    // Space Complexity: O(1). 

    // cout<<isPowOfTwo_3(8);   
    cout<<isPowOfTwo_3(8);   
    cout<<endl;
    // Time Complexity: O(1) 
    // Space Complexity: O(1). 

    cout<<isPowOfTwo_4(3);   
    // cout<<isPowOfTwo_4(8);  
    cout<<endl;
    // Time Complexity: O(1) 
    // Space Complexity: O(1). 

    // Time Complexity -> O(log(n)) 
    // Spacw Complexity -> O(1) 

    return 0;
}