#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int hoare_partition(int arr[],int l,int r)
{
    int pivot=arr[l];
    int i=l-1,j=r+1;

    while(true)
    {
        do
        {
            i++;
        }while(arr[i] < pivot);
        
        do
        {
            j--;
        }while(arr[j] > pivot);

        if(i >= j)
        {
            return j;
        }

        swap(&arr[i],&arr[j]);
    }
}

//this is tail recursion 
//as function is called at the bottom of the function
// void quick_sort(int arr[],int l,int r)
// {   
//     if(l < r)
//     {   
//         // partition_index
//         int p=hoare_partition(arr,l,r);
//         quick_sort(arr,l,p);
//         quick_sort(arr,p+1,r);
//     }
// }


//tail call elemination can be replaced with the goto statement
void quick_sort(int arr[],int l,int r)
{   
    x:  
    if(l < r)
    {   
        // partition_index
        int p=hoare_partition(arr,l,r);
        quick_sort(arr,l,p);
        l=p+1;
        goto x;
    }
}

int main()
{
    // int arr[]={8,1,6,2,9,7};
    int arr[]={ 4, 1, 3, 9, 7};
    int n=sizeof(arr)/sizeof(int);

    int l=0;
    int r=n-1;

    quick_sort(arr,l,r);

    for(int i=0;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}