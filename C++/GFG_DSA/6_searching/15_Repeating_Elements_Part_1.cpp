// ==> Condition of Repeating Element :
// * one element is repeating
// * rest of the element is not repeating 
// and is occuring exactly ones
// * array size >=2

// I/P->
// 0 2 1 3 2 2 
// O/P->
// 2
// only 2 is repeating 
// not other element is repeating
// other element is occuring only one time


// I/P->
// 1 2 3 0 3 4 5 
// O/P->
// 3


// I/P->
// 0 0
// O/P->
// 0

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int Repeating_Elements_one(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int Repeating_Elements_two(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i] == arr[i+1])
        {
            return arr[i];
        }
    }
    return -1;
}

int Repeating_Elements_three(int arr[],int n)
{
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    bool visited[max] = {false};
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
        }
        else
        {
            return arr[i];
        }
    }
    return -1;
}

// Note : in this case minimum element is 0
int main()
{
    int arr[]={0,2,1,3,2,2};
    int n=sizeof(arr)/sizeof(int);

    cout<<Repeating_Elements_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)

    cout<<endl;

    cout<<Repeating_Elements_two(arr,n);
    //Time Complexity -> O(n.log(n))
    //Space Complexity -> O(1)
    
    cout<<endl;

    cout<<Repeating_Elements_three(arr,n);
    
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)


    return 0;
}


