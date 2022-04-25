// 1) Used for fixed sized arrays 
// i.e. no of elements do not change
// and following two types of operations
// (a) Range Query : O(log(n))
// (b) Update a value : O(log(n))
// 2) Requires O(n) preprocessing time 
// and O(n) auxiliary space

#include <iostream>

using namespace std;


int getSum(int arr[],int qs,int qe)
{
    int sum = 0;
    for(int i=qs;i<=qe;i++)
    {
        sum += arr[i];
    }
    return sum;
}

void update(int arr[],int index,int val)
{
    arr[index] = val;
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);

    // 1) Simple Method
    cout<<getSum(arr,0,2)<<" ";
    // Time Complexity -> O(qe-qs+1)
    cout<<getSum(arr,1,3)<<" ";
    update(arr,1,60);
    // Time Complexity -> O(1)
    cout<<getSum(arr,0,2)<<" ";
    cout<<getSum(arr,1,3)<<" ";

    return 0;
}