#include <iostream>

using namespace std;

//Remove_duplicates_from_a_sorted_array

// I/p
// 10 20 20 30 30 30 30 
// size=7
// O/P
// 10 20 30 
// size=3

// I/P
// 10 10 10
// size=3
// O/P
// 10
// size=1

int remove_dupli_one(int arr[],int n)
{
    int temp[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] != arr[i+1])
        {
            temp[k++] = arr[i];
        }
    }

    for(int i=0;i<k;i++)
    {
        arr[i] = temp[i]; 
    }

    return k;
}

int remove_dupli_two(int arr[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(arr[res-1] != arr[i])
        {
            arr[res] = arr[i];
            res++;
        }
    }

    return res;
}

int main()
{
    int arr[]={10,10,20,30,30,40};

    int n=sizeof(arr)/sizeof(int);

    int k=remove_dupli_one(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    // int k=remove_dupli_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}