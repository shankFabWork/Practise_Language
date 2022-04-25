// cut vertex
// Articulation Points are the points which , 
// when removed , It broke down the graph in 
// two connected components

#include <bits/stdc++.h>

using namespace std;

// unidirected graph
void addEdge(vector <int> g[],int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void dfs_tranverse(int i,int parent,int timer,vector <int> g[],vector <int> &low,vector <int> &tin,vector <int> &visited,vector <int> &articulation)
{
    visited[i] = 1;
    tin[i] = low[i] = timer++;
    int child = 0;
    for(int itr:g[i])
    {
        if(itr == parent)
        {
            continue;
        }
        if(visited[itr] == false)
        {
            dfs_tranverse(itr,i,timer,g,low,tin,visited,articulation);
            low[i] = min(low[i],low[itr]);
            if(low[itr] >= tin[i] && parent != -1)
            {
                articulation[i] = 1;
            }
            child++;
        }
        else
        {
            low[i] = min(low[i],tin[itr]);
        }
    }
    if(child > 0 && parent == -1)
    {
        articulation[i] = 1;
    }
}


void bridgs_in_graph(vector <int> g[],int n)
{
    int timer = 0;
    vector <int> low(n,-1);
    vector <int> tin(n,-1);
    vector <int> visited(n,0);
    vector <int> articulation(n,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            dfs_tranverse(i,-1,timer,g,low,tin,visited,articulation);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(articulation[i] == 1)
        {
            cout<<i<<" ";
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



    bridgs_in_graph(g,n);
    return 0;
}