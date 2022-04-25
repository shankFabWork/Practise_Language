#include <iostream>

using namespace std;

// I/P
// n = 4
// O/P
// 24

// I/P
// n = 6
// O/P
// 720

// I/P
// n = 0
// O/P
// 1

int fact_no_1(int n)
{
    int res = 1;
    for(int i=1;i<=n;i++)
    {   
        res = res*i;
    }
    return res;
}

int fact_no_2(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n*fact_no_1(n-1);
}

int main()
{
    int no=4;

    // int res=fact_no_1(no);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    int res=fact_no_2(no);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)

    cout<<endl<<res<<endl;
    return 0;
}