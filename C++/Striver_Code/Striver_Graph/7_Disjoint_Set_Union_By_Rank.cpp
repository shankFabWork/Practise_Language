#include <bits/stdc++.h>

using namespace std;

int *parent_arr;
int *rank_arr;

void initialize(int n)
{
    parent_arr = new int[n];
    rank_arr = new int[n];
    for(int i=0;i<n;i++)
    {
        parent_arr[i] = i;
        rank_arr[i] = 0;
    }
}

int findParent(int a)
{
    if(a == parent_arr[a])
    {
        return a;
    }
    return findParent(parent_arr[a]);
}

void union_node(int a,int b)
{
    if(findParent(a) == findParent(b))
    {
        return;
    }
    if(rank_arr[a] > rank_arr[b])
    {
        parent_arr[b] = a;
    }
    else if(rank_arr[a] < rank_arr[b])
    {
        parent_arr[a] = b;
    }
    else
    {
        parent_arr[b] = a;
        rank_arr[a]++;
    }
}


int main()
{
    int n = 5;
    initialize(n);

    cout<<findParent(0);
    union_node(0,1);
    union_node(1,2);
    union_node(2,3);
    cout<<findParent(3);

    return 0;
}