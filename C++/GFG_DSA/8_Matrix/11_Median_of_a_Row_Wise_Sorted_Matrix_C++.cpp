// I/P
// int r = 3, c = 3;
// int m[r][c] = { 
//     {1,10,20}, 
//     {15,25,35}, 
//     {5,30,40}, 
// };
// O/P
// 20
// 1 5 10 15 20 25 30 35 40 

// I/P
// int r = 3, c = 5;
// int m[r][c] = { 
//     {2,4,6,8,10}, 
//     {1,3,5,7,9}, 
//     {100,200,400,500,800} 
// };
// O/P
// 8   
// 1 2 3 5 6 7 8 9 10 100 200 400 500 800

// Assumptions
// 1) Odd Sized Matrix (3*3,3*5)
// 2) All Distict Element

#include <iostream>
#include <algorithm>

using namespace std;

const int r = 3;
const int c = 5;

int Median_of_a_Row_Wise_Sorted_Matrix_one(int mat[r][c])
{
    int arr[r*c];
    int k = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[k] = mat[i][j];
            k++;
        }
    }
    sort(arr,arr+k);
    // n.log(n)
    // i.e. r*c*log(r*c)
    int median_index = (k/2+1)-1;
    // r*c = k is odd
    return arr[median_index];
}

int Median_of_a_Row_Wise_Sorted_Matrix_two(int mat[r][c])
{
    int min = mat[0][0];
    int max = mat[0][c-1];
    for(int i=0;i<r;i++)
    {
        if(min > mat[i][0])
        {
            min = mat[i][0];
        }
    }
    for(int i=0;i<r;i++)
    {
        if(max < mat[i][c-1])
        {
            max = mat[i][c-1];
        }
    }
    int median_pos = (r*c+1)/2;
    while(min < max)
    {
        int mid = (min+max)/2;
        int mid_pos = 0;
        for(int i=0;i<r;i++)
        {
            mid_pos += upper_bound(mat[i],mat[i]+c,mid)-mat[i];
        }
        if(median_pos > mid_pos)
        {
            min = mid+1;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}

int main()
{
    int mat[r][c]= { 
        {5,10,20,30,40}, 
        {1,2,3,4,6}, 
        {11,13,15,17,19} 
    };
    cout<<Median_of_a_Row_Wise_Sorted_Matrix_one(mat);
    // n.log(n)
    // i.e. r*c*log(r*c)
    cout<<endl;
    cout<<Median_of_a_Row_Wise_Sorted_Matrix_two(mat);
    // answer is in either
    // first column or in last column
    // TC - O(r * log(max - min) * log(c))
    // max -> maximum element
    // min -> minimum element
}

//  2   4   6   8   10  
//  1   3   5   7   9  
//  100 200 400 500 800 

// min = 1 , max = 800 , median_pos = (15+1)/2 = 8
// (1,800) , mid = 400 , mid_pos = 5+5+3 = 13
// (1,400) , mid = 200 , mid_pos = 5+5+2 = 12
// (1,200) , mid = 100 , mid_pos = 5+5+1 = 11
// (1,100) , mid = 50 , mid_pos = 5+5+1 = 11
// (1,50) , mid = 25 , mid_pos = 5+5+1 = 11
// (1,25) , mid = 12 , mid_pos = 5+5+1 = 11
// (1,12) , mid = 6 , mid_pos = 3+3+1 = 7
// (7,12) , mid = 9 , mid_pos = 4+5+1 = 10
// (7,9) , mid = 8 , mid_pos = 4+4+1 = 9
// (7,8) , mid = 7 , mid_pos = 3+4+0 = 7
// (8,8) , while(min < max) condition voilates
// return min => 8
// 1 2 3 4 5 6 7 8 9 10 100 200 400 500 800
// median_pos = 8

// 5 10 20 30 40 
// 1  2  3  4  6
// 11 13 15 17 19

// min = 1 , max = 40 , median_pos = 8
// (1,40) , mid = 20 , mid_pos = 3+5+5 = 13
// (1,20) , mid = 10 , mid_pos = 3+5+5 = 13
// (1,11) , mid = 5 , mid_pos = 1+4+1 = 6
// (6,11) , mid = 8 , mid_pos = 1+5+0 = 6
// (9,11) , mid = 10 , mid_pos = 2+5+0 = 7
// (11,11) , while(min < max) condition voilates
// return min => 11
// 1 2 3 4 5 6 10 11 13 15 17 19 20 30 40 
//median_pos = 8
// 11