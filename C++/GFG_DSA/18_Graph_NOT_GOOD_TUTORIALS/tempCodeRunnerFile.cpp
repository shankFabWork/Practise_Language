#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstring>

using namespace std;

void addEdges(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
}

void printGraph(vector <int> adj[],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"->";
        for(int val:adj[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

void BFS_common(vector <int> adj[],bool visited[],int s,int dist[])
{
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while(q.empty() != true)
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v] == false)
            {
                // dist of adjacent = dist of current + 1
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFS(vector <int> adj[],int n,int dist[])
{
    bool visited[n];
    for(int i=0;i<=n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<=n;i++)
    {
        if(visited[i] == false)
        {
            BFS_common(adj,visited,i,dist);
        }
    }
}

void printDist(int dist[],int n)
{
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<dist[i]<<" ";   
    }
}

int main()
{
    int n = 5;
    // "+1" for adding 5th vertex also
    // if not added bad alloc error will occur
    vector <int> adj[n+1];
    int dist[n+1];
    memset(dist,INT_MAX,n+1);
    dist[0] = 0;
    addEdges(adj,0,2);
    addEdges(adj,1,4);
    addEdges(adj,0,1);
    addEdges(adj,1,2);
    addEdges(adj,2,3);
    addEdges(adj,3,4);
    addEdges(adj,1,5);
    printGraph(adj,n);
    cout<<endl;
    cout<<"Breadth First Search";
    cout<<endl;
    BFS(adj,n,dist);
    cout<<endl<<"Print Distance";
    printDist(dist,n);

    return 0;
}