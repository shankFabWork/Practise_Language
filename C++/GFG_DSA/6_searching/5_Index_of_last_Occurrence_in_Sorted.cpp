#include <iostream>

using namespace std;

// I/P->
// 10 15 20 20 40 40
// x=20
// O/P->
// 3

// I/P->
// 5 8 8 10 10
// x=10
// O/P->
// 4

// I/P->
// 8 10 10 12
// x=7
// O/P->
// -1

int last_occurance_one(int arr[],int elem,int left,int right)
{
    int mid = (left + right)/2;
    if(left > right)
    {
        return -1;
    }

    if(arr[mid] == elem)
    {
        // changes from here rest evertinh is same
        if(mid  == 0 || arr[mid] != arr[mid+1])
        {
            return mid;
        }
        else
        {
            last_occurance_one(arr,elem,mid+1,right);
        }
    }
    else if(arr[mid] > elem)
    {
        last_occurance_one(arr,elem,left,mid - 1);
    }
    else
    {
        last_occurance_one(arr,elem,mid + 1,right);
    }
}

void last_occurance_two(int arr[],int n,int elem)
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
                cout<<mid;
                break;
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
}

int main()
{
    int arr[]={5,10,10,10,10,20,20};
    int n=sizeof(arr)/sizeof(int);
    int x = 10;

    cout<<last_occurance_one(arr,x,0,n-1);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(log(n))
    
    //this is best solution
    last_occurance_two(arr,n,x);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(1)


    return 0;
}


