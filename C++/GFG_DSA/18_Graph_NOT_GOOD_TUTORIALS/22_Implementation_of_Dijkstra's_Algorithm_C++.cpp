#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>

#define N 4
using namespace std;

void primMST(int graph[N][N])
{
    vector <bool> mSet(N,false);
    vector <int> key(N,INT_MAX);
    key[0] = 0;
    int res = 0;
    for(int count = 0;count < N;count++)
    {
        int u = -1;
        // O(log(N))
        for(int i=0;i<N;i++)
        {
            if(!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res = res + key[u];
        // O(log(N))
        for(int v = 0 ;v<N;v++)
        {
            if(!mSet[v] && graph[u][v] != 0)
            {
                key[v] = min(key[v],key[u] + graph[u][v]);
            }
        }
    }

    // show part
    for(int i=0;i<N;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<key[i]<<" ";
    }
    cout<<endl;
    cout<<res;
}

int main()
{
    int graph[N][N] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	primMST(graph); 
    // Time Complexity -> O((V+E).log(V))
    // in my case it is N

    return 0;
}