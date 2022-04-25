// I/P ->
// arr1[] = {0,1,0,0,0,0}
// arr2[] = {1,0,1,0,0,1}
// O/P ->
// 4

// I/P ->
// arr1[] = {0,1,0,1,1,1,1}
// arr2[] = {1,1,1,1,1,0,1}
// O/P ->
// 6

// I/P ->
// arr1[] = {0,0,0}
// arr2[] = {1,1,1}
// O/P ->
// 0

// I/P ->
// arr1[] = {0,0,1,0}
// arr2[] = {1,1,1,1}
// O/P ->
// 1

#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

int Longest_same_sum_in_binary_array_two(int arr1[],int arr2[],int n1,int n2)
{

    int new_arr[n1];
    for(int i=0;i<n1;i++)
    {
        new_arr[i] = arr1[i] - arr2[i]; 
    }
    int sum = 0;
    int maxLen = 0;
    unordered_map <int,int> um;
    for(int i=0;i<n1;i++)
    {
        sum += new_arr[i];
        if(sum == 0)
        {
            maxLen = i+1;
        }

        // just cram this part from
        // here
        if(um.find(sum) != um.end())
        {
            maxLen = max(maxLen,i-um[sum]);
        }
        else
        {
            um[sum] = i;
        }
        // to here
    }
    return maxLen;
}

int Longest_same_sum_in_binary_array_one(int arr1[],int arr2[],int n1,int n2)
{
    int res = INT_MIN;
    for(int i=0;i<n1;i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int j=i;j<n2;j++)
        {
            sum1 += arr1[j];
            sum2 += arr2[j];
            if(sum1 == sum2)
            {   
                res = max(res,j-i+1);
            }
        }
    }
    return res;
}

// We have to find two 
// binary subrray of same size
int main()
{
    // int arr1[] = {0,1,0,1,1,1,1};
    // int arr2[] = {1,1,1,1,1,0,1};

    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};

    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    cout<<Longest_same_sum_in_binary_array_one(arr1,arr2,n1,n2);
    //Time Complexity -> 
    //Space Complexity ->

    cout<<endl;
    cout<<Longest_same_sum_in_binary_array_two(arr1,arr2,n1,n2);
    //Time Complexity -> 
    //Space Complexity ->

    return 0;
}


