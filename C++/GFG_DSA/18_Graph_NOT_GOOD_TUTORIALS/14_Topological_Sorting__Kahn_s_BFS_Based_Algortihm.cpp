#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
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

void Topological_Sorting_BFS(vector <int> adj[],int n)
{
    vector <int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(int val:adj[i])
        {
            indegree[val]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
    queue <int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(q.empty() != true)
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int val:adj[curr])
        {
            if(--indegree[val] == 0)
            {
                q.push(val);
            }
        }
    }
}

int main()
{
    int n = 5;
    vector <int> adj[n+1];

    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    printGraph(adj,n);
    Topological_Sorting_BFS(adj,n);
    // Time Complexity -> O(V+E)
    // this algo is also known as Kahn's Algorithm.

    return 0;
}