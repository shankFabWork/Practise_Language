#include <iostream>

using namespace std;

void mergeArray(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1],right[n2];
    int i,j,k;

    for(i=0;i<n1;i++)
    {
        left[i]=arr[i+l];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=arr[mid+1+j];
    }

    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i] >= right[j])
        {
            arr[k++]=right[j++];
        }
        else
        {
            arr[k++]=left[i++];
        }
    }
    
    while(i<n1)
    {
        arr[k++]=left[i++];
    }

    while(j<n2)
    {
        arr[k++]=right[j++];
    }
    
}

void mergeSort(int arr[],int l,int r)
{
    // atleast 2 elements in the array 
    // one element in the array will not pass this if condition
    if(l < r) 
    {
        // int mid=l+(r-l)/2;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        mergeArray(arr,l,mid,r);
    }

}

int main()
{

    int arr[]={10,40,20,60,90,40};
    int n=sizeof(arr)/sizeof(int);

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    mergeSort(arr,0,n-1);

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    


    return 0;
}