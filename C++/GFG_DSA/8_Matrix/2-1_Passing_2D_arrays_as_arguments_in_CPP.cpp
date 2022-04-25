#include <iostream>
#include <vector>

using namespace std;

void print_matrix_1(vector <int> v[],int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    }
}

void print_matrix_2(vector <vector<int>> v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int index =sizeof(arr)/sizeof(int) - 1;
    int m=3,n=2;

    // // vector <int> v[m];
    // // for(int i=0;i<m;i++)
    // // {
    // //     for(int j=0;j<n;j++)
    // //     {
    // //         v[i].push_back(arr[index--]);
    // //     }
    // }
    // print_matrix_1(v);
    // first row will contain all zeros
    // second row will contain all ones
    
    vector <vector<int>> v;
    for(int i=0;i<m;i++)
    {
        vector <int> arr;
        for(int j=0;j<n;j++)
        {
            arr.push_back(10);
        }
        v.push_back(arr);
    }

    print_matrix_2(v);


    return 0;
}