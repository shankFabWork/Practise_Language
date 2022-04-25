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
#include <vector>
#include <algorithm>

using namespace std;

// I/P
// 5 15 10 8 6 12 9 18
// O/P
// 15 18 12 12 12 18 18 -1

// I/P
// 10 15 20 25
// O/P
// 15 20 25 -1

// I/P
// 25 20 15 10
// O/P
// -1 -1 -1 -1

void Next_Greater_Element_one(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] > arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j == n)
        {
            cout<<-1<<" ";
        }
    }
}

void Next_Greater_Element_two(int arr[],int n)
{
    vector <int> v;
    stack <int> s;
    s.push(arr[n-1]);
    v.push_back(-1);
    cout<<-1<<" ";
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty() != true && s.top() < arr[i])
        {
            s.pop();
        }
        int nge = (s.empty() == true)?-1:s.top();
        cout<<nge<<" ";
        v.push_back(nge);
        s.push(arr[i]);
    }
    cout<<endl;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}   



int main()
{
    int arr[] = {5,15,10,8,6,12,9,18};
    int n = sizeof(arr)/sizeof(int);
    Next_Greater_Element_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)
    cout<<endl;
    Next_Greater_Element_two(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)


    return 0;
}