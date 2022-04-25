#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int lomuto_partition(int arr[],int l,int r,int p)
{

    int i=-1;
    for(int j=0;j<=r-1;j++)
    {
        if(arr[j] <= arr[p])
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
}

int main()
{

    //Auxilary Space -> O(1)
    //Time Complexity -> O(n)

    int arr[]={2,8,4,9,1,7};

    //corner cases
    // int arr[]={70,60,80,40,30};
    // int arr[]={30,40,20,50,80};
    //at last we swap (arr[i+1],arr[p])
    int n=sizeof(arr)/sizeof(int);
    int l=0;
    int r=n-1;
    int p=5; //7

    int pivot_pos=lomuto_partition(arr,l,r,p);
    cout<<pivot_pos<<endl;
    for(int i=0;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}