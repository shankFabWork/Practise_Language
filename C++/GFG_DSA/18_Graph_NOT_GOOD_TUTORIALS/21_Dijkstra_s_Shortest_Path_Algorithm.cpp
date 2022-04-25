#include <iostream>
#include <climits>

using namespace std;

int mw(int *weight,bool *visited,int v)
{
    int minWeight = -1;
    for(int i=0;i<v;i++)
    {
        if( (minWeight == -1 || weight[i] < weight[minWeight] )&& visited[i] != true)
        {
            minWeight = i;
        }
    }
    return minWeight;
}

void dijkstra_algo(int **arr,int v)
{
    int *weight = new int[v]; 
    bool *visited = new bool[v];

    for(int i=0;i<v;i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    } 
    weight[0] = 0;

    for(int i=0;i<v-1;i++)
    {
        int minWeight = mw(weight,visited,v);
        visited[minWeight] = true;
        for(int j=0;j<v;j++)
        {
            if(visited[j] != true && arr[minWeight][j] != 0)
            {
                int dist = arr[minWeight][j] + weight[minWeight];
                if(dist < weight[j])
                {
                    weight[j] = dist;
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<weight[i]<<endl;
    }

}

int main()
{
    int v = 5;
    int e = 7;
    int **arr = new int*[v];

    int s,d,w;
    for(int i=0;i<v;i++)
    {
        arr[i] = new int[v];
        for(int j=0;j<v;j++)
        {
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        cin>>s>>d>>w;
        arr[s][d] = w;
        arr[d][s] = w;
    }
    // 0 1 4
    // 0 2 8
    // 1 3 5
    // 1 2 2
    // 2 3 5
    // 2 4 9
    // 3 4 4
    dijkstra_algo(arr,v);

    return 0;
}



