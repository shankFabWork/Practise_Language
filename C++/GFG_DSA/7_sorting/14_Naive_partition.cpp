#include <iostream>

using namespace std;

void naive_partition(int arr[],int l,int r,int p)
{
    int temp[r-l+1];
    int i=0,index=0;

    for(i=l;i<=r;i++)
    {
        if(arr[i] <= arr[p])
        {
            temp[index++]=arr[i];
        }
    }

    for(i=l;i<=r;i++)
    {
        if(arr[i] > arr[p])
        {
            temp[index++]=arr[i];
        }
    }

    index=0;
    for(i=l;i<=r;i++)
    {
        arr[i]=temp[index++];
    }

}

int main()
{
    // int arr[]={1,8,3,7,2,9};
    int arr[]={5,13,6,9,12,11,8};
    int n=sizeof(arr)/sizeof(int);

    int i=0;
    int l=0;
    int r=n-1;
    int p=6; //8

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Auxilary Space : O(n)
    //Time Complexity : O(n)


    naive_partition(arr,l,r,p);

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}