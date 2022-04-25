// I/P
// arr[] = {2,8,30,15,25,12}
// O/P
// -1 -1 -1 30 30 15

// I/P
// arr[] = {30,20,10}
// O/P
// -1 30 20

// I/P
// arr[] = {10,20,30}
// O/P
// -1 -1 -1 

// I/P
// arr[] = {6,18,4,15}
// O/P
// -1 -1 6 18

#include <iostream>
#include <limits.h>
#include <set>
#include <vector>

using namespace std;

void Ceiling_on_left_side_one(int arr[],int n)
{
    // as first array element do not has any left
    cout<<"-1 ";
    for(int i=1;i<n;i++)
    {
        int diff = INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(arr[j] >= arr[i])
            {
                diff = min(diff,arr[j]-arr[i]);
            }
        }
        if(diff == INT_MAX)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<arr[i]+diff<<" ";
        }
    }
}

void Ceiling_on_left_side_two(int arr[],int n)
{
    set <int> s;
    s.insert(arr[0]);
    for(int i=0;i<n;i++)
    {
        // upper bound - greater than
        // lower bound - greater than or equal 
        // set<int>::iterator it = s.lower_bound(arr[i]);
        auto it = s.upper_bound(arr[i]);
        if(it == s.end())
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<*it<<" ";
        }
        s.insert(arr[i]);
    }
}

int main()
{
    int arr[] = {2,8,30,15,25,12};
    int n = sizeof(arr)/sizeof(int);
    // Naive Approach
    Ceiling_on_left_side_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)


    cout<<endl;
    // Efficient solution includes 
    // self balancing binary search tree
    // set or map
    // but set is for single element
    // but map is for (key,value) pair
    Ceiling_on_left_side_two(arr,n);
    // Time Complexity -> O(n.log(n))
    // Space Complexity -> O(n)

    return  0;
}