#include <iostream>

using namespace std;

// Given an infinite sized array, we need to 
// write an efficient solution to search an element. 
// In this video, we have discussed two solutions.

// array size is in millions or Infinite

// I/P->
// 1 10 15 20 40 80 90 100 120 500,1000...
// x=100
// O/P->
// 7

// I/P->
// 20 40 100 300
// x=50
// O/P->
// -1

int Search_in_Infinite_Sized_Array_one(int arr[],int x)
{
    int  i = 0;
    while(true)
    {
        if(arr[i] == x)
        {
            return i;
        }
        if(arr[i] > x)
        {
            return -1;
        }
        i++;
    }
}

int binary_search_one(int arr[],int elem,int left,int right)
{
    int mid = (left + right)/2;
    if(left > right)
    {
        return -1;
    }

    if(arr[mid] == elem)
    {
        return mid;
    }
    else if(arr[mid] > elem)
    {
        binary_search_one(arr,elem,left,mid - 1);
    }
    else
    {
        binary_search_one(arr,elem,mid + 1,right);
    }
}

int binary_search_two(int arr[],int elem,int left,int right)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == elem)
        {
            return mid;
        }
        else if(arr[mid] > elem)
        {
            right = mid - 1; 
        }
        else
        {
            left = mid + 1; 
        }
    }
    return -1;
}

// efficiend solution
int Search_in_Infinite_Sized_Array_two(int arr[],int x)
{
    if(arr[0] == x)
    {
        return 0;
    }

    int i = 1;
    
    // log(pos)
    while(arr[i] < x)
    {
        i = i * 2;
        if(arr[i] == x)
        {
            return i;
        }
    }
    // log(pos)
    // return binary_search_one(arr,x,i/2+1,i-1);
    return binary_search_two(arr,x,i/2+1,i-1);
}

int main()
{
    int arr[]={1,10,15,20,40,80,90,100,120,500,1000};

    int x = 100;
    // int x = 15;
    // int x = 21;

    // naive approach
    cout<<Search_in_Infinite_Sized_Array_one(arr,x);
    //Time Complexity -> O(position)
    //Space Complexity -> O(1)

    // next approach
    // we will not pass 'n' because 
    // it is infinite size array
    cout<<Search_in_Infinite_Sized_Array_two(arr,x);
    //Time Complexity -> O(log(position))
    //Space Complexity -> O(1)

    return 0;
}



