#include <bits/stdc++.h>

using namespace std;

//  I/P
// arr[] = {10,1,2,7,6,1,5}
// target = 8
// O/P
// [
//     [1,1,6],
//     [1,2,5],
//     [1,7],
//     [2,6]
// ]

//  I/P
// arr[] = {2,5,2,1,2}
// target = 5   
// O/P
// [
//     [1,2,2],
//     [5],
// ]

void Combination_Sum_2(int arr[],int n,int index,int target,vector <int> &ds,vector <vector<int>> &ans)
{
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<n;i++)
    {
        if(arr[i] == arr[i-1] && i>index) continue;
        if(target < arr[i]) break;
        ds.push_back(arr[i]);
        Combination_Sum_2(arr,n,index+1,target-arr[i],ds,ans);
        ds.pop_back();
    }
}


int main()
{
    int arr[] = {10,1,2,7,6,1,5};
    int target = 8;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    vector <int> ds;
    vector <vector<int>> ans;
    sort(arr,arr+n);
    Combination_Sum_2(arr,n,0,target,ds,ans);


    for(auto i : ans)
    {
        for(int j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}