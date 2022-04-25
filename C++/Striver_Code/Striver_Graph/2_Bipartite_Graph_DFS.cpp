#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void print_graph(vector <int> adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int data:adj[i])
        {
            cout<<data<<" ";
        }
        cout<<endl;
    }
}

bool DFS(vector <int> adj[],int color[],int i)
{
    if(color[i] == -1)
    {
        color[i] = 1;
    }
    for(int data:adj[i])
    {
        if(color[data] == -1)
        {
            color[data] = 1 - color[i];
            if(DFS(adj,color,data) == false)
            {
                return false;
            }
        }
        else if(color[data] == color[i])
        {
            return false;
        }
    }
   return true;
}

bool Bipartite_Graph_DFS(vector <int> adj[],int n)
{
    int color[n];
    for(int i=0;i<n;i++)
    {
        color[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        if(color[i] == -1)
        {
            if(DFS(adj,color,i) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 5;
    vector <int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    // addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    cout<<Bipartite_Graph_DFS(adj,n);
}