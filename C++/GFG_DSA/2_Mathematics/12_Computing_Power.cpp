#include <iostream>

using namespace std;

// I/P
// x = 2,n = 3
// O/P
// 8

// I/P
// x = 3,n = 4
// O/P
// 81

// I/P
// x = 5,n = 0
// O/P
// 1

// I/P
// x = 5,n = 1
// O/P
// 5

//not efficient
int power_one(int x,int n)
{
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res*=x;
    }
    return res;
}


//efficient
int power_two(int x,int n)
{
    if(n == 0)
    {
        return 1;
    }

    int temp=power_two(x,n/2);
    temp=temp*temp;

    if(n%2 == 0)
    {
        return temp;
    }
    else
    {
        return temp*x;
    }
}

int main()
{
    // cout<<power_one(2,3);  
    // Time Complexity -> O(N)
    //Space Complexity -> O(1)

    int x = 2;
    int n = 3;
    cout<<power_two(x,n);  
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(log(n))
    // in recursion will take value 
    // in the call stack


    return 0;
}