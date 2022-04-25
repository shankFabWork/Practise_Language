#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}

int lomuto_partition(int arr[],int l,int r)
{
    int i=-1;
    int p=arr[r];

    for(int j=0;j<=r-1;j++)
    {
        if(arr[j] <= p)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quick_sort(int arr[],int l,int r)
{
    if(l < r)
    {
        int p=lomuto_partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}

int main()
{
    // int arr[]={1,8,3,6,9,7};
    int arr[]={8,4,7,9,3,10,5};
    // int arr[]={1,3,6,8,9,7};
    // int arr[]={1,3,6,7,9,8};
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