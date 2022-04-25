// I/P
// {{6,2},{4,3},{2,6},{1,5}}
// O/P
// 2

// I/P
// {{8,1},{1,2},{4,3},{3,4},{2,6},{6,7},{7,8},{5,5}}
// O/P
// 5


// Steps involved :: 
// 1) Sort the array in ascending order of first value of value
// and if two first values are same like (2,6) and (2,3)
// then consider second value

// 2) find lis of sorted array according to second value
#include <bits/stdc++.h>

using namespace std;

bool myComp(pair <int,int> a,pair <int,int> b)
{
    if(a.first == b.first)
    {
        return (a.second < b.second);
    }
    return (a.first < b.first);
}

int ceil_index(int lis[],int l,int elem)
{
    int s = 0;
    int e = l-1;
    while(s < e)
    {
        int mid = s+(e-s)/2;
        if(lis[mid] >= elem )
        {
            e = mid;
        }
        else
        {
            s = mid+1;
        }
    }
    return e;
}

int lis(vector <int> arr)
{
    int n = arr.size();
    int lis[n];
    lis[0] = arr[0];
    int l = 1;
    for(int i=1;i<n;i++)
    {
        if(lis[l-1] < arr[i])
        {
            lis[l] = arr[i];
            l++;
        }
        else    
        {
            int index = ceil_index(lis,l,arr[i]);
            lis[index] = arr[i];
        }
    }
    return l;
}

int main()
{
    // vector <pair<int,int>> v = {{6,2},{4,3},{2,6},{1,5}};
    // vector <pair<int,int>> v = {{8,1},{1,2},{4,3},{3,4},{5,5},{2,6},{6,7},{7,8}};
    vector <pair<int,int>> v = {{8,1},{1,2},{4,3},{3,4},{3,2},{5,5},{2,6},{6,7},{7,8}};
    // here {3,4} and {3,2} has same first so 
    // we will sort same first in ascending order
    // and will get {3,2} and {3,4}
    sort(v.begin(),v.end(),myComp);
    // O(n.log(n))

    vector <int> arr;
    // for(auto elem:v)
    // {
    //     cout<<elem.first<<" "<<elem.second<<endl;
    // }

    for(auto itr = v.begin();itr != v.end();itr++)
    {
        arr.push_back(itr->second);
    }
    cout<<lis(arr);
    // O(n.log(n))
    

    // so Time Complexity -> O( n.log(n) + n.log(n) ) = O(n.log(n))

}