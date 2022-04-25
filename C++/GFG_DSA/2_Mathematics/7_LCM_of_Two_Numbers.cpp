#include <iostream>

using namespace std;

int lcm_no_1(int no1,int no2)
{
    int res=max(no1,no2);
    while(1)
    {
        if(res%no1 == 0 && res % no2 == 0)
        {
            return res;
        }
        res++;
    }
}

int gcd(int no1,int no2)
{
    if(no2 == 0)
    {
        return no1;
    }
    else
    {
        return gcd(no2,no1%no2);
    }
}

int lcm_no_2(int no1,int no2)
{
    // (a*b)/lcm(a,b)
    int lcm_no=(no1*no2)/gcd(no1,no2);
    return lcm_no;
}

int main()
{
    // int no1=3,no2=5;
    // int no1=30,no2=45;
    // int no1=15,no2=12;
    int no1=100,no2=50;

    // int lcm=lcm_no_1(no1,no2);
    // Time Complexity -> O(a*b - max(a,b))
    
    // cout<<gcd(30,45);
    int lcm=lcm_no_2(no1,no2);
    // Time Complexity -> O(log(min(a,b)))
    cout<<lcm;

    return 0;
}