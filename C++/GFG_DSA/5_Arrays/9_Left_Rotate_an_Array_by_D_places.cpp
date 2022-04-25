#include <iostream>

using namespace std;

// I/P->
// 1 2 3 4 5
// d=2
// O/P->
// 3 4 5 1 2

// I/P->
// 1 2 3 4 5
// d=6
// 6-5=1

// O/P->
// 5 4 3 2 1
// 1 5 4 3 2

//condition 
// d <= No of elements in the array

void Left_Rotate_Array_by_D_places_one(int arr[],int n,int k)
{
    int temp[n];
    int c=0;
    for(int i=k;i<n;i++)    
    {
        temp[c++] = arr[i];
    }
    for(int i=0;i<k;i++)
    {
        temp[c++] = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = temp[i];
    }
}

void Left_Rotate_Array_by_D_places_two(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void Left_Rotate_Array_by_D_places_three(int arr[],int n,int k)
{

    // k=2
    // arr->1 2 3 4 5
    // temp[2]->1 2 (c=2)
    // arr->(d to n-1)->(3 4 5 4 5)
    // arr->(0 to k)->(3 4 5 1 2)
    int temp[k];
    int c=0;
    for(int i=0;i<k;i++)
    {
       temp[i] = arr[i];  
    }
    c=0;
    for(int i=k;i<n;i++)
    {
        arr[c++] = arr[i];
    }
    for(int i=0;i<k;i++)
    {
        arr[c++] = temp[i];
    }
}



void reverse(int arr[],int low,int high)
{
    while(low < high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}

// 1 2 3 4 5
// 2 1 3 4 5
// 2 1 5 4 3 
// 3 4 5 1 2

void Left_Rotate_Array_by_D_places_four(int arr[],int n,int k)
{
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}
    
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int k=2;

    // Left_Rotate_Array_by_D_places_one(arr,n,k);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    // for(int i=0;i<k;i++)
    // {
    //     Left_Rotate_Array_by_D_places_two(arr,n);
    // }
    
    //Time Complexity -> O(n.d)
    //Space Complexity -> O(1)


    // Left_Rotate_Array_by_D_places_three(arr,n,k);
    //Time Complexity -> O(n)
    //Space Complexity -> O(k)

    Left_Rotate_Array_by_D_places_four(arr,n,k);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)


    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }





    return 0;
}
