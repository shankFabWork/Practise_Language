#include <iostream>
#include <vector>

using namespace std;

// I/P
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// O/P
// 1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13


// I/P
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// O/P
// 1 2 3 4 8 7 6 5 9 10 11 12 

void print_matrix_one(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

void print_matrix_two(int *arr[],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

void print_matrix_three(vector <vector<int>> v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0;i<v.size();i++)
    {
        if(i%2 == 0)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
            }            
        }
        else
        {
            for(int j=v[i].size()-1;j>=0;j--)
            {
                cout<<v[i][j]<<" ";
            }                        
        }
    }
}

int main()
{
    int m=4;
    int n=3;

    // Ist method (double pointer)
    // int **arr;
    // arr = new int *[m];
    // for(int i=0;i<m;i++)
    // {
    //     arr[i] = new int[n];
    // }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j] = 10;
    //     }
    // }
    // print_matrix_one(arr,m,n);


    // IInd method (array of pointer)
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
    //     }
    // }
    // print_matrix_two(arr,m,n);

    // IIInd method (vector of vector)
    
    int list[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int index = 0;

    vector <vector<int>> v;
    for(int i=0;i<m;i++)
    {
        vector <int> arr;
        for(int j=0;j<n;j++)
        {
            arr.push_back(list[index++]);
        }
        v.push_back(arr);
    }
    print_matrix_three(v);
    // TimeComplexity -> O(r*c)


    
    return 0;
}