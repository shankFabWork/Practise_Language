// I/P
// 15 10 18 12 4 6 2 8 
// O/P
// -1 15 -1 18 12 12 6 12 

// I/P
// 8 10 12
// O/P
// -1 -1 -1 

// I/P
// 12 10 8 
// O/P
// -1 12 10 

// Given an array of distinct integers, 
// find the closest (positive wise) greater
// on left of every element. If there
// is no greater element on left, then print -1

#include <iostream>
#include <stack>

using namespace std;


// same as Previous Greater Element
void Previous_Greater_Element_one(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j] > arr[i])
            {
                cout<<arr[j]<<" ";
                break; 
            }
        }
        if(j == -1)
        {
            cout<<-1<<" ";
        }
    }
}

void Previous_Greater_Element_two(int arr[],int n)
{
    stack <int> s;
    s.push(arr[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty() != true && s.top() < arr[i])
        {
            s.pop();
        }
        int pge = (s.empty() == true)?-1:s.top();
        cout<<pge<<" ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {15,19,10,2,18,12,40,6,2,8};
    int n = sizeof(arr)/sizeof(int);
    Previous_Greater_Element_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)
    cout<<endl;
    Previous_Greater_Element_two(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    return 0;
}