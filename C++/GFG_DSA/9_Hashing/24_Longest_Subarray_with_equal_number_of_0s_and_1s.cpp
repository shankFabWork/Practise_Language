// I/P->
// int arr[] = {1,0,1,1,1,0,0};
// O/P->
// 6

// I/P->
// int arr[] = {1,1,1,1};
// O/P->
// 0

// I/P->
// int arr[] = {0,0,1,1,1,1,1,0};
// O/P->
// 4

// I/P->
// int arr[] = {0,0,1,0,1,1};
// O/P->
// 6

#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

int Longest_Subarray_with_equal_number_of_0s_and_1s_one(int arr[],int n)
{
    int res = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int nz = 0;
        int no = 0;
        for(int j=i;j<n;j++)
        {
            if(arr[j] == 0)
            {
                no++;
            }
            if(arr[j] == 1)
            {
                nz++;
            }
            if(nz == no)
            {
                res = max(res,no+nz);
            }
        }
    }
    return res;
}

int Longest_Subarray_with_equal_number_of_0s_and_1s_two(int arr[],int n)
{
    int new_arr[n];
    for(int i=0;i<n;i++)
    {
        new_arr[i] = (arr[i] == 0)?-1:1;
    }
    int sum = 0;
    int maxLen = 0;
    unordered_map <int,int> um;
    for(int i=0;i<n;i++)
    {
        sum += new_arr[i];

        if(sum == 0)
        {
            maxLen = i+1;
        }

        // just cram this part from
        // here
        if(um.find(sum+n) != um.end() )
        {
            if(maxLen < i-um[sum+n])
            {
                maxLen = i-um[sum+n];
            }
        }
        else
        {
            um[sum+n] = i;
        }
        // to here
    }
    return maxLen;
}

int main()
{
    int arr[] = {1,1,1,0,1,0};
    int n=sizeof(arr)/sizeof(int);

    cout<<Longest_Subarray_with_equal_number_of_0s_and_1s_one(arr,n);

    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)

    cout<<endl;
    cout<<Longest_Subarray_with_equal_number_of_0s_and_1s_two(arr,n);

    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)


    return 0;
}


