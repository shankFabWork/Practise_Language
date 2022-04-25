#include <iostream>

using namespace std;

// I/P->
// 0 0 0 1 1 1 1
// O/P->
// 4

// I/P->
// 1 1 1 1 1
// O/P->
// 5

// I/P->
// 0 0 0 0
// O/P->
// 0

int countOnes(int arr[],int n)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == 0)
        {
            low = mid + 1;
        }
        else
        {
            // first occurance
            if(mid == 0 || (arr[mid] != arr[mid-1]) )
            {
                return (n-mid);
            }
            else
            {
                high = n-1;
            }
        }
    }
}

// array is sorted
// array will only contain 0 and 1 is sorted
// in group 
// otherwise it will not work
int main()
{
    int arr[]={0,0,0,1,1,1,1};
    int n=sizeof(arr)/sizeof(int);

    cout<<countOnes(arr,n);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)

    return 0;
}



