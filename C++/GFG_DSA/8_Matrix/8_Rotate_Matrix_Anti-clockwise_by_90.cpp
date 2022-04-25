// I/P
// 1 2 3
// 4 5 6
// 7 8 9
// O/P
// 3 6 9
// 2 5 8
// 1 4 7

// I/P
// 1 2 3 4
// 5 6 7 8
// O/P
// 4 8
// 3 7
// 2 6
// 1 5

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

// I/P
// 1 2 3
// 4 5 6
// 7 8 9
// O/P
// 3 6 9
// 2 5 8
// 1 4 7
void Rotate_Matrix_Anti_clockwise_by_90_one(int arr[r][c])
{
    int temp[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            temp[r-j-1][i] = arr[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
    print_matrix(arr);
}

void swap_val(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Rotate_Matrix_Anti_clockwise_by_90_two(int arr[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
        {
            swap_val(arr[i][j],arr[j][i]);
        }
    }
    // for(int i=0;i<r/2;i++)
    // {
    //     for(int j=0;j<c;j++)
    //     {
    //         swap_val(arr[i][j],arr[r-i-1][j]);
    //     }
    // }
    // or

    for(int i=0;i<r;i++)
    {
        int low = 0;
        int high = c-1;
        while(low < high)
        {
            swap_val(arr[low][i],arr[high][i]);
            low++;
            high--;
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

    // 1 5 9 13
    // 2 6 10 14
    // 3 7 11 15
    // 4 8 12 16

    // 4 8 12 16
    // 3 7 11 15
    // 2 6 10 14
    // 1 5 9 13

    print_matrix(arr);
    
    // Naive Solution 
    // Rotate_Matrix_Anti_clockwise_by_90_one(arr);
    // Last column becomes first row
    // Second last column becomes second row
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(r*c)

    // this is inplace 
    // i.e. do not require an extra space
    Rotate_Matrix_Anti_clockwise_by_90_two(arr);
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(1)

    // I/P
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16

    // (Transpose)
    //     ||
    //    \  /
    //     \/

    // 1 5 9 13
    // 2 6 10 14
    // 3 7 11 15
    // 4 8 12 16

    // (make 1st row as last row)
    // (make 2nd row as 2nd last row)
    //     ||
    //    \  /
    //     \/

    // 4 8 12 16
    // 3 7 11 15
    // 2 6 10 14
    // 1 5 9 13




    return 0;
}
