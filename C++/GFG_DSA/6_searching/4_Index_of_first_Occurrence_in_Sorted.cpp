#include <iostream>

using namespace std;

// Given a sorted array with repetition and an element x, 
// we need to find index of first occurrence of x.


// I/P->
// 1 10 10 10 20 20 40
// x = 20
// O/P->
// 4

// I/P->
// 10 20 30
// x = 15
// O/P->
// -1

int first_occurance_one(int arr[],int n,int x)
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

int first_occurance_two(int arr[],int elem,int left,int right)
{
    int mid = (left + right)/2;
    if(left > right)
    {
        return -1;
    }

    if(arr[mid] == elem)
    {
        if(mid  == 0 || arr[mid] != arr[mid-1])
        {
            return mid;
        }
        else
        {
            first_occurance_two(arr,elem,left,mid-1);
        }
    }
    else if(arr[mid] > elem)
    {
        first_occurance_two(arr,elem,left,mid - 1);
    }
    else
    {
        first_occurance_two(arr,elem,mid + 1,right);
    }
}


void first_occurance_three(int arr[],int n,int elem)
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
                cout<<mid;
                break;
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
}



// recursive call includes function call overhead
//ignore warning
int main()
{
    int arr[]={1,10,10,10,20,20,40};
        //     0  1  2  3  4  5  6
    int n=sizeof(arr)/sizeof(int);
    int x=20;

    // int arr[]={10,20,30};
    // int n=sizeof(arr)/sizeof(int);
    // int x=15;

    // cout<<first_occurance_one(arr,n,x);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    cout<<first_occurance_two(arr,x,0,n-1);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(log(n))

    // best solution
    first_occurance_three(arr,n,x);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)
    
    return 0;
}



