// Merge_overlapping_intervals

// I/P
// {{1,3},{2,4},{5,7},{6,8}}
// O/P
// {{1,4},{5,8}}

// 1,3 + 2,4 = 1,4
// 1,4 + 5,7 = can not merge
// 5,7 + 6,8 =5,8

// I/P
// {{7,9},{6,10},{4,5},{1,3},{2,4}}
// O/P
// {{1,5},{6,10}}

// method 1 -> make an array of pairs ::::
// pair <int,int> arr[n]

// method 2 -> make an array of pairs ::::
// class Interval
// {
//     int start,end;
// };
// Interval arr[n];

// ----->How to check if these two interval overlap or not

// i1 = {5,10}
// i2 = {1,7}
// what is the larger start value -> 5
// does it lies in the range of anoher interval between 1 to 7 yes 

// i1 = {10,20}
// i2 = {5,15}
// what is the larger start value -> 10
// does it lies in the range of anoher interval between 5 to 15 yes 

// i1 = {10,20}
// i2 = {100,200}
// what is the larger start value -> 100
// does it lies in the range of anoher interval between 10 to 20 no 

// ----->other wayto check if these two interval overlap or not

// i1 = {10,20}
// i2 = {100,200}
// what is the smallest end value -> 20
// does it lies in the range of anoher interval between 100 to 200 no 

// i1 = {10,20}
// i2 = {5,15}
// what is the smallest end value -> 15
// does it lies in the range of anoher interval between 10 to 20 yes 

#include <iostream>
#include <algorithm>

using namespace std;

struct Interval
{
    int s,e;
};

bool myComparator(Interval a,Interval b)
{
    return a.s > b.s;
}

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int min_val(int a,int b)
{
    if(a > b)
    {
        return b;
    }
    return a;
}

int Merge_overlapping_intervals_one(Interval arr[],int n)
{
    sort(arr,arr+n,myComparator);

    int index = 0;

    for(int i=1;i<n;i++)
    {
        // if(arr[index].s <= arr[i].e && arr[index].s >= arr[i].s)
        // array is already sorted in descending order
        if(arr[index].s <= arr[i].e)
        {
            arr[index].s = min_val(arr[index].s,arr[i].s);
            arr[index].e = max_val(arr[index].e,arr[i].e);
        }
        else
        {
            index++;
            arr[index] = arr[i]; 
        }
    }
    return index;
}


void printArray(Interval arr[],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i].s<<" "<<arr[i].e<<endl;
    }
}

int main()
{
    // Interval arr[]={{1,3},{2,4},{5,7},{6,8}};
    Interval arr[]={{7,9},{6,10},{4,5},{1,3},{2,4}};
    int n=sizeof(arr)/sizeof(arr[0]);



    n = Merge_overlapping_intervals_one(arr,n);
    // Time Complexity -> O(n.log(n)) 
    // Space Complexity -> O(1)
    printArray(arr,n);

    // dry run
    // {{5,10},{3,15},{18,30},{2,7}}
    // {{2,7},{3,15},{5,10},{18,30}}
    // {{2,15},{3,15},{5,10},{18,30}}
    // {{2,15},{3,15},{5,10},{18,30}}
    // {{2,15},{18,30},{5,10},{18,30}}
    // index = 1
    // {{2,15},{18,30}}

    return 0;
}
