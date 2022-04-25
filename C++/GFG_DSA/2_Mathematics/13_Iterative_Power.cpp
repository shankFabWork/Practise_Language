// Iterative solution

// Time Complexity -> O(log(n))
//Space Complexity -> O(1)

// 3^10 = 3^8 * 3^2 -> 10 = 1010
// 3^19 = 3^16 * 3^2 * 3^1 -> 19 = 10011

// 1) Every Number can be written as sum 
// of powers of 2 
// (Set Bits i Binary Representation)

// 2) We can transverse through all bits of a number 
// (fron LSB to MSB) in O(log(n)) time

#include <iostream>

using namespace std;

// x = 2 , n =3
// x^n
// 2^3 = 8
int Iterative_Power(int x,int n)
{
    int res = 1;
    while(n > 0)
    {   
        // if(n & 1)
        if(n%2 != 0)
        {
            res = res*x;
        }
        x = x*x;
        // n = n/2;
        n = n>>1;
    }
    return res;
}

int main()
{
    // int x = 3,n = 10;
    // int x = 2,n = 3;
    int x = 8,n = 4;
    // (x)^n
    int val = Iterative_Power(x,n);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)
    cout<<val;

    return 0;
}