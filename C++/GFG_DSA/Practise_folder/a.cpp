#include <bits/stdc++.h>

using namespace std;

int hcf(int no1,int no2)
{
    while(no1 != no2)
    {
        if(no1 > no2)
        {
            no1 = no1 - no2;
        }
        else
        {
            no2 = no2 - no1;
        }
    }
    return no1;
}

int main()
{
    // int no1=7,no2=13;
    // int no1=10,no2=20;
    // int no1=4,no2=6;
    // int no1=100,no2=200;
    // int no1=100,no2=50;
    // cout<<(no1*no2)/hcf(no1,no2);

    // int n = 11;
    // bool a = 0;
    // for(int i=2;i<n;i++)
    // {
    //     if(n%i == 0)
    //     {
    //         a = 1;
    //         break;
    //     }
    // }
    // if(a != 1)
    // {
    //     cout<<"no is prime";
    // }
    // else
    // {
    //     cout<<"no is not prime";
    // }

    // int n=40;
    // int i = 2;

    // while(n != 0)
    // {
    //     while(n%i == 0)
    //     {
    //         n = n/i;
    //         cout<<i;
    //         if(n == 0)
    //         {
    //             break;
    //         }
    //     }
    //     if(n == 0)
    //     {
    //         break;
    //     }
    //     i++;
    // }

    // int n = 40;
    // int no = n;
    // while(n%2 == 0)
    // {
    //     cout<<2<<" ";
    //     n = n/2;
    // }
    // while(n%3 == 0)
    // {
    //     cout<<3<<" ";
    //     n = n/3;
    // }
    // for(int i=5;i<sqrt(no);i=i+6)
    // {
    //     while(n%i == 0)
    //     {
    //         cout<<i<<" ";
    //         n = n/i;
    //     }
    //     while(n % (i+2) == 0)
    //     {
    //         cout<<i+2<<" ";
    //         n = n/(i+2);
    //     }
    // }
    // if(n>3)
    // {
    //     cout<<n;
    // }
    // int n=29;
    // int no = n;
    // if(n >= 2)
    // {
    //     cout<<2<<" ";
    // }
    // if(n >= 3)
    // {
    //     cout<<3<<" ";
    // }
    // for(int i=5;i<no;i=i+6)
    // {
    //     cout<<i<<" "<<i+2<<" ";
    // }

    // int x = 4;
    // int n = 5;
    // int res = 1;
    // while(n > 0)
    // {
    //     if(n%2 != 0)
    //     {
    //         res =  res*x;
    //     }
    //     x = x*x;
    //     n = n/2;
    // }
    // cout<<res;

    // int n = 8;
    // int k = 3;
    // bool is_set = false;
    // for(int i=0;i<k;i++)
    // {
    //     if(i == k-1 && n%2 != 0)
    //     {
    //         is_set = true;
    //     }
    //     n = n/2;
    //     // n = n>>1;
    // }
    // if(is_set)
    // {
    //     cout<<endl<<k<<"th bit is set"<<endl;
    // }
    // else
    // {
    //     cout<<endl<<k<<"th bit is not set"<<endl;
    // }

    // int n = 16;
    // int k = 0;
    // while(n)
    // {
    //     if(n%2 != 0)
    //     {
    //         k++;
    //     }
    //     n = n/2;
    // }
    // cout<<k;

    // int n = 16;
    // int k = 0;
    // while(n)
    // {
    //     n = n & (n-1);
    //     k++;
    // }
    // cout<<k;
    
    // int arr[] = {1,4,3};
    // int n = sizeof(arr)/sizeof(int);
    // int res = 0;
    // for(int i=0;i<=n;i++)
    // {
    //     res = res^(i+1);
    // }

    // for(int i=0;i<n;i++)
    // {
    //     res = res^arr[i];
    // }
    // cout<<res;

    int n = 3;
    // int a = n&(~(n-1));
    // cout<<a;
    int a = 3;
    // int b = -3;
    // cout<<a&b;
    cout<<a&(~2);

}