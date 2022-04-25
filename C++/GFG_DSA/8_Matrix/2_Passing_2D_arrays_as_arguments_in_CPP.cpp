#include <iostream>

using namespace std;

// void print_matirx(int arr[][],int m,int n)
// not allowed as second indices can not be empty
// first indices in 2-d array can be omitted
// we can not pass argumnet in that
// so it is impossible
// or

void print_matirx(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

int main()
{
    int m=3,n=2;

    // 2d array using double pointer
    // (this is better)
    int **arr;
    arr = new int * [m];
    for(int i=0;i<m;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 10;
        }
    }

    // 2d array using single pointer
    // int *arr[m];
    // for(int i=0;i<m;i++)
    // {
    //     arr[i] = new int[n];
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j] = 10;
    //     }
    // }


    print_matirx(arr,m,n);


    return 0;
}