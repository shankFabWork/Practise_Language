// Binary Index Tree is based on the fact that

// Every Number can be expressed as 
// sum of powers of 2
// 14 -> 2^3 + 2^2 + 2^1
// 10 -> 2^3 + 2^1
// 5 -> 2^2 + 2^0

// arr[] = {10,20,30,40,50,60,70,80,90,100}
//           0  1  2  3  4  5  6  7  8  9
//           range -> 1 to 10

//   10  20 30 40  50  60 70 80 90
// 0  1   2  3  4   5   6  7  8  9
//   10  30 30 100 50 110 70 360 90 

#include <iostream>

using namespace std;

void updateQuery_for_constructBIT(int BIT_array[],int n,int index,int val)
{
    index = index + 1;
    while(index <= n)
    {
        BIT_array[index] += val;
        index = index + (index & - index);
    }
}

int* constructBIT(int arr[],int n)
{
    int *BIT_array = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        BIT_array[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        updateQuery_for_constructBIT(BIT_array,n,i,arr[i]);
    }
    for(int i=1;i<n;i++)
    {
        cout<<BIT_array[i]<<" ";
    }
    cout<<endl;
    return BIT_array;
}   

int getSum(int BIT_array[],int index)
{
    index = index + 1;
    int sum = 0;
    while(index > 0)
    {
        sum = sum + BIT_array[index];
        index = index - (index & -index); 
    }
    return sum;
}

// suppose i = 6
// i = 7
// 4 2 1
// 1 1 1 -> 7
// 1 1 0 -> 6
// 1 0 0 -> 4
// 0 0 0
// so get the sum of number of set bits
// so the time complexity is O(log(n))


void updateQuery(int BIT_array[],int n,int index,int val)
{
    index = index + 1;
    int diff = val - BIT_array[index];
    while(index <= n)
    {
        BIT_array[index] += diff;
        index = index + (index & - index);
    }
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90};
    // 10  30 30 100 50 110 70 360 90 
    int n = sizeof(arr)/sizeof(int);

    int *BIT_array = constructBIT(arr,n);
    cout<<arr[2]<<endl;
    cout<<getSum(BIT_array,8)<<endl;
    updateQuery(BIT_array, n, 2, 35); 
    cout<<getSum(BIT_array,8)<<endl;

    return 0;
}