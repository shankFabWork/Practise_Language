#include <iostream>

using namespace std;

// I/P
// n = 5
// O/P
// 1
// Explaination
// 1*2*3*4*5 = 120
// 1 zero in 120

// I/P
// n = 10
// O/P
// 1
// Explaination
// 10! = 3628800
// 2 zero in 3628800

// I/P
// n = 100
// O/P
// 24
// Explaination
// 100! = 9.332622e+157
// 24 zero in 9.332622e+157

int trailing_zeros_one(int n)
{
    int fact = 1;
    for(int i=1;i<=n;i++)
    {
        fact = fact * i;
    }
    int res = 0;
    while(fact % 10 == 0)
    {
        res++;
        fact = fact/10;
    }
    return res;
}

int trailing_zeros_two(int n)
{
    int res = 0;
    for(int i=5;i<=n;i=i*5)
    {
        res = res + n/i;
    }
    return res;
}

int main()
{
    // int no=12;
    int no=5;

    cout<<endl<<"no of trailing zeros are "<<endl;
    cout<<trailing_zeros_one(no)<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    cout<<trailing_zeros_two(no)<<endl;
    // Time Complexity -> O(log(n))
    // Space Complexity -> O(1)

    return 0;
}