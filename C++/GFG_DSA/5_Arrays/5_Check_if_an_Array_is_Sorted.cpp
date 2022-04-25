#include <iostream>

using namespace std;

bool is_sorted_1(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool is_sorted_2(int arr[],int n)
{
    for(int i=1;i<n-1;i++)
    {
        if(arr[i] < arr[i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //Sorted
    int arr[]={10,40,60,90};
    
    //Unsorted
    // int arr[]={10,40,60,10};
    
    int n=sizeof(arr)/sizeof(int);
    
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1) 
    cout<<is_sorted_1(arr,n);

    cout<<endl;

    //Time Complexity -> O(n)
    //Space Complexity -> O(1) 
    cout<<is_sorted_2(arr,n);

    return 0;
}

