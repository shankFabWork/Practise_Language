#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector <int> adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto val:adj[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

void DFS_Recursion(vector <int> adj[],int s,bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";
    for(int i:adj[s])
    {
        if(visited[i] == false)
        {
            DFS_Recursion(adj,i,visited);
        }
    }
}

void DFS_disconnected(vector <int> adj[],int n,int s)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    DFS_Recursion(adj,s,visited);
}

int count = 0;
int DFS_connected(vector <int> adj[],int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            DFS_Recursion(adj,i,visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 8;
    // "+1" for the index 
    // u can do addEdge(adj,8,7); without "+1" 
    vector <int> adj[n+1];

    // connected graph
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,0,3);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // printGraph(adj,n);

    // disconnected graph
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    printGraph(adj,n);

    // it only works with the connected graph
    // as the source is given by us
    cout<<endl;
    DFS_disconnected(adj,n,0);
    cout<<endl;
    
    // this function show dfs whether 
    // connected or disconnected
    int connected_components = DFS_connected(adj,n);
    // Time Complexity -> O(V+E)
    cout<<endl<<connected_components<<endl;

    // whether connected or disconnected
    // "DFS_Recursion" function is going to be same

    // count the connected component in the graph

    // "connected component" is also known 
    // as the island in the graph
    return 0;
}