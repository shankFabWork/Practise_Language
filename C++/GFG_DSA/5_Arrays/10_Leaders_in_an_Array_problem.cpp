#include <iostream>

using namespace std;

// I/P->
// 7 10 4 6 6 5 2
// O/P->
// 10 6 5 2

// I/P->
// 10 20 30 
// O/P->
// 30

// I/P->
// 30 20 10 
// O/P->
// 30 20 10

//Last element is always a leader

// An element is called the leader of an array 
// if there is no element greater than 
// it on the right side.

void Leaders_in_an_Array_one(int arr[],int n)
{

    for(int i=0;i<n;i++)
    {
        bool is_leader = true;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] <= arr[j])
            {
                is_leader = false;
                break;
            }
        }
        if(is_leader == true)
        {
            cout<<arr[i]<<" ";
        }
    }
}


void Leaders_in_an_Array_two(int arr[],int n)
{
    int curr_leader = arr[n-1];
    cout<<curr_leader<<" ";

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] > curr_leader)
        {
            curr_leader = arr[i];
            cout<<curr_leader<<" ";
        }
    }

}


int main()
{
    int arr[] = {7,10,4,10,6,5,2};
    int n=sizeof(arr)/sizeof(int);

    // Leaders_in_an_Array_one(arr,n);
    //Time Complexity -> O( n^2 ) 
    //Space Complexity -> O(1)


    Leaders_in_an_Array_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)


    return 0;
}

