#include <iostream>
#include <math.h>

// This video introduces us to the basic 
// mathematical topics that will come in 
// handy in solving programming problems. 
// Below mentioned are the topics that we 
// will be learning about:

// Finding the number of digits in a number.
// Arithmetic and Geometric Progressions.
// Quadratic Equations.
// Mean and Median.
// Prime Numbers.
// LCM and HCF
// Factorials
// Permutations and Combinations
// Modular Arithmetic

using namespace std;

int count_digit_1(int n)
{
    if(n == 0)
    {
        return 0; 
    }
    return 1+count_digit_1(n/10);
}

int count_digit_2(int n)
{
    int count=0;
    while(n)
    {
        if(n == 0)
        {
            return count;
        }
        ++count;
        n=n/10;
    }
    return count;
}

int count_digit_3(long n)
{
    return floor(log10(n)+1);
}

int main()
{
    // counting digits
    int no=123432;
    cout<<count_digit_1(no);
    // Time Complexity -> O(d)
    // "d" is the number of digit
    // Space Complexity -> O(1)
    cout<<count_digit_2(no);
    cout<<count_digit_3(no);

    // do it yourself
    // it is easy
    // 1) arthimetic and geometric progressions
    // 2,4,8,16,32
    // 2) Quadratic Equations.
    // a*x^2 + b*x + c
    // D = -b (+-) b^2 -4*a*c
    //     ------------------
    //             2*a
    // 3) // Mean and Median.
    // 4) Prime Numbers.
    // 5) LCM and HCF
    // LCM (least common multiple ) 
    // 4 and 6 -> 12
    // HCF -> (highest common factor)
    // 12 and 16 -> 4s
    // 6) Factorials
    // 7) Permutations and Combinations
    // (i) Permutations
    // n
    //  P -> (n!) / (n-r)!
    //   r
    // (ii) Combinations
    // n
    //  C -> (n!) / ( r! * (n-r)! )
    //   r
    // 8) Modular Arithmetic (%)
    // 7%2 = 1
    // 17%3 = 2


    return 0;
}