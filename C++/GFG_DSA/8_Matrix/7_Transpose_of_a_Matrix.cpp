// I/P
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// O/P
// 1 5 9 13
// 2 6 10 14
// 3 7 11 15
// 4 8 12 16

#include <iostream>

using namespace std;

const int r = 4;
const int c = 4;

void print_matrix(int arr[r][c])
{
    cout<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Transpose_of_a_Matrix_one(int arr[r][c])
{
    int new_arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            new_arr[j][i] = arr[i][j];
        }
    }
    print_matrix(new_arr);
}

void swap_val(int *a,int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void Transpose_of_a_Matrix_two(int arr[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
        {
            swap_val(&arr[i][j],&arr[j][i]);
        }
    }
    print_matrix(arr);
}

int main()
{
    int arr[r][c] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    Transpose_of_a_Matrix_one(arr);
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(r*c)


    Transpose_of_a_Matrix_two(arr);
    // do not require addition 2d matrix
    // for storing
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(1)

    // I/P
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16

    // O/P
    // 1 5 9 13
    // 2 6 10 14
    // 3 7 11 15
    // 4 8 12 16

    // here 1 6 11 16 are unchanged 
    // they will always be same

    return 0;
}