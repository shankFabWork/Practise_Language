#include <iostream>

using namespace std;

void initialize(int presum[],int arr[],int n)
{
    presum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        presum[i] = presum[i-1] + arr[i];
    }
}

int getSum(int presum[],int qs,int qe)
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

void update(int presum[],int arr[],int n,int index,int val)
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
    int presum[n];
    initialize(presum,arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)

    cout<<getSum(presum,0,2)<<" ";
    // Time Complexity -> O(1)
    cout<<getSum(presum,1,3)<<" ";
    update(presum,arr,n,1,60);
    // Time Complexity -> O(n)
    cout<<getSum(presum,0,2)<<" ";
    cout<<getSum(presum,1,3)<<" ";
    update(presum,arr,n,1,90);
    cout<<getSum(presum,0,2)<<" ";
    cout<<getSum(presum,1,3)<<" ";

    // Important Points :
    // -----size of segement tree-----
    // -------------------------------
    
    // if n is the power of 2 , then 2n-1
    // else 2x-1 where x is the smallest 
    // power of 2 greater than n

    // n = 5 , 
    // not power of 2
    // so 2x-1
    // x = 2^(ceil(log(base2(n))))
    // x = 8
    // answer : 15

    // n = 17 
    // not power of 2
    // so 2x-1
    // x = 2^(ceil(log(base2(n))))
    // x = 32
    // answer : 31
    
    // n = 4 
    // power of 2
    // so 2n-1
    // answer : 7 

    // so this overall formula will become
    // 2*2^(ceil(log(base2(n)))) - 1

    // we can directly write 4*n
    // in order to avoid learning
    // this big formula for the size 
    // of segement tree
    
    return 0;
}