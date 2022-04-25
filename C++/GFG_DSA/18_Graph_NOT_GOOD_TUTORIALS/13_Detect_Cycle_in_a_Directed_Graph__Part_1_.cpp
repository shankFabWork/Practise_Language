#include <iostream>
#include <vector>

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

// recSta[s] = true;
// else if(recSta[adjacent] == true)
// recSta[s] = false;
// return false;
bool DFS_Recursion(vector <int> adj[],int s,bool visited[],bool recSta[])
{
    visited[s] = true;
    recSta[s] = true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u] == false && DFS_Recursion(adj,u,visited,recSta) == true)
        {   
            return true;
        }
        else if(recSta[u] == true)
        {
            return true;
        }
    }
    recSta[s] = false;
    return false;
}

bool DFS_connected(vector <int> adj[],int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    bool recSta[n];
    for(int i=0;i<n;i++)
    {
        recSta[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            if(DFS_Recursion(adj,i,visited,recSta) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 8;
    vector <int> adj[n+1];

    // has loop
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);

    // has no loop
    addEdge(adj,0,1);

    printGraph(adj,n);
    
    if(DFS_connected(adj,n) == true)
    // Time Complexity -> O(V+E)
    {
        cout<<endl<<"directed graph has loop";
    }
    else
    {
        cout<<endl<<"directed graph has no loop";
    }
    

    return 0;
}