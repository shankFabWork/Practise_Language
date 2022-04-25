#include <iostream>

using namespace std;

int mergeArray(int arr[],int l,int mid,int r)
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
    int res=0;
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
            res=res+(n1-i);
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
    return res;
}

int count_inversion_first(int arr[],int n)
{
    int inversion_no=0;
    for(int i=0;i<n;i++)
    {
        int res=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                ++res;
            }
        }
        inversion_no+=res;
        cout<<res<<" ";
    }
    cout<<endl;
    return inversion_no;
}

int count_inversion_second(int arr[],int l,int r)
{
    int res=0;
    if(l < r)
    {
        int mid=(l+r)/2;
        res+=count_inversion_second(arr,l,mid);
        res+=count_inversion_second(arr,mid+1,r);
        res+=mergeArray(arr,l,mid,r);
    }
    return res;
}

int main()
{

    // an array forms a inversion
    // when i<j
    // and 
    // arr[i] > arr[j]

    // ex : 5 1 7 3 9 4
    // -->  3 0 2 0 1 0 (array form)
    //o/p : 6 inversin are there in an array

    int arr[]={10,3,8,1,7,4};
    int n=sizeof(arr)/sizeof(int);

    //Time complexity -> O(n^2)
    //Space complexity -> O(1)

    // int no_inversion=count_inversion_first(arr,n);
    int no_inversion=count_inversion_second(arr,0,n-1);
    cout<<no_inversion;

    return 0;
}