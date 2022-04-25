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
    
    for(int i=0;i<n-1;i++)
    {
        int min_weight = INT_MAX;   
        int min_dest = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(min_weight > key[i] && mst[i] != true)
            {
                min_weight = key[i];
                min_dest = i;
            }
        }
        mst[min_dest] = true;
        int weight = min_weight;
        int prev = min_dest;
        for(auto data:adj[prev])
        {
            int val = data.first;
            int weight = data.second;
            if(mst[val] != true && key[val] > weight)
            {
                parent[val] = prev;
                key[val] =  weight;
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
    // Time Complexity - O(n^2)


    return 0;
}