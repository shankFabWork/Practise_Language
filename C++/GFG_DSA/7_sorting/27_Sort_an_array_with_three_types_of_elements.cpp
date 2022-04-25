// Sort an array of three types of elements

// 1) sort an array of 0s , 1s and 2s
// 0 1 0 2 1 2
// 0 0 1 1 2 2

// 2) three way partitioning when multiply 
// occurance of a pivot may exist

// considering 2 as a pivot
// 2 2 1 1 10 10 20 30 
// 1 1 2 2 30 10 10 20 

// 3) partitioning around a range
// 10 5 6 3 20 9 40
// range[5,10]
// 3 5 10 6 9 20 40
// elements less than 5 will be on the left 
// elements greater than 10 will be on the right 


#include <iostream>

using namespace std;

void Sort_an_array_with_three_types_of_elements_one(int arr[],int n)
{
    int temp[n],i;

    int index = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            temp[index++] = arr[i];
        }
    }

    for(int j=0;j<n;j++)
    {
        if(arr[j] == 1)
        {
            temp[index++] = arr[j];
        }
    }

    for(int k=0;k<n;k++)
    {
        if(arr[k] == 2)
        {
            temp[index++] = arr[k];
        }
    }

    index = 0;
    for(int i=0;i<n;i++)
    {
        arr[i] = temp[index++];
    }

}

void swap(int *a,int *b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Dutch National Flag Algorithm OR 3-way Partitioning:
void Sort_an_array_with_three_types_of_elements_two(int arr[],int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        switch(arr[mid])
        {
                case 0: swap(&arr[low],&arr[mid]);
                        low++;
                        mid++;
                        break;         

                case 1: mid++;
                        break;  

                case 2: swap(&arr[mid],&arr[high]);
                        high--;
                        break;                  
        }
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
    int arr[]={0,1,0,2,1,2};
    int n=sizeof(arr)/sizeof(int);

    // Sort_an_array_with_three_types_of_elements_one(arr,n);
    //Time Complexity -> O(n) 
    //Space Complexity -> O(n)


    // this algo is also called
    // Dutch National Flag Algorithm OR 3-way Partitioning:
    Sort_an_array_with_three_types_of_elements_two(arr,n);
    //Time Complexity -> O(n) 
    //Space Complexity -> O(1)

    printArray(arr,n);




    return 0;
}
