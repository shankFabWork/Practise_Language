// Search and Insert operations on both fixed and dynamic sized arrays

#include <iostream>

using namespace std;

// Search in fixed sized arrays
// O(n)
int search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}


//Time complexity -> O(n)
//elem to be inseted is in the beginning -> O(n)
//elem to be inseted is in the ending -> O(1)

int insert(int arr[],int n,int x,int cap,int pos)
{
    if(n == cap)
    {
        return n;
    }

    //pos in not in index
    int index=pos-1;

    for(int i=n;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=x;
    return n+1;
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

// Search in fixed sized arrays
// Average Time Complexity for the Insertion  -> O(1)
// Average time complexity for inserting at the end ->  O(1)

int main()
{
    int cap=100;
    int arr[cap]={5,2,7,3,6,1};
    int n=6;

    cout<<n<<" ";

    cout<<search(arr,n,7);
    disp(arr,n);
    n=insert(arr,n,10,cap,3);
    disp(arr,n);
    n=insert(arr,n,20,cap,5);
    disp(arr,n);


    return 0;
}