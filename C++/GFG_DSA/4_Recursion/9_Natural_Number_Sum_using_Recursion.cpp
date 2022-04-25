#include <iostream>

using namespace std;

int sum_using_recursion(int n)
{
    if(n == 0)
    {
        return n;
    }

    return n+sum_using_recursion(n-1);
}

int main()
{
    cout<<sum_using_recursion(4);

    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    return 0;
}