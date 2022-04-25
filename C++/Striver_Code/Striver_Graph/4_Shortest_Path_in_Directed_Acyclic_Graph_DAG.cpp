#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <pair<int,int>> adj[],int a,int b,int weight)
{
    adj[a].push_back({b,weight});
}

void topological_sort(vector <pair<int,int>> adj[],int n,vector <int> &v)
{
    vector <int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(pair<int,int> data:adj[i])
        {
            indegree[data.first]++;
        }
    }

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
        v.push_back(curr);
        // cout<<curr<<" ";
        for(pair<int,int> data:adj[curr])
        {
            if(--indegree[data.first] == 0)
            {
                q.push(data.first);
            }
        }
    }
}

int main()
{
    int n = 6;
    vector <pair<int,int>> adj[n];
    addEdge(adj,0, 1, 2); 
	addEdge(adj,0, 4, 1); 
	addEdge(adj,1, 2, 3); 
	addEdge(adj,4, 2, 2); 
	addEdge(adj,4, 5, 4); 
	addEdge(adj,2, 3, 6); 
	addEdge(adj,5, 3, 1);

    // find topological sort with anyway
    vector <int> v;
    topological_sort(adj,n,v);

    vector <int> dist(n,INT_MAX);
    dist[0] = 0;
    
    for(int i=0;i<n;i++)
    {
        int curr = v[i];
        if(dist[curr] != INT_MAX)
        {
            for(pair<int,int> data:adj[curr])
            {
                if(dist[data.first] > dist[curr] + data.second)
                {
                    dist[data.first] = dist[curr] + data.second;
                }
            }        
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}