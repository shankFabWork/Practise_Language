#include <bits/stdc++.h>

using namespace std;

// I/P
// arr=[2,3,6,7]
// target=7
// O/P
// [[2,2,3],[7]]


void Combination_Sum_1(int arr[],int index,int target,vector <vector <int>> &ans,vector<int> &ds,int n)
{
    if(index == n)
    {
        if(target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(arr[index] <= target)
    {
        ds.push_back(arr[index]);
        Combination_Sum_1(arr,index,target-arr[index],ans,ds,n);
        ds.pop_back();
    }
    Combination_Sum_1(arr,index+1,target,ans,ds,n);
}

int main()
{
    int arr[]={2,3,6,7};
    int target=7;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <vector <int>> ans;
    vector <int> ds;

    Combination_Sum_1(arr,0,target,ans,ds,n);

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