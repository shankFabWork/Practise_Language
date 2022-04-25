#include <iostream>

using namespace std;

// Maximum Difference problem is to find the 
// maximum of arr[j] - arr[i] where j>i.

// I/P->
// 2 3 10 6 4 8 1
// O/P->
// 8

// I/P->
// 7 9 5 6 3 2
// O/P->
// 2

// I/P->
// 10 20 30
// O/P->
// 20

// I/P->
// 30 10 8 2
// O/P->
// 2

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int min_val(int a,int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

void Maximum_Difference_problem_one(int arr[],int n)
{
    int diff = arr[1] - arr[0];
    //     int diff = 0;
    //     never initialize value as 0
    //     see the concept as in this case largest difference is -2
    //     and 0 > -2  
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            diff = max_val(diff,arr[j] - arr[i]);
        }
    }
    cout<<diff;
}

void Maximum_Difference_problem_two(int arr[],int n)
{
    int maxDiff = arr[1] - arr[0];
    int minVal = arr[0];
    for(int j=1;j<n;j++)
    {
        maxDiff = max_val(maxDiff , arr[j] - minVal);
        // substrating it with the minimum value 
        // in order to find out the maximum difference

        minVal = min_val(minVal , arr[j]);
        //finding the minimum value
    }
    cout<<maxDiff;
}

int main()
{
    // int arr[]={2,3,10,6,4,8,1};
    // int arr[]={7,9,5,6,3,2};
    // int arr[]={10,20,30};
    int arr[]={30,10,8,2};
   
    int n=sizeof(arr)/sizeof(int);

    //Time Complexity -> 
    //Space Complexity -> 

    // Maximum_Difference_problem_one(arr,n);

    Maximum_Difference_problem_two(arr,n);

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<"\t";
    // }
    
    return 0;
}

