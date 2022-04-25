/* C++ program to solve Rat in
a Maze problem using backtracking */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int N;

size_t **maze;
size_t **sol;

size_t start_r;
size_t start_c;
size_t end_r;
size_t end_c;

void printSolution()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}


bool isSafe(int x, int y)
{
	if (
		x >= 0 && x <= end_r && y >= 0
		&& y <= end_c && maze[x][y] == 1)
		{
			return true;
		}
	return false;
}


bool solveMazeUtil(int x,int y)
{
	if (x == end_r && y == end_c && maze[x][y] == 1) 
	{
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(x, y) == true) 
	{
		if (sol[x][y] == 1)
			return false;
	
		sol[x][y] = 1;

		if (solveMazeUtil(
				x + 1, y)
			== true)
			return true;

		if (solveMazeUtil(
				x, y + 1)
			== true)
			return true;
	
		if (solveMazeUtil(
				x - 1, y)
			== true)
			return true;

		if (solveMazeUtil(
				x, y - 1)
			== true)
			return true;

		sol[x][y] = 0;
		return false;
	}

	return false;
}

bool solveMaze()
{

	if (solveMazeUtil(0, 0) == false) 
	{
		cout<<"Solution doesn't exist";
		return false;
	}
	printSolution();

	return true;
}


int main()
{
    string m = "111101111";
    size_t r = 3;
    size_t c = 3;
    string start = "0,0";
    string cheese = "1,2";


	N = r;
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

    start_r = stoi(result_1[0]); 
    start_c = stoi(result_1[1]);
    end_r = stoi(result_2[0]);
    end_c = stoi(result_2[1]);



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

    if(end_r >= r || end_c >= c || start_r < 0 || start_c < 0 || maze[start_r][start_c] == 0)
    {
        return -1;
    }
	// start_r,start_c,end_r,end_c
    if(solveMaze() == true)
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
