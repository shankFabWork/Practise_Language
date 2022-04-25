#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <pair<int,int>> edge[],int a,int b,int weight)
{
    edge[a].push_back({b,weight});
    edge[b].push_back({a,weight});
}

int main()
{
    int n = 4;
    vector <pair<int,int>> edge[n];

    addEdge(edge,0,1,50);
    addEdge(edge,0,2,100);
    addEdge(edge,1,2,30);
    addEdge(edge,3,1,200);
    addEdge(edge,2,3,20);

    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    // weight , dest
    vector <int> dist(n,INT_MAX);
    dist[0] = 0;
    while(pq.empty() != true)
    {
        int weight = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto data:edge[prev])
        {
            if(dist[data.first] > dist[prev] + data.second)
            {
                dist[data.first] = dist[prev] + data.second;
                pq.push({data.second,data.first});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}