// I/P
// grid[][] = 
// {
//     {1,0,3,0},
//     {0,0,2,1},
//     {0,1,0,2},
//     {2,4,0,0}
// }
// O/P
// grid[][] = 
// {
//     {1,2,3,4},
//     {4,3,2,1},
//     {3,1,4,2},
//     {2,4,1,3}
// }

// Rule
// 1) Every number in every row is different
// 2) Every number in every column is different
// 3) Every item or every number in every subgrid
// of size 2*2 should also be different 
// 4) Size should always be square
// i.e. N*N and N should be perfect square

#include <iostream>
#include <cmath>
#define N 9

using namespace std;

bool isSafe(int i,int j,int n,int grid[N][N])
{
    for(int k=0;k<N;k++)
    {
        if(grid[k][j] == n || grid[i][k] == n)
        {
            return false;
        }
    }

    int s = sqrt(N);
    int rs = i - i%s;
    int cs = j - j%s;

    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(grid[i+rs][j+cs] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[N][N])
{
    int i,j;
    bool isEmpty = true;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(grid[i][j] == 0)
            {
                isEmpty = false;
                break;
            }
        }  
        if (!isEmpty) 
        { 
            break; 
        }       
    }

    if(isEmpty)  
    { 
        return true; 
    } 

    for(int n=1;n<=N;n++)
    {
        if(isSafe(i,j,n,grid))
        {
            grid[i][j] = n;
            if(solve(grid))
            {
                return true;
            } 
            else
            {
                grid[i][j] = 0;
            }  
        }
    }
    return false;
}

void printMatrix(int grid[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int grid[N][N] =
    { 
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
    };
    if(solve(grid))
    {
        printMatrix(grid);
    }
    else
    {
        cout<<"Wrong sudoku";
    }

    return 0;
}