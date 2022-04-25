#include <iostream>

using namespace std;

void printArray(int arr[],int k)
{
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void counting_sort_naive_approach(int arr[],int n,int k)
{
    int count[k];

    // or
    // int count[k] = {0};

    printArray(arr,n);

    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }

    printArray(count,k);

    for(int i=0;i<n;i++)
    {
        ++count[arr[i]];
    }

    printArray(count,k);

    // 1 3 0 0 2
    // 0 1 2 3 4

    int index = 0;
    for(int i=0;i<k;i++)  //O(k)
    {
        for(int j=0;j<count[i];j++)   //O(n)
        {
            arr[index++] =  i;
        }
    }

    printArray(arr,n);

}

// 1 4 4 1 0 1 
// 0 0 0 0 0
// 1 3 0 0 2
// 0 1 1 1 4 4

int main()
{
    int arr[]={1,4,4,1,0,1};
    
    // range is given that 
    // the element are with in the range of k
    // i.e. 5 in this case i.e. (0-4)
    // we can find it by jut finding the 
    // maximum element in the array

    int k=5;
    int n=sizeof(arr)/sizeof(int);

    counting_sort_naive_approach(arr,n,k);
    // Time Complexity -> O(n + k)
    // Space Complexity -> O(k)

    // int worst case
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(n)
    
    // when all the elements are distinct
    // 5 2 3 1 0 4
    // 0 0 0 0 0 0 
    // 1 1 1 1 1 1
    // 0 1 2 3 4 5

    return 0;
}