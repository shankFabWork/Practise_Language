#include <iostream>

using namespace std;

// I/P->
// x=4
// O/P->
// 2

// I/P->
// x=14
// O/P->
// 3

// I/P->
// x=25
// O/P->
// 5

int sqrtRoot_one(int x)
{
    int i=1;
    while(i*i <= x)
    {
        i++;
    }
    return (i-1);
}

// using binary search
int sqrtRoot_two(int x)
{
    int low = 0;
    int high = x;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int mySqrt = (mid * mid);
        if(mySqrt == x)
        {
            return mid;
        }
        else if(mySqrt > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
} 

int main()
{
    // cout<<sqrtRoot_one(9);
    cout<<sqrtRoot_one(16);
    //Time Complexity -> O(root(x))
    //Space Complexity -> O(1)

    cout<<sqrtRoot_two(9);
    // cout<<sqrtRoot_two(16);
    //Time Complexity -> O(log(x))
    //Space Complexity -> O(1)

    return 0;
}



