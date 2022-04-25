// I/P->
// int arr[] = {5,8,-4,-4,9,-2,2}; 
// int sum = 0;
// O/P->
// 3

// I/P->
// int arr[] = {3,1,0,1,8,2,3,6}; 
// int sum = 5;
// O/P->
// 4

// I/P->
// int arr[] = {8,3,7}; 
// int sum = 15;
// O/P->
// 0

#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

int Longest_subarray_with_given_sum_one(int arr[],int n,int sum)
{
    int presum;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        presum = 0;
        for(int j=i;j<n ;j++)
        {
            presum += arr[j];
            if(presum == sum)
            {
                res = max(res,j-i+1);
            }
        }
    }
    return res;
}

int Longest_subarray_with_given_sum_two(int arr[],int n,int sum)
{
    unordered_map <int,int> um;
    int prefix_sum = 0;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum == sum)
        {
            res = i + 1;
        }
        if( um.find(prefix_sum) == um.end())
        {
            um[prefix_sum] = i;
        }
        if( um.find(prefix_sum - sum) != um.end())
        {
            res = max(res,um[prefix_sum] - um[prefix_sum - sum]);
        }
    }
    return res;
}


int main()
{
    int arr[]={5,2,3,4};
    int sum = 5;
    int n=sizeof(arr)/sizeof(int);

    cout<<Longest_subarray_with_given_sum_one(arr,n,sum);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)
    cout<<endl;

    cout<<Longest_subarray_with_given_sum_two(arr,n,sum);
    //Time Complexity -> O(n) 
    //Space Complexity -> O(1)

    return 0;
}


