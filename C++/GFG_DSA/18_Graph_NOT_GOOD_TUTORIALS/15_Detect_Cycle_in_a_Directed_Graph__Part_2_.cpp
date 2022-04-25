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

// Topological Sorting works only for an acyclic graph
// Topological Sorting do not work
// for a directed cyclic graph
bool Detect_Cycle_in_Directed_Graph(vector <int> adj[],int n)
{
    // write "n" not "n+1"
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
    int count = 0;
    // count is inside while loop
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
        count++;
    }
    return (count != n);
}

int main()
{
    int n = 3;
    vector <int> adj[n+1];

    // graph has cycle 
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);

    // graph do not has cycle 
    addEdge(adj,0,1);
    addEdge(adj,0,2);

    printGraph(adj,n);
    // this algo is also known as Kahn's Algorithm.
    if(Detect_Cycle_in_Directed_Graph(adj,n) == true)
    // Time Complexity -> O(V+E)
    {
        cout<<endl<<"Directed graph has cycle"<<endl;
    }
    else
    {
        cout<<endl<<"Directed graph has no cycle"<<endl;
    }

    return 0;
}