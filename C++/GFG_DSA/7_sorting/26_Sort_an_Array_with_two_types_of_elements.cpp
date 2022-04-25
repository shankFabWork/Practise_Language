// Sort_an_Array_with_two_types_of_elements_one

// 1) Segregate +ve and -ve number
// I/P
// 15 -2 -3 16
// O/P
// -2 -3 15 16

// 2) segregate even and odd number
// I/P
// 15 14 12 13
// O/P
// 12 14 15 13

// 3) sort a binary array (array containing 0 or 1)
// 0 1 0 1
// 0 0 1 1

#include <iostream>

using namespace std;

void Sort_an_Array_with_two_types_of_elements_one(int arr[],int n)
{
    int temp[n],i;
    int index = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < 0)
        {
            temp[index++] =arr[i];
        }
    }
    
    for(int j=0;j<n;j++)
    {
        if(arr[j] >= 0)
        {
            temp[index++] =arr[j];
        }
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = temp[i]; 
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Sort_an_Array_with_two_types_of_elements_two(int arr[],int n)
{
    int i = -1;
    int j = n;
    while(true)
    {
        do
        {
            i++;
        }while(arr[i] < 0);

        do
        {
            j--;;
        }while(arr[j] >= 0);

        if(i >= j)
        {
            return;
            break;
        }

        swap(&arr[i],&arr[j]);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={13,-12,18,-10};
    int n=sizeof(arr)/sizeof(int);
    // Sort_an_Array_with_two_types_of_elements_one(arr,n);

    // this is lomuto partition
    Sort_an_Array_with_two_types_of_elements_two(arr,n);
    printArray(arr,n);




    return 0;
}