#include <iostream>
#include <climits>

using namespace std;

int main()
{

    int arr[]={0,-1,7,1,2,3,4};
    int n=sizeof(arr)/sizeof(int);
    // int min=arr[0];
    int min=INT_MAX;
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout<<min;

    return 0;
}