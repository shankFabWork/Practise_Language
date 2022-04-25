// I/P->
// int arr[] = {1,4,13,-3,-10,5};
// 1 5 18 15 5
// before 5 sum is 0
// as 5 is in the array
// O/P->
// yes

// I/P->
// int arr[] = {-1,4,-3,5,1};
// -1 3 0 5
// before 5 sum is 0
// as 5 is in the array
// O/P->
// yes

// I/P->
// int arr[] = {3,1,-2,5,6};
// 3 4 2 7 13
// O/P->
// no

// I/P->
// int arr[] = {5,6,0,8};
// 5 11 0 
// sum of 0 is 0
// as 0 is in the array
// O/P->
// yes

#include <iostream>
#include <unordered_set>

using namespace std;

bool Subarray_with_zero_sum_one(int arr[],int n)
{
    bool hasSum = false;
    for(int i=0;i<n;i++)
    {
        int sum = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(sum == 0)
            {
                hasSum = true;
                break;
            }
            sum += arr[j];
        }
    }
    return hasSum;
}

bool Subarray_with_zero_sum_two(int arr[],int n)
{
    unordered_set <int> us;
    int pre_sum = 0;
    int zero_sum = false;
    for(int i=0;i<n;i++)
    {
        pre_sum += arr[i];
        us.insert(pre_sum);
        if(us.find(pre_sum) != us.end())
        {
            zero_sum = true;
            break;
        }
    }
    return zero_sum;
}

int main()
{
    int arr[] = {1,4,13,-3,-10,5};  
    int n=sizeof(arr)/sizeof(int);

    cout<<Subarray_with_zero_sum_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)
    
    cout<<endl;

    cout<<Subarray_with_zero_sum_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    return 0;
}


