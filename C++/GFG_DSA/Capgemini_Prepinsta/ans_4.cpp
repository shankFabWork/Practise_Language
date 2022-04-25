#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {1,2,3,3,4,1,4,5,1,2};
    int n = sizeof(arr)/sizeof(int);
    // unordered_map <int,int> um;
    // for(int i=0;i<n;i++)
    // {
    //     um[arr[i]]++;
    // } 

    // for(auto data:um)
    // {
    //     cout<<data.first<<" "<<data.second<<endl;
    // }
    int max_elem = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > max_elem)
        {
            max_elem = arr[i];
        }
    }
    int new_n = max_elem+1;
    int new_arr[new_n];
    for(int i=0;i<new_n;i++)
    {
        new_arr[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        new_arr[arr[i]]++;
    }
    for(int i=0;i<new_n;i++)
    {
        if(new_arr[i] != 0)
        {
            cout<<i<<" "<<new_arr[i]<<endl;
        }
    }


    return 0;
}