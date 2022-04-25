
// 2) Maxmimum sum increasing subsequence

// I/P
// int arr[] = {3,20,4,6,7,30}
// O/P
// 53

// I/P
// int arr[] = {5,10,20}
// O/P
// 35

// I/P
// int arr[] = {20,10,5}
// O/P
// 20

#include <iostream>
#include <limits.h>
using namespace std;
int Maxmimum_sum_increasing_subsequence(int arr[],int n)
{
    int lis[n];
    lis[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        // lis[i] = 1;
        lis[i] = arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                // lis[i] = max(lis[i],lis[j]+1);
                lis[i] = max(lis[i],lis[j]+arr[i]);
            }
        }
    }

    // find maximum in lis array
    int max_elem = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max_elem < arr[i])
        {
            max_elem = arr[i];
        }
    }
    return max_elem;
}

int main()
{
    // int arr[] = {3,20,4,6,7,30};
    // int arr[] = {5,10,20};
    int arr[] = {20,10,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<Maxmimum_sum_increasing_subsequence(arr,n);
}
