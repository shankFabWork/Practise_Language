#include <iostream>

using namespace std;

int ceilIdx(int arr[], int l, int r, int key) 
{ 
    while (r > l) 
    {         
        int m = l + (r - l) / 2; 
        if (arr[m] >= key) 
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

int Longest_Increasing_Subsequence_Problem(int arr[],int n)
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
    // int arr[] = {4,10,6,5,8,11,2,20};
    // int arr[] = {1,11,2,10,4,5,2,1};
    int arr[] = {1,8,7,5,3,4,6,2};
 
    int n = sizeof(arr)/sizeof(int);

    cout<<Longest_Increasing_Subsequence_Problem(arr,n);
    // TC - O(N^log(N))
    // SC - O(N)
}