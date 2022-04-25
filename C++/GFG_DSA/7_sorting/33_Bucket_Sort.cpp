// Bucket Sort

// 1) Consider a situation where 
// we have number uniformly distributed in 
// the range of 1 to 10^8 , how do we sort efficiently

// 2) consider another situation where we have point number 
// uniformly distributed in range 0.0 to 1.0

// ------------------------------------------------------
// Bucket Sort
// 20 88 70 85 75 95 18 82 60
// Range 0 to 99

// // 0-19 20-39 40-59 60-79 80-99

// step 1 : Scatter
// 0-19 20-39 40-59   60-79      80-99
//  18   20          70,75,60  88,85,95,82

// step 2 : Sort Buckets
// 0-19 20-39 40-59   60-79      80-99
//  18   20          60,70,75  82,85,88,95

// step 3 : Join Sorted Bucket
// 18 20 60 70 75 82 85 88 95

// how do we sort bucket 
// if array is small we will use bucket sort
// if array is small we will use merge sort
// sort function in the array is take care about it already

// O/P
// 20 80 10 85 75 99 18
// k = 5
// I/P
// 10 18 20 75 80 85 99

// O/P
// 20 80 40 30 70
// k = 4
// I/P
// 20 30 40 70 80 
// ------------------------------------------------------
// Important
// 30 40 10 80 5 12 70

// part 1: find maximum value
// max = 80
// max++
// 81

// part 2: fill bucket
// i=0:b=4*30/31=1
// i=1:b=4*40/31=1
// i=2:b=4*10/31=0
// i=3:b=4*80/31=3
// i=4:b=4*5/31=0
// i=5:b=4*12/31=0
// i=6:b=4*70/31=3
// as k = 4
// =>4 buckets will be made
// 1st bucket : 10 5 12
// 2nd bucket : 30 40
// 3rd bucket : 
// 4th bucket : 80 70

// part 3: sort bucket
// 1st bucket : 5 10 12
// 2nd bucket : 30 40
// 3rd bucket : 
// 4th bucket : 70 80

// part 4: join bucket
// 5 10 12 30 40 70 80
// ------------------------------------------------------



// for bucked sort we just need to make array of vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BucketSort(int arr[],int n,int k)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    max++;

    // array of vector
    vector <int> bkt[k];
    // it means
    // 0 ->
    // 1 ->
    // . ->
    // . ->
    // . ->
    // k-1 ->
    // buckets
    // vector size is unlimited
    for(int i=0;i<n;i++)
    {
        int bi = (k * arr[i])/max;
        bkt[bi].push_back(arr[i]);
    }

    for(int i=0;i<k;i++)
    {
        sort(bkt[i].begin(),bkt[i].end());
    }

    int index = 0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<bkt[i].size();j++)
        {
            arr[index++] = bkt[i][j];
        }
    }

}


void PrintArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    int arr[] = {30,40,10,80,5,12,70};
    int n = sizeof(arr)/sizeof(int);
    int k = 4;
    // how many buckets u want to make
    // in this case it is 4
 
    BucketSort(arr,n,k);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    PrintArray(arr,n);

    // best case when data is uniformly distributed
    // O(n)

    // worst case when all the element (items) go into the single bucket
    // sort function use 
    // if we use insertion to sort the individual bucket then O(n^2)
    // if we use merge to sort the individual bucket then O(n.log(n))


    return 0;
}
