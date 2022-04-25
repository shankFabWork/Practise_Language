#include <iostream>

using namespace std;

void fun(int n)
{
    if(n == 0)
    {
        return;
    }
    fun(n-1);
    cout<<n<<" ";

    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
}

int main()
{
    fun(5);

    return 0;
}