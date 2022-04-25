// Sort an array of 0's 1's & 2's 
// Sort_an_array_of_0_s_1_s_and_2_s
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(int);

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        switch(arr[mid])
        {
            case 0: 
                swap(arr[low],arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high]);
                high--;
                break;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}