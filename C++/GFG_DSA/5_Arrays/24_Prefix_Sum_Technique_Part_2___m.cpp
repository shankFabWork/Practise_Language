// Given N ranges , find the maximum 
// appering element in the ranges

// I/P
// L[] = {1,2,5,15}
// R[] = {5,8,7,18}
// it means 
// 1-5 -> {1,2,3,4,5}
// 2-8 -> {2,3,4,5,6,7,8}
// 5-7 -> {5,6,7}
// 15-18 -> {15,16,17,18}

// O/P
// 5

// Time Complexity
// O(n*m)

// Condition:
// 0 <= L[i],R[i] < 1000

#include <iostream>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;

void maxOccurance_one(int L[],int R[],int n)
{
    // same as below method
    // int arr[100]={0};
    // for(int i = 0; i < n; i++)
    // {
    //     for(int a = L[i];a <= R[i];a++)
    //     {
    //         arr[a]++;
    //     }        
    // }
    // int max_elem = INT_MIN;
    // int max_index = 0;
    // for(int i = 0; i < 100; i++)
    // {
    //     if(max_elem < arr[i])
    //     {
    //         max_elem = arr[i];
    //         max_index = i;
    //     }
    // }
    // cout<<max_index;


    // same as above method
    unordered_map <int,int> um;
    for(int i=0;i<n;i++)
    {
        for(int j=L[i];j<=R[i];j++)
        {
            um[j]++;
        }
    }
    int max_val = INT_MIN;
    int max_index;
    for(auto data:um)
    {
        if(data.second > max_val)
        {
            max_val = data.second;
            max_index = data.first;
        }
    }
    cout<<max_index;

}



void maxOccurance_two(int L[],int R[],int n)
{
    int arr[100]={0};
    for(int i = 0; i < n; i++)
    {
        arr[L[i]]++;
        arr[R[i]+1]--;
    }
    int max_elem = INT_MIN;
    int max_index = 0;
    for(int i = 1; i < 100; i++)
    {
        arr[i] += arr[i-1];
        if(max_elem < arr[i])
        {
            max_elem = arr[i];
            max_index = i;
        }
    }

    cout<<(max_index);
}

int main()
{
    // int L[] = {1,2,3};
    // int R[] = {3,5,7};
    // answer -> 3

    int L[] = {1,2,5,15};
    int R[] = {5,8,7,18};
    // answer -> 5

    int n=sizeof(L)/sizeof(int);

    // maxOccurance_one(L,R,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(100)
    // Space Complexity depending upon constraints 
    // in this case it is 100 

    maxOccurance_two(L,R,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(100)

    return 0;
}

// 1 2 3
// 3 5 7
// 0 1 1 1  0  0  0 0  0 0 0 0 0 0 0 0 0 
// 0 0 0 0 -1  0 -1 0 -1 0 0 0 0 0 0 0 0
// sum
// 0 1 1 1 -1  0 -1 0 -1 0 0 0 0 0 0 0 0
// last loop
// 0 1 2 3  2  2  1 1  0 0 0 0 0 0 0 0 0  
// according to index
// 0 1 2 3 4 5  6 7  8  9 10 11 12 13 14 15 16 17 18 19 20
// answer is 3

// 1 2 5 15
// 5 8 7 18
// 0 1 2 3 4 5  6 7  8  9 10 11 12 13 14 15 16 17 18 19 20
// 0 1 1 0 0 1  0 0  0  0  0  0  0  0  0  1  0  0  0  0  0
// 0 0 0 0 0 0 -1 0 -1 -1 0 0 0 0 0 0 0 0 0 0 0 0  0 -1 0
// sum
// 0 1 1 0 0 1 -1 0 -1 -1 0 0 0 0 0 0 0 0 1 0 0 0  0 -1 0
// last loop
// 0 1 2 2 2 3  2 2  1  0 0 0 0 0 0 0 0 0 1 0 0 0  0  0 0
// according to index
// 0 1 2 3 4 5  6 7  8  9 10 11 12 13 14 15 16 17 18 19 20
// answer is 5
