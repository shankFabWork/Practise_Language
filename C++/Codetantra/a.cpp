#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

size_t N;

size_t **maze;
size_t **sol;

bool solveMazeUtil(size_t x,size_t y);

void printSolution()
{
	for (size_t i = 0; i < N; i++) 
    {
		for (size_t j = 0; j < N; j++)
        {
            cout<<sol[i][j];
        }
		cout<<"\n"  ;
	}
}


bool isSafe(size_t x, size_t y)
{

	if(
		x >= 0 && x < N && y >= 0
		&& y < N && maze[x][y] == 1
    )
    {
		return true;
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


bool solveMazeUtil(size_t x,size_t y)
{
	
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) 
    {
		sol[x][y] = 1;
		return true;
	}


	if (isSafe(x, y) == true) 
    {
		
		if (sol[x][y] == 1)
        {
			return false;
        }
	
		sol[x][y] = 1;

		
		if (solveMazeUtil( x + 1, y) == true)
        {
			return true;
        }

		
		if (solveMazeUtil( x, y + 1) == true)
        {
			return true;
        }
	
		if (solveMazeUtil( x - 1, y) == true)
        {
			return true;
        }

		if (solveMazeUtil( x, y - 1) == true)
        {
			return true;
        }

		sol[x][y] = 0;
		return false;
	}

	return false;
}

int main()
{
    string m = "111101111";
    size_t r = 3;
    size_t c = 3;
    N = r;
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

	solveMaze();
	return 0;
}
