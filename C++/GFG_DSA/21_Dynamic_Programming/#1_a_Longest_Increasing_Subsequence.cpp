// 1) Minimum deletions to make the array sorted

// I/P
// int arr[] = {5,10,3,6,7,8}
// O/P
// 2
// 1 2 1 2 3 4
// max = 4
// n=6
// n-max = 6-4 = 2

// I/P
// int arr[] = {5,10,3,6,7,8}
// O/P
// 2

// I/P
// int arr[] = {5,10,3,6,7,8}
// O/P
// 2

// n - Longest_Increasing_Subsequence(arr,n)


#include <bits/stdc++.h>

using namespace std;

int ceilIdx(int tail[], int l, int r, int key) 
{ 
    while (r > l) 
    {         
        int m = l + (r - l) / 2; 
        if (tail[m] >= key) 
        {
            r = m; 
        }
        else
        {
            l = m+1; 
        }
    } 

    return r; 
} 

int Longest_Increasing_Subsequence(int arr[],int n)
{
    int lis[n];
    lis[0] = arr[0];
    int l = 1;
    for(int i=1;i<n;i++)
    {
        if(lis[l-1] < arr[i])
        {
            lis[l] = arr[i];
            l++;
        }
        else
        {
            int index = ceilIdx(lis,0,n-1,arr[i]);
            lis[index] = arr[i];  
        }
    }
    return l;
}

int main()
{
    int arr[] = {5,10,3,6,7,8};
    int n =sizeof(arr)/sizeof(arr[0]);

    int ans = n - Longest_Increasing_Subsequence(arr,n);
    cout<<ans;
}