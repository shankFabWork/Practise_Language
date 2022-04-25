#include <iostream>

using namespace std;

// Given a sorted array and an element x, 
// we need to count occurrences of x in the array.

// I/P
// 10 20 20 20 30 30
// x=20
// O/P
// 3

// I/P
// 10 10 10 10 10
// x=10
// O/P
// 5

// I/P
// 5 8 10
// x=7
// O/P
// 0


int first_occurance(int arr[],int n,int elem)
{
    int left = 0;
    int right = n-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == elem)
        {
            if(mid  == 0 || arr[mid] != arr[mid-1])
            {
                return mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        else if(arr[mid] > elem)
        {
            right = mid - 1; 
        }
        else if(arr[mid] < elem)
        {
            left = mid + 1; 
        }
        else
        {
            cout<<-1;
            break;
        }
    }
    return 0;
}


int last_occurance(int arr[],int n,int elem)
{
    int left = 0;
    int right = n-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == elem)
        {
            if(mid  == 0 || arr[mid] != arr[mid+1])
            {
                return mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if(arr[mid] > elem)
        {
            right = mid - 1; 
        }
        else if(arr[mid] < elem)
        {
            left = mid + 1; 
        }
        else
        {
            cout<<-1;
            break;
        }
    }
    return 0;
}

int Count_Occurrences_in_Sorted_array_two(int arr[],int n,int x)
{
    int firstElem = first_occurance(arr,n,x);
    // it's time complexity O(log(n))

    if(firstElem == -1)
    {
        cout<<"element do not exist in array";
    }
    else
    {
        int lastElem = last_occurance(arr,n,x);
        // it's time complexity O(log(n))
        return (lastElem - firstElem +1);
    }
    return 0;
}

int Count_Occurrences_in_Sorted_array_one(int arr[],int n,int x)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            sum += 1;
        }
    }
    return sum;
}

int main()
{
    int arr[]={10,20,20,20,30,30};    
    // int x=10;
    // int x=20;
    int x=30;
    int n=sizeof(arr)/sizeof(int);

    cout<<Count_Occurrences_in_Sorted_array_one(arr,n,x);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    
    // this is better
    // cout<<Count_Occurrences_in_Sorted_array_two(arr,n,x);
    // Time Complexity -> O(log(n) + log(n)) = O(log(n))
    // Space Complexity -> O(1)

    return 0;
}