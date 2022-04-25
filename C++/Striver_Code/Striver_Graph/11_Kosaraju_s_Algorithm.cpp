// Strongly Connected Components (SCC)
// Step involved in Kosaraju's Algorithm

// 1)  Sort Nodes in the Order of their
// finishing Time (Simple Topological Sorting)
// using dfs traversal

// 2) Transpose The graph

// 3) DFS according to the finishing time

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> g[],int a,int b)
{
    g[a].push_back(b);
}

void DFS_traversal(vector <int> g[],vector <int> &visited,int n,stack <int> &s,int i)
{
    visited[i] = 1;
    for(int data:g[i])
    {
        if(visited[data] == false)
        {
            DFS_traversal(g,visited,n,s,data);
        }
    }
    s.push(i);
}

void topological_sort(vector <int> g[],int n,stack <int> &s)
{
    vector <int> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            DFS_traversal(g,visited,n,s,i);
        }
    }
}

void transpose_graph(vector <int> g[],int n,vector <int> tran_g[])
{
    for(int i=0;i<n;i++)
    {
        for(auto data:g[i])
        {
            tran_g[data].push_back(i); 
        }
    }
}


void DFS_traversal_rev(vector <int> g[],vector <int> &visited,int n,stack <int> &s,int i)
{
    cout<<i<<" ";
    visited[i] = 1;
    for(int data:g[i])
    {
        if(visited[data] == false)
        {
            DFS_traversal_rev(g,visited,n,s,data);
        }
    }
}


void topological_sort_rev(vector <int> tran_g[],int n,stack <int> s)
{
    vector <int> visited(n,0);
    while(s.empty() != true)
    {
        int elem = s.top();
        s.pop();
        if(visited[elem] == false)
        {
            DFS_traversal_rev(tran_g,visited,n,s,elem);
            cout<<endl;
        }
    }
}

int main()
{   
    int n = 5;
    vector <int> g[n];
	addEdge(g,1, 0); 
	addEdge(g,0, 2); 
	addEdge(g,2, 1); 
	addEdge(g,0, 3); 
	addEdge(g,3, 4); 

    stack <int> s;
    topological_sort(g,n,s);

    vector <int> tran_g[n];
    transpose_graph(g,n,tran_g);

    topological_sort_rev(tran_g,n,s);

    return 0;
}
