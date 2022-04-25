
// I/P->
// int arr[] = {1,9,3,4,2,20};
// O/P->
// 1 2 3 4
// 4

// I/P->
// int arr[] = {8,20,7,30};
// O/P->
// 7 8
// 2

// I/P->
// int arr[] = {20,30,40};
// O/P->
// 1

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <limits.h>

using namespace std;

int Longest_Consecutive_Subsequence_one(int arr[],int n)
{
    sort(arr,arr+n);
    int res = 0;
    int data = 1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]+1 == (arr[i+1]) )
        {
            data++;
        }
        else
        {
            res = max(res,data);
            data = 1;
        }
    }
    return res;
}

int Longest_Consecutive_Subsequence_two(int arr[],int n)
{
    unordered_set <int> us(arr,arr+n);
    int max_val = INT_MIN;
    for(int i=0;i<n;i++)
    {       
        if(us.find(arr[i]-1) == us.end())
        {
            int curr = 1;
            while(us.find(arr[i]+curr) != us.end())
            {
                curr++;
                max_val = max(max_val,curr);
            }
        }
    }
    return max_val; 
}

int main()
{
    int arr[] = {1,9,3,4,2,20};
    // int arr[] = {8,20,7,30};

    int n=sizeof(arr)/sizeof(int);

    cout<<Longest_Consecutive_Subsequence_one(arr,n);

    //Time Complexity -> O(n.log(n))
    //Space Complexity -> O(n)
    cout<<endl;
    cout<<Longest_Consecutive_Subsequence_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
    

    return 0;
}


