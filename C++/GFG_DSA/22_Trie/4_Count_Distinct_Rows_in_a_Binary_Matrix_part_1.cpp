#include <iostream>

using namespace std;

int main()
{
    // in c++ , 2d array
    // number of columns mentioning
    // is neccessory

    // int n = 3;
    // int m = 3;
    // int mat[n][m] = {
    //     {1,0,0},
    //     {1,1,1},
    //     {1,0,0},
    //     {1,1,1}
    // };

    int n = 3;
    int m = 4;
    int mat[n][m] = 
    {
        {1,0,0,0},
        {1,1,1,1},
        {1,1,1,1}
    };

    int no_of_distinct = 0;
    for(int i=0;i<n;i++)
    {
        int j;
        int k = 0;
        for(int k=0;k<m;k++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j] != mat[i+k+1][j])
                {
                    break;
                }
            }
            if(j == m)
            {
                no_of_distinct++;
            }
        }
    }
    cout<<no_of_distinct;
    // TC - O(n*m*m)
    // SC - O(m*n)

}