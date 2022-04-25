#include <bits/stdc++.h>

using namespace std;

int kadanees_algo(int arr[],int n)
{
    int maxDiff = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++)
    {
        maxDiff = max(maxDiff+arr[i],arr[i]);
        res = max(res,maxDiff);
    }
    return res;
}

int Maximum_Circular_Sum_Subarray(int arr[],int n)
{
    int max_normal = kadanees_algo(arr,n);
    if(max_normal < 0)
    {
        return max_normal;
    }
    int arr_sum = 0;
    for(int i=0;i<n;i++)
    {
        arr_sum += arr[i];
        arr[i] = -1*arr[i];
    }
    int max_circular = arr_sum + kadanees_algo(arr,n);
    return max(max_circular,max_normal);
}


int main()
{
    // int arr[] = {1,-2,3,-1,-2};
    // int n=sizeof(arr)/sizeof(int);

    // int maxDiff = arr[0];
    // int maxVal = arr[0];
    // for(int i=0;i<n;i++)
    // {
    //     maxDiff = max(maxDiff+arr[i],arr[i]);
    //     maxVal = max(maxVal,maxDiff);
    // }
    // cout<<maxVal;

    // int arr[] = {7,10,13,14};
    // int n=sizeof(arr)/sizeof(int);

    // int c = 1;
    // int max_val = INT_MIN;
    // for(int i=0;i<n;i++)
    // {
    //     if( 
    //         (arr[i]%2 == 0 && arr[i+1]%2 != 0) 
    //         ||
    //         (arr[i]%2 != 0 && arr[i+1]%2 == 0) 
    //     )
    //     {
    //         c++;
    //     }
    //     else
    //     {
    //         c = 1;
    //     }
    //     max_val = max(max_val,c);
    // }
    // cout<<max_val;

    int arr[] = {8,-4,3,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<Maximum_Circular_Sum_Subarray(arr,n);

    return 0;
}