// same but one loop 
// instead of 3
// not doing
// not done yet

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

void Largest_Rectangular_Area_in_Histogram(int arr[],int n)
{
    stack <int> s;
    int res = INT_MIN;
    for(int i=0;i<n;i++)
    {
        while(s.empty() != true && arr[s.top()] >= arr[i])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp]*( (s.empty() == true)?i:(i-s.top()-1) );
            res = max(res,curr);
        }
        s.push(i);
    }
    while(s.empty() != true)
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp]*( (s.empty() == true)?n:(n-s.top()-1) );
        res = max(res,curr);
    }
    cout<<res<<endl;
}

int main()
{
    int arr[] = {6,2,5,4,1,5,6};
    int n = sizeof(arr)/sizeof(int);
    Largest_Rectangular_Area_in_Histogram(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    return 0;
}