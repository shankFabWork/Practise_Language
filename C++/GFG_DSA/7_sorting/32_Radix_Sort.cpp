// Radix sort is a linear time algorithm
// if your data is with in the limited range

//  An algorithm is said to take linear time, or O(n) time,
//  if its time complexity is O(n). Informally, this means 
//  that the running time increases at most linearly 
//  with the size of the input.

// 319 212 6 8 100 50
// re-wrting numbers with the leading zeros
// 319 212 006 008 100 050
// we need to find the maximum digit number
// stable sort according to the last digit (Least Significant Digit)
// 100 050 212 006 008 319
// stable sort according to the middle digit 
// 100 006 008 212 319 050
// stable sort according to the most significant digit 
// 006 008 050 100 212 319

#include <iostream>
#include <limits.h>

using namespace std;

// O(n + b)
// b = 10 
void CountSort(int arr[],int n,int exp)
{
    int count[10] = {0};
    int output[n];

    // O(n)
    for(int i=0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }
     
    // O(b)
    for(int i=1;i<10;i++)
    {
        count[i] = count[i] + count[i-1];
    }
   
    // O(n)
    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    // O(n)
    for(int i=0;i<n;i++)
    {
        arr[i] = output[i];
    }
}


void Radix_Sort(int arr[],int n)
{
    // int max = INT_MIN;
    // for(int i=0;i<n;i++)
    // {
    //     if(max < arr[i])
    //     {
    //         max = arr[i];
    //     }
    // }
    // cout<<max;
    // or

    // part 1

    // O(n)
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    // part 2

    // maximum nuber is 319
    // so d = 3 in this case (no of digits)

    // O(d)
    for(int exp=1;max/exp > 0;exp = exp * 10)
    {
        // O(n + b)
        CountSort(arr,n,exp);
    }

    // Time Complexity -> O(d*(n + b))

    // Space Complexity -> O(n+b)
    // n for array "arr" 
    // n = 6 in this case
    // and
    // b for array "count" 
    // b = 10 in this case




    // for example
    // 391/1 = 391
    // 391/10 = 39
    // 391/100 = 3
    // 391/1000 = 0
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
    int arr[] = {319,212,6,8,100,50};
    int n = sizeof(arr)/sizeof(int);
    PrintArray(arr,n);
    // this is stable sort
    // say 100 100 both of them will reamin at their position
    Radix_Sort(arr,n);
    PrintArray(arr,n);

    return 0;
}


// 0 1 2 3 4 5 6 7 8 9
// 0 0 0 0 0 0 0 0 0 0

// n=6
// 0   1   2 3 4   5
// 319 212 6 8 100 50

// 0 1 2 3 4 5 6 7 8 9
// 0 0 0 0 0 0 0 0 0 0
// 2 0 1 0 0 0 1 0 1 1 
// 2 2 3 3 3 3 4 4 5 6
// 0  1  2   3 4 5
// 100 50 212 6 8 319

// 0 1 2 3 4 5 6 7 8 9
// 0 0 0 0 0 0 0 0 0 0
// 3 2 0 0 0 1 0 0 0 0
// 3 5 5 5 5 6 6 6 6 6
// 0   1  2  3   4   5
// 100 06 08 212 319 50

// 0 1 2 3 4 5 6 7 8 9
// 0 0 0 0 0 0 0 0 0 0
// 3 1 1 1 0 0 0 0 0 0
// 3 4 5 6 6 6 6 6 6 6
// 0   1   2   3   4   5
// 006 008 050 100 212 319