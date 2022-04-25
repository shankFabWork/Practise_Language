// I/P
// N = 5
// O/P
// Yes
// 1 0 0 0 0
// 0 0 0 1 0
// 0 1 0 0 0
// 0 0 0 0 1
// 0 0 1 0 0

// I/P
// N = 4
// O/P
// Yes
// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// I/P
// N = 3
// O/P
// No

// we will cut down the recursion tree
// as soon as we find infeasibility

#include <iostream>
// we can place N*N
// where n is defined here 
#define N 4

using namespace std;

bool board[N][N];

void printMatrix()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row,int col)
{
    // checking all element of row for clashing
    for(int i=0;i<col;i++)
    {
        if(board[row][i] == 1)
        {
            return false;
        }
    }
    // checking all element of upper diagonal for clashing
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    // checking all element of lower diagonal for clashing
    for(int i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool solveRec(int col)
{
    if(col == N)
    {
        return true;
    }
    for(int i=0;i<N;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col] = 1;
            if(solveRec(col+1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

bool solve(int col)
{
    if(solveRec(col) == false)
    {
        cout<<"Chess with this length is not possible";
        return false;
    }
    else
    {
        printMatrix();
        return true;
    }
}

int main()
{
    // it sprecifies the column number from where 
    // we want to start
    // if u will write '1' here , it means it 
    // will start from 1th index column
    solve(0);
    // solve(0);

    return 0;
}