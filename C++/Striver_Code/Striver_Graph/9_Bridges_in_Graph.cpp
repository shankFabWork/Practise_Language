// Cut Edge
// Bridge is a edge on removing it
// , it broke down the graph into 
// two connected components

// this is a unidirected graph
// node = i
// it = data
// low[node] = min(low[node,low[it]])
// if(low[it] > low[node])
// low[node] = min(low[node],tin[it])

#include <bits/stdc++.h>

using namespace std;

// unidirected graph
void addEdge(vector <int> g[],int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void DFS_traversal(vector <int> g[],vector <int> &visited,int n,int s,int parent,int timer,vector <int> &low,vector <int> &tin)
{
    // tin - time of insertions
    // low - lowest time of insertion
    // low[s] = tin[s] = timer++;
    // low[adjacent] > tin[s]
    // low[s] = min(low[s],low[adjacent]);
    // low[s] = min(low[s],tin[adjacent]);
    visited[s] = 1;
    low[s] = tin[s] = timer++;
    for(int itr:g[s])
    {
        if(itr == parent)
        {
            continue;
        }
        if(visited[itr] == false)
        {
            DFS_traversal(g,visited,n,itr,s,timer,low,tin);
            low[s] = min(low[s],low[itr]);
            if(low[itr] > tin[s])
            {
                cout<<s<<" "<<itr<<endl;
            }
        }
        else
        {
            low[s] = min(low[s],tin[itr]);
        }
    }
}

void bridgs_in_graph(vector <int> g[],int n)
{
    int timer = 0;
    vector <int> low(n,-1);
    vector <int> tin(n,-1);
    vector <int> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            DFS_traversal(g,visited,n,i,-1,timer,low,tin);
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