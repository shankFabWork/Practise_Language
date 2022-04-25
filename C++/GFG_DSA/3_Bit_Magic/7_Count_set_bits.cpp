#include <iostream>

using namespace std;


//naive method
int count_Set_bit(int n)
{
    int res=0;
    while(n)
    {
        // if( n % 2 != 0 )
        if( (n & 1) != 0 )
        {
            res=res+1;
        }
        // n=n/2;
        n=n >> 1;
    }

    return res;
}


// Implementation of Brian Kernighan’s Algorithm:

// Brain Kernighan's Algorithm
int brain_kernighan_algorithm(int n)
{
    int res=0;
    while(n > 0)
    {
        n=n&(n-1);
        ++res;
    }
    return res;
}


// 0 to 2^8 -1
int table[256];

// recursive function to count set bits 
void initialize() 
{ 
    // To initially generate the table algorithmically:
    table[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
    }
} 

int countSetBits(int n)
{
    // 0xff -> taking last 8 bit 
    return table[n & 0xff] + 
    table[(n >> 8) & 0xff] + 
    table[(n >> 16) & 0xff] + 
    table[n >> 24]; 
}


int main()
{
    int n=20;
    cout<<n<<" contains "<<count_Set_bit(n)<<" bits";
    // Time Complexity: O(total bits) 
    // Space Complexity: O(1)    

    // cout<<n<<" contains "<<brain_kernighan_algorithm(n)<<" bits";
    // Time Complexity: O(set bit count)
    // 1011 -> 3 set bit 
    // Space Complexity: O(1) 

    // not too much important
    // initialize();
    // cout<<n<<" contains "<<countSetBits(n)<<" bits";
    // Time Complexity: O(1) 
    // Space Complexity: O(256) -> O(1)

    return 0;
}