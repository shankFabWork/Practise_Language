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
#include <algorithm>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

// I/P
// 6 2 5 4 1 5 6
// O/P
// 10

// I/P
// 2 5 1
// O/P
// 5

void Largest_Rectangular_Area_in_Histogram_1(int arr[],int n)
{
    int res = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] >= arr[i])
            {
                curr = curr+arr[i];
            }
            else
            {
                break;
            }            
        }
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] >= arr[i])
            {
                curr = curr+arr[i];
            }
            else
            {
                break;
            }            
        }
        res = max(res,curr);
    }
    cout<<res;
}
// size = 7
//          0 1 2 3 4 5 6
// arr[] = {6,2,5,4,1,5,6}
// Previous Greater Element
// if found (index)
// if not found (-1)
// -1 -1 1 1 -1 4 5

//Next Greater Element
// if found (index)
// if not found (replace it with size )
// (in this case size of array is 7)
// 1 4 3 4 7 7 7 

vector <int> ps,ns;
void ps_ne(int arr[],int n)
{
    cout<<-1<<" ";
    for(int i=1;i<n;i++)
    {
        int j;
        for(j = i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
            {
                cout<<j<<" ";
                break;
            }
        }
        if(j == -1)
        {
            cout<<-1<<" ";
        }
    }
}

void ns_ne(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[i])
            {
                cout<<j<<" ";
                break;
            }
        }
        if(j == n)
        {
            cout<<n<<" ";
        }
    }
    cout<<n<<" ";
}

void ps_e(int arr[],int n)
{
    stack <int> s;
    s.push(0);
    // cout<<-1<<" ";
    ps.push_back(-1);
    for(int i=1;i<n;i++)
    {
        while(s.empty() != true && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        int prevGre = (s.empty() == true)?-1:s.top();
        // cout<<prevGre<<" ";
        ps.push_back(prevGre);
        s.push(i);
    }
}

void ns_e(int arr[],int n)
{
    stack <int> s;
    s.push(n-1);
    // cout<<n<<" ";
    ns.push_back(n);
    for(int i = n-2;i >=0;i--)
    {
        while(s.empty() != true && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        int nextGre = (s.empty() == true)?n:s.top();
        // cout<<nextGre<<" ";
        ns.push_back(nextGre);
        s.push(i);
    }
    reverse(ns.begin(),ns.end());
}

void Largest_Rectangular_Area_in_Histogram_2(int arr[],int n)
{
    int max_elem = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int res = arr[i];
        res += (i - ps[i] - 1)*arr[i];
        res += (ns[i] -i - 1)*arr[i];
        max_elem = max(max_elem,res);
    }
    cout<<max_elem;
}



int main()
{
    int arr[] = {6,2,5,4,1,5,6};
    int n = sizeof(arr)/sizeof(int);
    Largest_Rectangular_Area_in_Histogram_1(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)
    cout<<endl;
    ps_ne(arr,n);
    cout<<endl;
    ns_ne(arr,n);
    cout<<endl;
    ps_e(arr,n);
    ns_e(arr,n);
    Largest_Rectangular_Area_in_Histogram_2(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)


    return 0;
}