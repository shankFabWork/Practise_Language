#include <bits/stdc++.h>

using namespace std;

size_t **maze;
size_t **sol;

bool isSafe(size_t i,size_t j,size_t end_r,size_t end_c)
{   
    return (i<=end_r)&&(j<=end_c)&&(maze[i][j] == 1);
}

void printSolution()
{
    for (int i = 0; i < ; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool solveMazeRec(size_t i,size_t j,size_t end_r,size_t end_c)
{
    if(i == end_r && j == end_c )
    {
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(i,j,end_r,end_c) == true)
    {
        sol[i][j] = 1;
        if(solveMazeRec(i,j+1,end_r,end_c) == 1)
        {
            return true;
        }
        if(solveMazeRec(i+1,j,end_r,end_c) == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string m = "111101111";
    size_t r = 3;
    size_t c = 3;
    string start = "0,0";
    string cheese = "1,2";
    
    vector<string> result_1;
    stringstream s_stream_1(start); 
    while(s_stream_1.good()) 
    {
        string substr_1;
        getline(s_stream_1, substr_1, ','); 
        result_1.push_back(substr_1);
    }

    
    vector<string> result_2;
    stringstream s_stream_2(cheese); 
    while(s_stream_2.good()) 
    {
        string substr_2;
        getline(s_stream_2, substr_2, ','); 
        result_2.push_back(substr_2);
    }

    size_t start_r = stoi(result_1[0]); 
    size_t start_c = stoi(result_1[1]);
    size_t end_r = stoi(result_2[0]);
    size_t end_c = stoi(result_2[1]);






    if(end_r >= r || end_c >= c || start_r >= r || start_c >= c)
    {
        return -1;
    }

    size_t counter = 0;
    maze = new size_t*[r];
    for(size_t i=0;i<r;i++)
    {
        maze[i] = new size_t[c];
        for(size_t j=0;j<c;j++)
        {
            char data = m[counter++];
            maze[i][j] = (size_t)data - 48;
        }
    }


    
    sol = new size_t*[r];
    for(size_t i=0;i<r;i++)
    {
        sol[i] = new size_t[c];
        for(size_t j=0;j<c;j++)
        {
            sol[i][j] = 0;
        }
    }
    if(solveMazeRec(start_r,start_c,end_r,end_c) == true)
    {
        size_t count_1 = 0;
        for(size_t i=0;i<r;i++)
        {
            for(size_t j=0;j<c;j++)
            {
                if(sol[i][j] == 1)
                {
                    count_1++;
                }
            }
        }
        cout<<count_1;
    }   
    else
    {
        return -1;
    }
    


    return 0;
}