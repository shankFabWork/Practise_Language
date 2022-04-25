#include <iostream>

using namespace std;

void Prefix_Sum_one(int arr[],int n,int l,int r)
{
    int sum = 0;
    for(int i=l;i<=r;i++)
    {
        sum += arr[i];
    }
    cout<<sum<<" ";
}

void query(int arr[],int n)
{
    // n is size of array
    int a1=0,a2=2,b1=1,b2=3,c1=2,c2=6;
    
    Prefix_Sum_one(arr,n,a1,a2);
    Prefix_Sum_one(arr,n,b1,b2);
    Prefix_Sum_one(arr,n,c1,c2);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

}


int main()
{
    int arr[] = {2,8,3,9,6,5,4};
    int n=sizeof(arr)/sizeof(int);

    query(arr,n);

    return 0;
}