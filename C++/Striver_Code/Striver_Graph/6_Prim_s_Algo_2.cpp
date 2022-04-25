#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <pair<int,int>> adj[],int a,int b,int weight)
{
    adj[a].push_back({b,weight});
    adj[b].push_back({a,weight});
}

void prims_a_algo(vector <pair<int,int>> adj[],int n)
{
    vector <int> key;
    vector <bool> mst;
    vector <int> parent;
    for(int i=0;i<n;i++)
    {
        key.push_back(INT_MAX);
        mst.push_back(false);
        parent.push_back(-1);
    }
    key[0] = 0; 

    // * Reality :-
    // priority_queue 
    // <weight,value>
    // adjacent
    // <value,weight>
    
    priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>> > pq;
    pq.push({0,0});
    for(int i=0;i<n-1;i++)
    {
        int s = pq.top().second;
        pq.pop();
        mst[s] = true;
        for(pair<int,int> data:adj[s])
        {
            int u = data.first;
            int weight = data.second;
            if(mst[u] != true && weight < key[u])
            {
                key[u] = weight;
                parent[u] = s;
                pq.push({key[u],u});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<key[i]<<" ";
    }

}

int main()
{
    int n = 4;
    // int n = 5;
    vector <pair<int,int>> adj[n];

    addEdge(adj,0,1,5);
    addEdge(adj,0,2,8);
    addEdge(adj,1,2,10);
    addEdge(adj,1,3,15);    
    addEdge(adj,2,3,20);

    // addEdge(adj,0,1,2);
    // addEdge(adj,0,3,6);
    // addEdge(adj,1,3,8);
    // addEdge(adj,1,4,5);
    // addEdge(adj,1,2,3);
    // addEdge(adj,2,4,7);


    prims_a_algo(adj,n);
    // Time Complexity - O(n.log(n))

    return 0;
}