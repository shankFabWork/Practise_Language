// I/P
// 1 2 3
// 4 5 6
// 7 8 9
// O/P
// 1 2 3 6 9 8 7 4 5

// I/P
// 1 2 3
// 4 5 6
// O/P
// 1 2 3 6 5 4

//    I/P
//    1 2 3 4
//    5 6 7 8
//    9 10 11 12
//    13 14 15 16
//    O/P
//    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

#include <iostream>

using namespace std;

const int r = 3;
const int c = 5;

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

void Spiral_Traversal_of_Matrix(int arr[r][c])
{
    int left = 0,top = 0 ,right = c-1 , bottom = r - 1;

    while(left <= right && top <= bottom)
    {
        for(int i = left;i<=right;i++)
        {
            cout<<arr[top][i]<<" ";
        }
        ++top;
        for(int i = top;i<=bottom;i++)
        {
            cout<<arr[i][right]<<" ";
        }
        --right;

        if(left < right)
        {            
            for(int i=right;i>=left;i--)
            {
                cout<<arr[bottom][i]<<" ";
            }
            --bottom;
        }
        
        if(top < bottom)
        {
            for(int i = bottom;i>=top;i--)
            {
                cout<<arr[i][left]<<" ";
            }
            ++left;
        }
        
    }
}

int main()
{
    int arr[r][c] = {
			{11,12,13,14,15},
			{21,22,23,24,25},
			{31,32,33,34,35}
		};

    // print_matrix(arr);
    Spiral_Traversal_of_Matrix(arr);
    // it will work only on (n*n) matrix
    // Time Complexity -> O(r*c)
    // Space Complexity -> O(1)





}