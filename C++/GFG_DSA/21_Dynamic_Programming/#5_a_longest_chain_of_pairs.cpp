// I/P
// {{5,24},{39,60},{15,28},{27,40},{50,90}}
// O/P
// 3
// {5,24},{27,40},{50,90}

// I/P
// {{6,8},{3,4}}
// O/P
// 2

// pair -> (a,b) 
// where a < b
// (a,b) and (c,d)
// a < b and c < d
// and also b < c

// Trick :
// 1) sort array of pair according to the first value
// 2) find lis according to second of the sorted array 

#include <bits/stdc++.h>

using namespace std;

bool myComp(pair <int,int> a,pair  <int,int> b)
{
    return a.first > b.second;
}

int ceil_index(int lis[],int l,int elem)
{
    int s = 0;
    int e = l-1;
    while(s < e)
    {
        int mid = (s+e)/2;
        if(lis[mid] >= elem)
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

int lis(vector <int> v)
{
    int n = v.size();
    int lis[n];
    int l = 1;
    for(int i=1;i<n;i++)
    {
        if(lis[l-1] < v[i])
        {
            lis[l] = v[i];
            l++;
        }
        else
        {
            int index = ceil_index(lis,l,v[i]);
            lis[index] = v[i];
        }
    }
    return l;
}

int main()
{
    vector <pair<int,int>> v = {{5,24},{39,60},{15,28},{27,40},{50,90}};
    int n = sizeof(v)/sizeof(v[0]);

    sort(v.begin(),v.end(),myComp);

    vector <int> arr;
    for(auto elem:v)
    {
        arr.push_back(elem.second);
    }
    cout<<lis(arr);
    // explaination
    // 5  15 27 39 50
    // 24 28 40 60 90
    // return a.first > b.second;
    // 24 < 27 
    // and 
    // 40 < 50
    // same as activity selection problem
}