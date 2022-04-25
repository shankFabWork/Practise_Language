#include <bits/stdc++.h>

using namespace std;

bool pair_in_unsorted_array_one(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}

bool pair_in_unsorted_array_two(int arr[],int n,int sum)
{
    unordered_set <int> us;
    // n
    for(int i=0;i<n;i++)
    {
        // log(n)
        if(us.find(sum-arr[i]) != us.end())
        {
            return true;
        }
        us.insert(arr[i]);
    }
    return false;
}

bool pair_in_sorted_array(int arr[],int n,int sum)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
        if(arr[l] + arr[r] == sum)
        {
            return true;
        }
        else if(arr[l] + arr[r] > sum)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return false;
}

bool triplet_in_an_array(int arr[],int n,int sum)
{
    // n.log(n)
    sort(arr,arr+n);

    // n^2
    // n
    for(int i=0;i<=n-3;i++)
    {
        int l = i+1;
        int r = n-1;
        // n
        while(l < r)
        {
            if(arr[i] + arr[l] + arr[r] == sum)
            {
                return true;
            }
            else if(arr[i] + arr[l] + arr[r] > sum)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return false;
}

int main()
{
    // int arr[] = {2, 3, 7, 8, 11};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int sum = 14;
    // cout<<pair_in_unsorted_array_one(arr,n,sum);
    // TC - O(n^2)
    // cout<<pair_in_unsorted_array_two(arr,n,sum);
    // TC - O(n.log(n))
    
    // int arr[] = { 1, 4, 45, 6, 10, 8 }; 
	// int sum = 16; 
	// int n = sizeof(arr) / sizeof(arr[0]); 
    // pair_in_sorted_array(arr,n,sum);
    // big-o(n)
    // theta(1)

    // int arr[] = { 1, 4, 45, 6, 10, 8 }; 
    // int sum = 22; 
	// int n = sizeof(arr) / sizeof(arr[0]); 
    // cout<<triplet_in_an_array(arr,n,sum);
    //  O(n*log(n)) + O(n^2)

    return 0;
}