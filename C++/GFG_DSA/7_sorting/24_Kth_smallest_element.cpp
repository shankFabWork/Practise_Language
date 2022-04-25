#include <iostream>
#include <algorithm>

using namespace std;

// I/P->
// 10 5 30 12
// k=2

// O/P->
// 10

// -----------------------

// I/P->
// 30 20 5 10 8
// 4

// O/P->
// 20

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int hoare_partition(int arr[],int l,int r)
{
    int pivot=arr[r];
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

int k_th_smallest_elem_two(int arr[],int n,int k)
{
    int l=0;
    int r=n-1;
    int p=hoare_partition(arr,l,r);
    while(l <= r)
    {
        int mid= (l+r)/2;
        if(p == k-1)
        {
            return p;
        }
        else if(p > k-1)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}

int k_th_smallest_elem_one(int arr[],int n,int k)
{
    sort(arr,arr+n);

    // this is by default quick sort
    //Time Complexity -> O( n.log(n) ) 
    //Space Complexity -> O(1)

    return arr[k-1];
}

int main()
{
    int arr[]={10,5,30,12};
    int n=sizeof(arr)/sizeof(int);
    int k=2;


    cout<<k_th_smallest_elem_two(arr,n,k);
    //Time Complexity -> O( n.log(n) ) 
    //Space Complexity -> O(1)

    return 0;
}

