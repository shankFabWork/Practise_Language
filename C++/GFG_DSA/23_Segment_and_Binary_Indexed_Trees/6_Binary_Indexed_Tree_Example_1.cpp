// 1) Used for fixed sized arrays 
// and following two types of operations
// (a) Range Query : O(log(n))
// (b) Update a value : O(log(n))
// 2) Requires O(n) preprocessing time 
// and O(n) auxiliary space

#include <iostream>

using namespace std;


int getSum_1(int arr[],int qs,int qe)
{
    int sum = 0;
    for(int i=qs;i<=qe;i++)
    {
        sum += arr[i];
    }
    return sum;
}

void update_1(int arr[],int index,int val)
{
    arr[index] = val;
}


void initialize_2(int presum[],int arr[],int n)
{
    presum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        presum[i] = presum[i-1] + arr[i];
    }
}

int getSum_2(int presum[],int qs,int qe)
{
    if(qs == 0)
    {
        return presum[qe];
    }
    else
    {
        return presum[qe] - presum[qs-1];
    }
}

void update_2(int presum[],int arr[],int n,int index,int val)
{
    int diff = val - arr[index];
    for(int i=index;i<n;i++)
    {
        presum[i] = presum[i] + diff;
    }
    arr[index] = val;
}


int main()
{
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);

    // Method - 1 : Simple Method
    cout<<getSum_1(arr,0,2)<<" ";
    // Time Complexity -> O(n)
    cout<<getSum_1(arr,1,3)<<" ";
    update_1(arr,1,60);
    // Time Complexity -> O(1)
    cout<<getSum_1(arr,0,2)<<" ";
    cout<<getSum_1(arr,1,3)<<" ";

    cout<<endl;
    // Method - 2 : Prefix Sum Array
    int presum[n];
    initialize_2(presum,arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)

    cout<<getSum_2(presum,0,2)<<" ";
    // Time Complexity -> O(1)
    cout<<getSum_2(presum,1,3)<<" ";
    update_2(presum,arr,n,1,60);
    // Time Complexity -> O(n)
    cout<<getSum_2(presum,0,2)<<" ";
    cout<<getSum_2(presum,1,3)<<" ";
    update_2(presum,arr,n,1,90);
    cout<<getSum_2(presum,0,2)<<" ";
    cout<<getSum_2(presum,1,3)<<" ";

    return 0;
}