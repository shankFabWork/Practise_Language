
// I/P->

// O/P->

#include <iostream>

using namespace std;

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i != n-1)
        {
            cout<<'-';
        }
    }
}

int main()
{
    int arr[]={};
    int n=sizeof(arr)/sizeof(int);


    //Time Complexity -> 
    //Space Complexity -> 



    print_array(arr,n);

    return 0;
}


