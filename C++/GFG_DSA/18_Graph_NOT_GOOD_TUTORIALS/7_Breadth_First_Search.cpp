// We discuss following versions of B.F.S. :

// 1. Given an undirected graph and 
// a source vertex 's' ,print B.F.S. from given source.

// 2. B.F.S on disconnected graphs.

// 3. Print number of islands in a graph 
// (or number of connected components in a graph).

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printGraph(vector <int> adj[],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"->";
        for(int val:adj[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

// requires source
void Breadth_First_Search(vector <int> adj[],int n,int s)
{
    queue <int> q;
    bool visited[n];
    for(int i=0;i<=n;i++)
    {
        visited[i] = false;
    }
    q.push(s);
    visited[s] = true;  
    while(q.empty() != true)
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i:adj[curr])
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// it is part of "Breadth_First_Search_no_source"
// used to find all the connected components
void BFS(vector <int> adj[],bool visited[],int s)
{
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while(q.empty() != true)
    {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i:adj[curr])
        {
            if(visited[i] == false)
            {
                visited[i] = true;                    
                q.push(i);
            }
        }
    }
}

int Breadth_First_Search_no_source(vector <int> adj[],int n)
{
    int count = 0;
    bool visited[n+1];
    for(int i=0;i<=n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<=n;i++)
    {
        if(visited[i] == false)
        {
            BFS(adj,visited,i);
            count++;
            cout<<endl;
        }
    }
    return count;
}

int main()
{
    // number of verteces
    int n = 8;
    vector <int> adj[n+1];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,6,7);
    addEdge(adj,7,8);
    addEdge(adj,8,6);
    
    printGraph(adj,n);
    cout<<"source-> 0"<<endl;
    Breadth_First_Search(adj,n,0);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    cout<<endl;
    cout<<"source-> 4"<<endl;
    Breadth_First_Search(adj,n,4);
    cout<<endl;
    // in this case no source will be given
    // it means when the graph is disconnected
    // Breadth_First_Search_no_source(adj,n);
    cout<<"no source was given"<<endl;
    // number of connected component 
    // in the unidirected graph
    int cc = Breadth_First_Search_no_source(adj,n);
    // Time Complexity -> O(V+E)
    cout<<endl;
    cout<<" number of connected component -> "<<cc;
    cout<<endl;



    return 0;
}