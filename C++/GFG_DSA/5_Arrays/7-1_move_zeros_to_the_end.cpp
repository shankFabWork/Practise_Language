#include <iostream>

using namespace std;

// I/P->
// 0 0 0 10 0
// O/P->
// 10 0 0 0 0

// I/P->
// 10 20
// O/P->
// 10 20

                    
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void move_zeros_to_end_one(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j] != 0)
                {
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
}

void move_zeros_to_end_two(int arr[],int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main()
{
    // int arr[]={0,0,0,10,0};

    // int arr[]={10,20};
    int arr[]={8,5,0,10,0,20};
    

    int n=sizeof(arr)/sizeof(int);
    // move_zeros_to_end_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(n)

    move_zeros_to_end_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)


    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}

