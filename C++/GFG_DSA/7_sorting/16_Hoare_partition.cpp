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

int main()
{

    // int arr[]={5,3,8,4,2,7,1,10};

    // corner case
    // pivot is 5 is smallest
    // int arr[]={5,10,9,12};

    // pivot is 5 is samllest
    // int arr[]={12,10,5,9};
    // int arr[]={9,10,5,12};

    //all the lement are same
    int arr[]={5,5,5,5,5};
    //that is why quick sort is not a stable sort
    //as it is swapping the similar element

    //naive partition is a stable sort
    //as they are traversed in the same order 
    // or copy in the order

    int n=sizeof(arr)/sizeof(int);

    int l=0;
    int r=n-1;
    int p=0;

    int partiton_array=hoare_partition(arr,l,r);
    cout<<partiton_array;
    cout<<endl;
    for(int i=0;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}