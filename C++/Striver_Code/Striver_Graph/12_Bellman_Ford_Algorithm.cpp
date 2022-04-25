// Detect Negative Weight Cycle in Graphs
// unlike from prims and dijkstar
// we will do exactly n-1 relaxations
// after that if we will do on more relaxation
// and
// if(d[u]+wt < d[v])
// {
//     d[v] = d[u] + wt
// }
// gives us negative number 
// it means that it has negative cycyle

#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int src;
    int dest;
    int weight;

    Node(int s,int d,int w)
    {
        src = s;
        dest = d;
        weight = w;
    }
};

void bellman_ford_algo(vector <Node*> graph,int src,int v)
{
    vector <int> dist(v,INT_MAX); 
    dist[0] = 0;

    for(int i=1;i<=v-1;i++)
    {
        for(auto data:graph)
        {
            if(dist[data->src] + data->weight < dist[data->dest])
            {
                dist[data->dest] = dist[data->src] + data->weight;
            }
        }
    }

    bool possible = true;
    for(auto data:graph)
    {
        if(dist[data->src] + data->weight < dist[data->dest])
        {
            dist[data->dest] = dist[data->src] + data->weight;
            possible = false;
        }
    }

    if(possible == true)
    {
        for(auto data:dist)
        {
            cout<<data<<" ";
        }
    }
    else
    {
        cout<<endl<<"Graph contains negative cycle"<<endl;
    }
}

int main()
{
    vector <Node*> graph;

    // edges = 5
    // weight = 4

    int e = 5;
    int v = 4;

    graph.push_back(new Node(0,1,1));
    graph.push_back(new Node(0,2,4));
    graph.push_back(new Node(1,2,-3));
    graph.push_back(new Node(1,3,2));
    graph.push_back(new Node(2,3,3));

    bellman_ford_algo(graph, 0,v); 

    return 0;
}



