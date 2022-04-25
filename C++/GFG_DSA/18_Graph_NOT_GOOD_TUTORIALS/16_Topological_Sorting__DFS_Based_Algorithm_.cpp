#include <iostream>
#include <vector>
#include <stack>

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

void printStack(stack <int> sta)
{
    while(sta.empty() != true)
    {
        cout<<sta.top()<<" ";
        sta.pop();
    }
}

// remember to "&"
// stack <int> &sta
void DFS_recursion(vector <int> adj[],bool visited[],stack <int> &sta,int s)
{
    visited[s] = true;
    for(int val:adj[s])
    {
        if(visited[val] == false)
        {
            DFS_recursion(adj,visited,sta,val);
        }
    }
    sta.push(s);
}

// we will use stack
// in previous all question we have used queue
void Topological_Sorting_DFS(vector <int> adj[],int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    stack <int> sta;
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            DFS_recursion(adj,visited,sta,i);
        }
    }
    printStack(sta);
}

int main()
{
    int n = 5;
    vector <int> adj[n+1];

    // addEdge(adj,0,1);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // addEdge(adj,2,4);
    // addEdge(adj,3,4);

    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);
    // addEdge(adj,1,3);
    // addEdge(adj,3,4);

    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,2,3);
    addEdge(adj,2,4);

    printGraph(adj,n);
    cout<<endl;
    // stack do not follow call by reference 
    // it folows call by value
    // so u need to put "&" in front of stack
    Topological_Sorting_DFS(adj,n);
    // Time Complexity -> O(V+E)

    return 0;
}