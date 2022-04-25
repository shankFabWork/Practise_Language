#include <iostream>

using namespace std;

void binary_search_one(int arr[],int n,int elem)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == elem)
        {
            cout<<i<<" ";
        }
    }
}

int binary_search_two(int arr[],int n,int elem)
{
    int left = 0;
    int right = n-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == elem)
        {
            return mid;
        }
        else if(arr[mid] > elem)
        {
            right = mid - 1; 
        }
        else
        {
            left = mid + 1; 
        }
    }
    return -1;
}

int main()
{
    //array must be sorted
    int arr[]={10,20,40,50,60};
    int n=sizeof(arr)/sizeof(int);
    int elem = 23;
    // int elem = 50;

    // naive solution
    binary_search_one(arr,n,elem);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    //efficiend solution
    cout<<binary_search_two(arr,n,elem);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)

    // in worst case 
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    
    return 0;
}



