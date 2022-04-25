// Sliding Window Technique ::
// Given an array of integer and a number K
// find the maximum sum of 
// k consecutive elements

// I/P
// 1 8 30 -5 20 7
// k=3
// O/P
// 45

// I/P
// 5 -10 6 90 3
// k=2
// O/P
// 96

#include <iostream>
#include <limits.h>
#include <unordered_set>

using namespace std;

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

void Sliding_Window_Technique_one(int arr[],int n,int k)
{
    int maxSum = INT_MIN;
    for(int i=0;i<(n-k+1);i++)
    {
        int sum = 0;
        for(int j=i;j<(i+k);j++)
        {
            sum += arr[j];
        }
        // cout<<sum<<" ";
        maxSum = max_val(maxSum,sum);
    }
    cout<<maxSum;
}

void Sliding_Window_Technique_two(int arr[],int n,int k)
{
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<k;i++)
    {
        curr_sum += arr[i]; 
    }
    // cout<<curr_sum<<" ";
    max_sum = max_val(max_sum,curr_sum);
    for(int i=k;i<n;i++)
    {
        // never write like this
        curr_sum = curr_sum + (arr[i] - arr[i-k]);
        // cout<<curr_sum<<" ";
        max_sum = max_val(max_sum,curr_sum);
    }
    cout<<max_sum;
}

// Next Problem in same video
// given an unsorted array of non-negative integers
// find if there is a subarray with the given integer

// I/P
// 1 4 20 3 10 5
// sum = 33
// O/P
// yes

// I/P
// 1 4 0 0 3 10 5
// sum = 7
// O/P
// yes

// I/P
// 2 4
// sum = 3
// O/P
// no

//this approach will noly work in positive array not negative array

bool isSubSum(int arr[],int n,int sum)
{
    int curr_sum = arr[0];
    int s = 0;
    for(int e = 1 ;e < n;e++)
    {
        while(curr_sum > sum && s < e)
        {
            curr_sum = curr_sum - arr[s];
            s++;
        }
        if(curr_sum == sum)
        {
            return true;
        }

        curr_sum = curr_sum + arr[e];
    }

    return (curr_sum == sum);
}

void n_bonacci_numbers(int n,int m)
{
    int a = 0;
    int b = 1;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    int k = 2; 

    for(int i=2;i<m;i++)
    {
        int c = a+b;
        arr[k] = c; 
        k++;
        a = b;
        b = c;
    }

    int sum = 0;
    for(int i=0;i<m;i++)
    {
        cout<<arr[i]<<" ";
        sum += arr[i];
    }
    for(int i=1;i<n-m;i++)
    {
        cout<<sum<<" ";
        arr[i+m-1] = sum;
        sum -= arr[i-1];
        sum += arr[i+m-1];
    }
}

void count_distinct_element(int arr[],int n,int k)
{   
    unordered_set <int> us;
    for(int i=0;i<=n-k;i++)
    {
        for(int j = i;j<k+i;j++)
        {
            us.insert(arr[j]);
        }
        cout<<us.size()<<" ";
        us.clear();
    }
}

int main()
{
    // int arr[] = {1,8,30,-5,20,7};
    // int arr[] = {1,4,20,3,10,5};
    
    // int n = sizeof(arr)/sizeof(int);
    // int k=3;

    // Sliding_Window_Technique_one(arr,n,k);
    // Time Complexity -> O((n-k)*k)
    // Space Complexity -> O(1)

    // Sliding_Window_Technique_two(arr,n,k);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    n_bonacci_numbers(10,4);
    // Time Complexity -> O(n-m+m)
    // Space Complexity -> O(1)

    // ---------------------------------------
    int arr[] = {1,4,20,3,10,5};
    int n = sizeof(arr)/sizeof(int);
    int k=3;

    int sum = 33;
    cout<<isSubSum(arr,n,sum);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    // int arr[] = {1,2,1,3,4,3,3};
    // int k = 4;
    // int n =sizeof(arr)/sizeof(arr[0]);
    // count_distinct_element(arr,n,k);
    // Time Complexity -> O(n*k)
    // Space Complexity -> O(1)

    // 4 7 -3 1 2
    // sum = 9
    // 4 11 
    // 7
    // 7 4 5 7
    // so we do not get sum in negative number
    // as this approch do not work in negative number 
    // ---------------------------------------

    return 0;
}

