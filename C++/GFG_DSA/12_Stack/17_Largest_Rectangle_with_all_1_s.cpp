// I/P
// mat[] = {{0,1,1,0},
//         {1,1,1,1},
//         {1,1,1,1},
//         {1,1,0,0}}
// O/P
// 8

// I/P
// mat[] = {{0,1,1},
//         {1,1,1},
//         {0,1,1}}
// O/P
// 6

// I/P
// mat[] = {{0,0},
//         {0,0}}
// O/P
// 0

// I/P
// mat[] = {{0,0},
//         {0,1}}
// O/P
// 1

// I/P
// mat[] = {{1,1,1}}
// O/P
// 3

#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>
#define R 4
#define C 4

using namespace std;

int Largest_Rectangular_Area_in_Histogram_1(int arr[][C],int row_no)
{
    int res = INT_MIN;
    for(int i=0;i<R;i++)
    {
        int curr = arr[row_no][i];
        for(int j=i-1;j>=0;j--)
        {
            if(arr[row_no][j] >= arr[row_no][i])
            {
                curr = curr+arr[row_no][i];
            }
            else
            {
                break;
            }            
        }
        for(int j=i+1;j<R;j++)
        {
            if(arr[row_no][j] >= arr[row_no][i])
            {
                curr = curr+arr[row_no][i];
            }
            else
            {
                break;
            }            
        }
        res = max(res,curr);
    }
    return res;
}

int Largest_Rectangular_Area_in_Histogram_2(int arr[])
{
    int res = INT_MIN;
    for(int i=0;i<R;i++)
    {
        int curr = arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] >= arr[i])
            {
                curr = curr+arr[i];
            }
            else
            {
                break;
            }            
        }
        for(int j=i+1;j<R;j++)
        {
            if(arr[j] >= arr[i])
            {
                curr = curr+arr[i];
            }
            else
            {
                break;
            }            
        }
        res = max(res,curr);
    }
    return res;
}

int Largest_Rectangular_Area_in_Histogram_3(int arr[])
{
    vector <int> ps;
    stack <int> s;
    s.push(0);
    // cout<<-1<<" ";
    ps.push_back(-1);
    for(int i=1;i<R;i++)
    {
        while(s.empty() != true && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        int prevGre = (s.empty() == true)?-1:s.top();
        // cout<<prevGre<<" ";
        ps.push_back(prevGre);
        s.push(i);
    }

    stack <int> s2;
    vector <int> ns;

    s2.push(R-1);
    // cout<<n<<" ";
    ns.push_back(R);
    for(int i = R-2;i >=0;i--)
    {
        while(s2.empty() != true && arr[s2.top()] >= arr[i])
        {
            s2.pop();
        }
        int nextGre = (s2.empty() == true)?R:s2.top();
        // cout<<nextGre<<" ";
        ns.push_back(nextGre);
        s2.push(i);
    }
    reverse(ns.begin(),ns.end());
    cout<<endl;

    int max_val = INT_MIN;
    for(int i=0;i<R;i++)
    {
        int curr = arr[i];
        curr += (i-ps[i]-1)*arr[i];
        curr += (ns[i]-i-1)*arr[i];
        max_val = max(max_val,curr);
    }
    // cout<<max_val;
    return max_val;
}

int main()
{
    int mat[][R] = {{0,1,1,0},
                    {1,1,1,1},
                    {1,1,1,1},
                    {1,1,0,0}};
    // int res = Largest_Rectangular_Area_in_Histogram_1(mat,0);
    // int res = Largest_Rectangular_Area_in_Histogram_2(mat[0]);
    int res = Largest_Rectangular_Area_in_Histogram_3(mat[0]);
    // cout<<res<<endl;
    int max_Res = INT_MIN;
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j] == 1)
            {
                mat[i][j] = mat[i-1][j]+1;
            }
        }
        // in this we pass the whole 2D matrix
        // res = Largest_Rectangular_Area_in_Histogram_1(mat,i);
        // in this we pass the 1D matrix of 2D matrix "Row Wise"
        // res = Largest_Rectangular_Area_in_Histogram_2(mat[i]);
        res = Largest_Rectangular_Area_in_Histogram_3(mat[i]);
        // cout<<res<<endl;
        max_Res = max(max_Res,res);
    }
    cout<<max_Res;
    // TC - O(R*C)
    // SC - O(R*C)

    return 0;
}