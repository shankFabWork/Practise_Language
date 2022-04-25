#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printGraph(vector <int> adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int val:adj[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}


// s -> u [adjacent]
// parent -> s
// u [adjacent] != parent
bool DFS_recursion(vector <int> adj[],bool visited[],int s,int parent)
{
    visited[s] = true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u] == false)
        {
            if(DFS_recursion(adj,visited,u,s) == true)
            {
                return true;
            }
        }
        else if(u != parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector <int> adj[],int n)
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
            if(DFS_recursion(adj,visited,i,-1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    vector <int> adj[n];

    // Graph has cycle
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // addEdge(adj,3,0);

    // Graph has no cycle
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);


    printGraph(adj,n);

    if(DFS(adj,n) == true)
    // Time Complexity -> O(V+E)
    {
        cout<<endl<<"it has cycle";
    }
    else
    {
        cout<<endl<<"it has no cycle";
    }

    return 0;
}