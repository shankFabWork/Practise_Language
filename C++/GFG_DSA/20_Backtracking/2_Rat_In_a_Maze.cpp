// I/P
// maze[][] =
//         { 
//             {1,0,0,0},
//             {1,1,0,1},
//             {0,1,0,0},
//             {1,1,1,1}
//         };
// O/P
// Yes

// I/P
// maze[][] =
//         { 
//             {1,0,0},
//             {0,1,0},
//             {1,1,1}
//         };
// O/P
// No

// Rat is at top-left
// Cheese is at bottom-right
// "0" is the blocked cell
// "1" is the empty space
// rat can only go to only pass through 1
// in order to get a cheese

// Only two moves allowed from (i,j)
// 1) (i+1,j) -> cell just below it
// 2) (i,j+1) -> cell on the right side


#include <iostream>
#define N 4

using namespace std;

void printMatrix(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }      
        cout<<endl;  
    }
}

// we have 3 functions
// solveMaze (main functions)
// solveMazeRec
// isSafe

bool isSafe(int maze[N][N],int i,int j)
{   
    return (i<N)&&(j<N)&&(maze[i][j] == 1);
}

bool solveMazeRec(int maze[N][N],int sol[N][N],int i,int j)
{
    if(i == N-1 && j == N-1)
    {
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(maze,i,j) == true)
    {
        sol[i][j] = 1;
        if(solveMazeRec(maze,sol,i,j+1) == 1)
        {
            return true;
        }
        if(solveMazeRec(maze,sol,i+1,j) == 1)
        {
            return true;
        }
    }
    return false;
}

void solveMaze(int maze[N][N])
{
    int sol[N][N] = {
        {0,0,0},    
        {0,0,0},
        {0,0,0}
    };
    if(solveMazeRec(maze,sol,0,0) == true)
    {
        cout<<"Rat can get cheese"<<endl;
        printMatrix(sol);
    }   
    else
    {
        cout<<"Rat can not get cheese"<<endl;
    }
}

int main()
{
    // if array is 1d array
    // we need not to give indexes
    // if array is 2d array
    // we have to give indexes

    int maze[N][N] ={ 
                    {1,1,1},
                    {1,0,1},
                    {1,1,1}
                };

    // int maze[N][N] =
    //         { 
    //             {1,0,0},
    //             {0,1,0},
    //             {1,1,1}
    //         };

    solveMaze(maze);

    return 0;
}