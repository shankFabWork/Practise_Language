#include <iostream>
#include <vector>

using namespace std;

// Important Points

// 1) elements are stored in row-major order
// int arr[3][2] = {
//     {10,20},
//     {30,40},
//     {50,60}
// };
// still it will be stored like this
//  10  20  30  40  50  60
// 200 204 208 212 216 220

// 2) internal curly braces are optionl
// int arr[3][2] = {10,20,30,40,50,60}
// int arr[3][2] = {
//     {10,20},
//     {30,40},
//     {50,60}
// };

// 3) only the first dimension can be omitted when we initialize
//     int arr[][2] = {{1,2},{3,4}}
//     int arr[][4] = {{1,2,4,5},{9,7,10,2},{48,10,3,1}}
        
int main()
{

    // fixed size array
    // int arr[3][2] = {{10, 20},
    //                  {30, 40},
	// 				    {50, 60}};

	// for(int i = 0; i < 3; i++)
	// {
	// 	for(int j = 0; j < 2; j++)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// }

    // 1) way to create multi-dimensional array in c++
    // using double pointer
    // allocated in heap

    // int m = 3; // row
    // int n = 2; // column
    // int **arr;

    // arr = new int * [m];
    // for(int i=0;i<m;i++)
    // {
    //     arr[i] = new int[n];
    // }

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j] = 10;
    //         cout<<arr[i][j]<<" ";
    //     }
    // }

    // 2) way to create multi-dimensional array in c++
    // array of pointer
    // allocated in stack

    // int m = 3; // row
    // int n = 2; // column
    // int *arr[m];

    // for(int i=0;i<m;i++)
    // {
    //     arr[i] = new int[n];
    // }

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j] = 10;
    //         cout<<arr[i][j]<<" ";
    //     }
    // }

    // 3) way to create multi-dimensional array in c++
    //  array of vector



    // int m = 3; // row
    // int n = 2; // column
    // vector <int> arr[m];

    // * *
    // * *
    // * *

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i].push_back(10);
    //         cout<<arr[i][j]<<" ";
    //     }
    // }

    // 4) way to create multi-dimensional array in c++
    //  vector of vector

    int m = 3; // row
    int n = 2; // column

    // vector of vector are called jagged array as
    // we can increase or decrease the number of 
    // rows and columns accordingly
    vector <vector<int>> arr;

    for(int i=0;i<m;i++)
    {
        vector <int> v;
        for(int j=0;j<n;j++)
        {

            v.push_back(10);
        }
        arr.push_back(v);
    }

    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }

    return 0;
}