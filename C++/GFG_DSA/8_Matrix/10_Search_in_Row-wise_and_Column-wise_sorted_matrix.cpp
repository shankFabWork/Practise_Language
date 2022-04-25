#include <iostream>

using namespace std;

    // I/P
    // int arr[4][4] =
    // {
    //     {10,20,30,40},
    //     {15,25,35,45},
    //     {27,29,37,48},
    //     {32,33,39,50}
    // }; 
    // x = 29
    // O/P
    // Found at (2,1)

    
    // I/P
    // int arr[2][2] =
    // {
    //     {10,20},
    //     {12,30}
    // }; 
    // x = 15
    // O/P
    // Not Found

const int r = 4;
const int c = 4;

void print_matrix(int mat[r][c])
{
    cout<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Search_in_Row_wise_and_Column_wise_sorted_matrix_one(int mat[r][c],int elem)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j] == elem)
            {
                cout<<elem<<" found at position ("<<i<<","<<j<<")";
                return;
            }
        }
    }
    cout<<"element not found ";
}

void Search_in_Row_wise_and_Column_wise_sorted_matrix_two(int mat[r][c],int elem)
{
    // we will start from top right
    int i = 0;
    int j = c-1;

    while(i<r && j>=0)
    {
        if(mat[i][j] == elem)
        {
            cout<<elem<<" -> found at position ("<<i<<","<<j<<")";
            return;
        }
        else if(mat[i][j] > elem)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout<<elem<<" -> Not Found";
}

int main()
{
    // matrix is alredy sorted
    // matrix is Row_wise_and_Column_wise_sorted_matrix
    int mat[r][c] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    print_matrix(mat);
    // Search_in_Row_wise_and_Column_wise_sorted_matrix_one(mat,29);
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(1)

    // Efficient Solution
    Search_in_Row_wise_and_Column_wise_sorted_matrix_two(mat,29);
    // Search_in_Row_wise_and_Column_wise_sorted_matrix_two(mat,100);
    // Time Complexity -> O(r+c)
    // Space Complexity -> O(1)

    
    return 0;
}
