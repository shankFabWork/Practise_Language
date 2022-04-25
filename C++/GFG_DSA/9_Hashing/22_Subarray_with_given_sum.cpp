// I/P->
// int arr[] = {5,8,6,13,3,-1};
// int sum = 22;
// O/P->
// true

// I/P->
// int arr[] = {15,2,8,10,-5,-8,6};
// int sum = 3;
// O/P->
// true

// I/P->
// int arr[] = {3,2,5,6};
// int sum = 10;
// O/P->
// true

#include <iostream>
#include <unordered_set>

using namespace std;

bool Subarray_with_given_sum_one(int arr[],int n,int sum)
{
    bool sum_matches = false;
    for(int i=0;i<n;i++)
    {
        int curr_sum = 0;
        for(int j=i;j<n;j++)
        {
            curr_sum += arr[j];
            if(curr_sum == sum)
            {
                sum_matches = true;
            }
        }
    }
    return sum_matches;
}

bool Subarray_with_given_sum_two(int arr[],int n,int sum)
{
    bool sum_matches = false;
    int pre_sum = 0;
    unordered_set <int> us;
    for(int i=0;i<n;i++)
    {
        pre_sum += arr[i];
        if(pre_sum == sum)
        {
            sum_matches = true;
        }
        if( us.find(pre_sum - sum) == us.end() )
        {
            sum_matches = true;
        }
        us.insert(pre_sum);
    }
    return sum_matches;
}

int main()
{
    int arr[] = {5,8,6,13};
    int sum = 14;
    int n=sizeof(arr)/sizeof(arr[0]);

    Subarray_with_given_sum_one(arr,n,sum);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)

    Subarray_with_given_sum_two(arr,n,sum);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    return 0;
}


