#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
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

bool directed_bfs(vector <int> adj[],bool visited[],int s)
{
    queue <pair<int,int>> q;
    q.push({s,-1});
    visited[s] = true;
    while(q.empty() != true)
    {
        int elem = q.front().first;
        int par = q.front().second;
        q.pop();
        for(int data:adj[elem])
        { 
            if(visited[data] != true)
            {
                q.push({data,elem});
                visited[data] = true;
            }
            else if(data != par)
            {
                return true;
            }
        }
    }
    return false;
}

bool Detect_cycle_in_directed_bfs(vector <int> adj[],int n)
{
    bool visited[n] = {true};
    for(int i=0;i<n;i++)
    {
        if(visited[i] != true)
        {
            return directed_bfs(adj,visited,i);
        }
    }
}

int main()
{
    int n = 3;
    vector <int> adj[n];
    
    // has loop
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);

    // has no loop
    addEdge(adj,0,1);

    cout<<Detect_cycle_in_directed_bfs(adj,n);

    return 0;
}