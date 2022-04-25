// I/P->
// int arr[] = {3,2,8,15,-8};
// sum = 17
// O/P->
// true

// I/P->
// int arr[] = {2,1,6,3 };
// sum = 6
// O/P->
// false

// I/P->
// int arr[] = {5,8,-3,6};
// sum = 3
// O/P->
// true

#include <iostream>
#include <algorithm>
#include <unordered_Set>

using namespace std;

bool Pair_with_given_sum_in_unsorted_array_one(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( (arr[i]+arr[j]) == sum)
            {
                return true;
            }
        }
    }
    return false;
}

bool Pair_with_given_sum_in_unsorted_array_two(int arr[],int n,int sum)
{
    int *new_arr = arr;
    for(int i=1;i<n;i++)
    {
        cout<<(new_arr[i]+new_arr[i-1])<<" ";
        if( (new_arr[i]+new_arr[i-1]) == sum)
        {
            return true;
        }
    }
    return false;
}



bool Pair_with_given_sum_in_unsorted_array_three(int arr[],int n, int sum)
{
    unordered_set <int> us;
    for(int i = 0; i < n; i++)
    {
        if(us.find(sum - arr[i]) != us.end())
        {
            return true;
        }
        else
        {
            us.insert(arr[i]);
        }    
    }
    return false;
    
}

int main()
{
    // int arr[] = {3,2,8,15,-8};
    // int sum = 17;

    // int arr[] = {2,1,6,3 };
    // int sum = 6;

    int arr[] = {5,8,-3,6};
    int sum = 3;

    int n=sizeof(arr)/sizeof(int);

    cout<<Pair_with_given_sum_in_unsorted_array_one(arr,n,sum);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)
    cout<<endl;
    
    cout<<Pair_with_given_sum_in_unsorted_array_two(arr,n,sum);
    //Time Complexity -> O(n.log(n))
    //Space Complexity -> O(1)
    cout<<endl;
    
    cout<<Pair_with_given_sum_in_unsorted_array_three(arr,n,sum);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
    cout<<endl;

    return 0;
}


