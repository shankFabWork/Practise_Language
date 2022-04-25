// Input
// int arr[] = {10,8,5,12,15,7,6};
// k = 3
// Output
// 10 12 15 15 15 

// Input
// int arr[] = {20,5,3,8,6,15};
// k = 4
// Output
// 20 18 15
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arr[] = {10,8,5,12,15,7,6};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<=n-k;i++)
    {
        int max_val = INT_MIN;
        for(int j=i;j<=i+k;j++)
        {
            max_val = max(max_val,arr[j]);
        }
        cout<<max_val<<" ";
    }

    // TC - O(n^2)

}