// Bipartite Graph
// Graph is called Bipartite when it is coloured with only two colours
// like blue or green
// but the condition is no two adjacent nodes have same color

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void print_graph(vector <int> bp[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"i->";
        for(int data:bp[i])
        {
            cout<<data<<" ";
        }
        cout<<endl;
    }
}

void print_color_arr(int color[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<color[i]<<" ";
    }
}

bool bi_partite_graph(vector <int> adj[],int color[],int s)
{
    queue <int> q;
    q.push(s);
    color[s] = 0;
    while(q.empty() != true)
    {
        int val = q.front();
        q.pop();
        // cout<<val<<" ";
        for(int data:adj[val])
        {
            if(color[data] == -1)
            {
                // color[data] = (color[val] == 0)?1:0;
                color[data] = 1-color[val];
                q.push(data);
            }
            else if(color[data] == color[val])
            {
                return false;
            }
        } 
    }
    // print_color_arr(color,n);
    return true;
}

bool bi_partite_graph_connected_comp(vector <int> adj[],int n)
{
    int color[n];
    for(int i=0;i<n;i++)
    {
        color[i] = -1;
    }
    for(int i=0;i<n;i++)
    {   
        if(color[i] == -1)
        {
            if(bi_partite_graph(adj,color,i) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 4;
    vector <int> adj[n];

    // odd cycle
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);

    // even cycle
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);


    cout<<bi_partite_graph_connected_comp(adj,n);
    
    return 0;
}