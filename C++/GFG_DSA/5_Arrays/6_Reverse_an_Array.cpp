#include <iostream>

using namespace std;

int main()
{
    int arr[]={6,1,8,3,7};

    int start=0;
    int end=sizeof(arr)/sizeof(int)-1;
    int temp=0;
    int n=end;

    while(start < end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }

    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    return 0;
}