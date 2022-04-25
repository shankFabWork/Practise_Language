// Maximum number of activity 
// that can happen on a 
// single tasking machine

// I/P
// {(2,3),(1,4),(5,8),(6,10)}
// sort it according to the second activity
// first solution will always 
// be the part of the solution 
// O/P
// 2

// I/P
// {(1,3),(2,4),(3,8),(10,11)}
// O/P
// 3

#include <iostream>
#include <algorithm>

using namespace std;

bool myComp(pair <int,int> p1,pair <int,int> p2)
{
    return p1.second < p2.second;
}

int Activity_Selection_Problem(pair <int,int> arr[],int n)
{
    int res = 1;
    int prev = 0;
    // we will start from 1 
    // as first activity is always going to 
    // be the part of the solution
    for(int curr=1;curr<n;curr++)
    {
        if(arr[curr].first >= arr[prev].second)
        {
            res++;
            prev = curr;
        }
    }
    return res;
}

int main()
{
    pair <int,int> arr[] = 
    {
        make_pair(12,25),
        make_pair(10,20),
        make_pair(20,30)
    };
    // after sorting it will become
    // (10,20),(12,25),(20,30)
    int n =sizeof(arr)/sizeof(pair<int,int>);
    sort(arr,arr+n,myComp);
    // O(N.log(N))

    // sort according to the finishing time
    // in ascending order

    // O(N)
    cout<<Activity_Selection_Problem(arr,n);
    // Space Complexity -> O(n.log(n))
    // Time Complexity -> O(1)
    // as we modifies the 
    // orignal array in sorting

    return 0;
}