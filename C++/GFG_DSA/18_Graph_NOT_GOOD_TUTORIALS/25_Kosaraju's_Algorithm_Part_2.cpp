#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    public:
    int N;
    vector <int> *adj;

    Graph(int n)
    {
        N = n;
        adj = new vector <int> [n];
    }

    void addEdge(int a,int b)
    {
        adj[a].push_back(b);
    }

    void printGraph()
    {
        for(int i=0;i<N;i++)
        {
            cout<<i<<"->";
            for(auto u:adj[i])
            {
                cout<<u<<" ";
            }
            cout<<endl;
        }
    }

    Graph transpose()
    {
        Graph new_g(N);
        for(int i=0;i<N;i++)
        {
            for(int u:adj[i])
            {
                new_g.adj[u].push_back(i);
            }
        }
        return new_g;
    }

    void DFS_recur(bool visited[],int s,stack <int> &sta)
    {
        visited[s] = true;
        for(auto u:adj[s])
        {
            if(visited[u] == false)
            {
                DFS_recur(visited,u,sta);
            }
        }
        sta.push(s);
    }

    void DFS_recur_no_stack(bool visited[],int val)
    {
        visited[val] = true;
        cout<<val<<" ";
        for(int u:adj[val])
        {
            if(visited[u] == false)
            {
                DFS_recur_no_stack(visited,u);
            }
        }
    }

    void kosaraju_s_algo()
    {
        bool visited[N];
        fill(visited,visited+N,false);
        stack <int> sta;
        for(int i=0;i<N;i++)
        {
            if(visited[i] == false)
            {
                DFS_recur(visited,i,sta);
            }
        }
        Graph g = transpose();         
        g.printGraph();
        cout<<endl;

        fill(visited,visited+N,false);
        while(sta.empty() != true)
        {
            int val = sta.top();
            sta.pop();
            if(visited[val] == false)
            {
                g.DFS_recur_no_stack(visited,val);
                cout<<endl;
            }
        }
    }

};  

int main()
{
    int n = 5;
    Graph g(n);
    
    g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 

    g.printGraph();
    cout<<endl;

    g.kosaraju_s_algo();



    return 0;
}
