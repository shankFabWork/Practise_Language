// Given an array of n integers where each value represents the number 
// of chocolates in a packet. Each packet can have a variable number of 
// chocolates. There are m students, the task is to distribute chocolate 
// packets such that: 

// 1) Each student gets one packet.
// 2) The difference between the number of chocolates in the packet with
// maximum chocolates and packet with minimum chocolates given to 
// the students is minimum.

// input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
// Output: Minimum Difference is 2 
// Explanation:
// We have seven packets of chocolates and 
// we need to pick three packets for 3 students 
// If we pick 2, 3 and 4, we get the minimum 
// difference between maximum and minimum packet 
// sizes.

// Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
// Output: Minimum Difference is 2 
// Explanation:
// We have seven packets of chocolates and 
// we need to pick three packets for 3 students 
// If we pick 2, 3 and 4, we get the minimum 
// difference between maximum and minimum packet 
// sizes.

// Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
// Output: Minimum Difference is 6 
// Explanation:
// The set goes like 3,4,7,9,9 and the output 
// is 9-3 = 6

// Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 
// 30, 40, 28, 42, 30, 44, 48, 
// 43, 50} , m = 7 
// Output: Minimum Difference is 10 
// Explanation:
// We need to pick 7 packets. We pick 40, 41, 
// 42, 44, 48, 43 and 50 to minimize difference 
// between maximum and minimum. 


#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int min_val(int a,int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

// O(n.log(n) + n) = O(n.log(n))
int minDiff(int arr[],int n,int m)
{
    if(m > n)
    {
        return -1;
    }
    sort(arr,arr+n);
    // O(n.log(n))

    int res = INT_MAX;
    int diff = arr[m-1] - arr[0];
    res = min_val(res,diff);

    // O(n)
    for(int i = 1;(i+m-1)<n;i++)
    {
        diff = arr[i+m-1] - arr[i];
        res = min_val(res,diff);
    }

    return res;
}

int main()
{
    int arr[] = {7,3,2,4,9,12,56};
    // 2 3 4 7 9 12 56
    // 2 4 3 5 47 
    // 2 
    // is the minimum difference 

    int n=sizeof(arr)/sizeof(int);
    int m = 3;

    // O(n.log(n))
    cout<<minDiff(arr,n,m);
    // Time Complexity -> O(n + k)
    // Space Complexity -> O(k)


    return 0;
}