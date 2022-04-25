// The task is to find maximum circular sum subarray of a given array. 
//  Two approaches are discussed, one is O(n^2) and other is O(n).

#include <iostream>

using namespace std;

// I/P
// 5 -2 3 4
// O/P
// 12

// I/P
// 2 3 -4
// O/P
// 5

// I/P
// 8 -4 3 -5 4
// O/P
// 12

// I/P
// -3 4 6 -2
// O/P
// 12

// I/P
// -8 7 6
// O/P
// 13

// Important
// I/P
// -3 -4 5 6 -8 7
// O/P
// 17

// Kadane's algorithm

int Kadane_algo(int arr[],int n)
{
    int maxE = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++)
    {
        maxE = max(arr[i],arr[i]+maxE);
        res = max(res,maxE);
    }
    return res;
}

int Maximum_Circular_Sum_Subarray(int arr[],int n)
{
    int max_normal = Kadane_algo(arr,n);
    if(max_normal < 0)
    {
        return max_normal;
    }
    int arr_sum = 0;
    for(int i=0;i<n;i++)
    {
        arr_sum = arr_sum + arr[i];
        arr[i] = -1*arr[i];
    }
    int max_circular = arr_sum + Kadane_algo(arr,n);
    return max(max_normal,max_circular);
}

int main()
{
    int arr[] = {8,-4,3,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<Maximum_Circular_Sum_Subarray(arr,n);
    // Efficient Algorithm 
    // TC -> O(n)
    // SC - O(1)
    return 0;
}