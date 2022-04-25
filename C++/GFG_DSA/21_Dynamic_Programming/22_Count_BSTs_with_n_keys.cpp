// BST means every key should be unique
// Every key on the left side should 
// be smaller than the root
// Every key on the right side should 
// be greater than the root

// every output has structurally 
// different BST

// we need to find number of structures 
// that can be formed with the help of BST


// another way to solve the problem is 
// finding catalan number

//  1      2n
// ---  *    C
// (n+1)       n

#include <iostream>

using namespace std;

int Count_BSTs_with_n_keys_one(int n)
{
    int dp[n+1];
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j=0;j<i;j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int fact(int n)
{
    int num = 1;
    for(int i=1;i<=n;i++)
    {
        num = num * i;
    }
    return num;
}

float Count_BSTs_with_n_keys_two(int n)
{
    float a = (float)1/(n+1);
    float b = (float)fact(2*n)/( fact(n) * fact(n)  );
    float c = (float)a*b;
    return c;
}

int main()
{
    int n = 5;
    cout<<Count_BSTs_with_n_keys_one(n);
    // TC - O(n^2)
    // SC - O(n)
    cout<<endl;
    // this is the property of catalan problem
    // we can use catalan number
    cout<<(float)Count_BSTs_with_n_keys_two(n);
    // TC - O(1)
    // SC - O(1)
}