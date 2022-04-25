#include <bits/stdc++.h>

using namespace std;

int main()
{
            int arr[] = {2, 2};
            int n = sizeof(arr)/sizeof(arr[0]);
            int x = 0;
            for(int i=0;i<n;i++)
            {
                x = x^arr[i];
            }
            for(int i=1;i<=n;i++)
            {
                x = x^i;
            }
            int a = 0;
            int b = 0;
            int rsb = x & -x;
            for(int i=0;i<n;i++)
            {
                if(rsb & arr[i])
                {
                    a = a^arr[i];
                }
                else
                {
                    b = b^arr[i];
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(rsb & i)
                {
                    a = a^i;
                }
                else
                {
                    b = b^i;
                }
            }
            int *return_arr = new int[2];
            for(int i=0;i<n;i++)
            {
                if(arr[i] == a)
                {
                    return_arr[0] = a;
                    return_arr[1] = b;
                    break;
                }
                else if(arr[i] == b)
                {
                    return_arr[0] = b;
                    return_arr[1] = a;
                    break;
                }
            }    
 
            for(int i=0;i<2;i++)
            {
                cout<<return_arr[i]<<" ";
            }
}