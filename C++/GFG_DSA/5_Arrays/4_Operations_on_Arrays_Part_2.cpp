#include <iostream>

using namespace std;

int deleteElem(int arr[],int n,int x)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            break;
        }
    }

    if(i == n)
    {
        return -1;
    }
    for(;i<n;i++)
    {
        arr[i]=arr[i+1];
    }

    return n-1;
}


void disp(int arr[],int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={6,2,5,1,3};
    int n=sizeof(arr)/sizeof(int);


    disp(arr,n);
    n=deleteElem(arr,n,5);
    disp(arr,n);

    //Insert : O(n)

    //Search : 
    // O(n) for unsortd
    // O( log(n) ) for sortd

    //Delete : O(n)
    //Insert : O(n)

    //get i th element -> O(1)
    //update i th element -> O(1)

    //insert at the end -> O(1)
    //delete at the end -> O(1)


    return 0;
}