// Majority element is an element that appears more than n/2 times 
// in an array of size n. In this video, two methods to find 
// majority element in an array are discussed.

// array of size 5
// majority element should occur 3 times (more than 2)

// array of size 6
// majority element should occur 4 times (more than 3)

// I/P
// 8 3 4 8 8
// O/P
// 8 or 3 or 4
// (index of 8)

// I/P
// 3 7 4 7 7 5  
// O/P
// -1
// (No Majority)

// I/P
// 20 30 40 50 50 50 50
// O/P
// 3 or 4 or 5 or 6
// (Any index of 50)

#include <iostream>

using namespace std;

// int max_val(int a,int b)
// {
//     if(a > b)
//     {
//         return a;
//     }
//     return b;
// }

int Majority_Element_one(int arr[],int n)
{
    int max_count = 0;
    for(int i=0;i<n;i++)
    {
        int count = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                count += 1;
            }
        }
        if(count > n/2)
        {
            return i;
        }
    }
    return -1;
}

int Majority_Element_two(int arr[],int n)
{
    //phase-1
    int res = 0;
    int count = 1;

    for(int i=1;i<n;i++)
    {
        if(arr[res] == arr[i])
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
        if(count == 0)
        {
            count = 1;
            res = i;
        }
    }

    //phase 2
    count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == arr[res])
        {
            count += 1;
        }
    }

    if(count > (n/2))
    {
        return res;
    }
    return -1;
}

int main()
{
    // int arr[] = {8,7,6,8,6,6,6,6};
    // res is 3
    // is majority

    int arr[] = {6,8,4,8,8};
    // res is 4
    // is majority

    // int arr[] = {6,8,4,8};
    // res is -1
    // is not majority

    int n = sizeof(arr)/sizeof(int);

    // cout<<Majority_Element_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    cout<<Majority_Element_two(arr,n);
    // this algo is popularly knows as ::
    // Boyer Moore Voting algorithm
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    //values of count and res
    // 8 8 6 6 6 6 
    // 1 2 1 0 1 2 -> count
    // 0 0 0 3 3 3 -> res

    // 6 8 7 6 6
    // 1 0 0 1 2 -> count
    // 0 1 2 3 3 -> res

    return 0;
}