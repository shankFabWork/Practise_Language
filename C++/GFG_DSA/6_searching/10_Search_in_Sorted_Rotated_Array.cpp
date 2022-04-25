#include <iostream>

using namespace std;

// I/P->
// 10 20 30 40 50 8 9
// x = 30

//but in this case origanl array is
// 8 9 10 20 30 40 50 
// which is rotated
// to
// 10 20 30 40 50 8 9
// O/P->
// 2

// I/P->
// 100 200 300 10 20 

//but in this case origanl array is
// 10 20 100 200 300 
// which is rotated
// to
// 100 200 300 10 20 
// x = 40
// O/P->
// -1

// 10 20 40 60 5 8
//        ^
// one of the half will always be sorted 
// when we divide the array into two
// in this case left half is sorted
// 10 < 40 < 8
// but 40 is not less than 8

// // 40 50 8 9 10 20 30  
//            ^
// one of the half will always be sorted 
// when we divide the array into two
// in this case right half is sorted
// 40 < 9 < 30
// but 9 is not greater than 40

#include <iostream>

using namespace std;

int Search_in_Sorted_Rotated_Array_one(int arr[],int n,int x)
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

int Search_in_Sorted_Rotated_Array_two(int arr[],int n,int x)
{
    int low = 0;    
    int high = n - 1;

    while(low < high)
    {
        int mid = (low + high)/2;

        if(x == arr[mid])
        {
            return mid;
        }

        if(arr[low] < arr[mid])
        {
            if(x < arr[mid] && x > arr[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(x < arr[high] && x > arr[mid])
            {
                low = mid + 1 ;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[]={100,200,400,1000,10,20};
    int n=sizeof(arr)/sizeof(int);
    int x = 10;

    // cout<<Search_in_Sorted_Rotated_Array_one(arr,n,x); 
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    // cout<<Search_in_Sorted_Rotated_Array_two(arr,n,x); 
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)
    
    return 0;
}
 


