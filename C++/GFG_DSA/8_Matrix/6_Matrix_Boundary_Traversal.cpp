// I/P
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// O/P
// 1 2 3 4 8 12 16 15 14 13 9 5

// I/P
// 1 2 3 4
// 5 6 7 8
// O/P
// 1 2  4 8 7 6 5

// I/P
// 1 2 3 4
// O/P
// 1 2 3 4

// I/P
// 1 2 3 
// O/P
// 1 2 3 

// I/P
// 1 2
// 3 4
// 5 6
// O/P
// 1 2 4 6 5 3 


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int r = 4;
    int c = 4;
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


    // Time Complexity -> O(r+c)

    // corner case 
    // when r == 1
    // when c == 1
    if(r == 1)
    {
        for(int i=0;i<c;i++)
        {
            cout<<arr[0][i]<<" ";
        }
    }

    else if(c == 1)
    {
        for(int i=0;i<r;i++)
        {
            cout<<arr[i][0]<<" ";
        }
    }
    
    else
    {
        for(int i=0;i<c;i++)
        {
            cout<<arr[0][i]<<" ";
        }
        for(int i=1;i<r;i++)
        {
            cout<<arr[i][c-1]<<" ";
        }
        for(int i=c-2;i>=0;i--)
        {
            cout<<arr[r-1][i]<<" ";
        }
        for(int i=r-2;i>=1;i--)
        {
            cout<<arr[i][0]<<" ";
        }
    }

    return 0;
}