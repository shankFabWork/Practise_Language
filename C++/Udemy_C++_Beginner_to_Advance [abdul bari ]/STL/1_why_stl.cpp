#include <iostream>

using namespace std;

int main()
{
    //we can not increase size an array 
    //that is why stl is use
    //stack
    int arr1[10];
    //heap
    int *arr2=new int[10];


    for(int i=0;i<4;i++)
    {
        cin>>arr2[i];
    }

    for(int i=0;i<4;i++)
    {
        cout<<arr2[i];
    }

    return 0;
}