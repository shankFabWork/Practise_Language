#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
    public:
    int src;
    int dest;
    int weight;
};


bool compare(Edge e1,Edge e2)
{
    return e1.weight < e2.weight;
}

int parent_val(int val,int parent[])
{
    if(parent[val] == val)
    {
        return val;
    }
    return parent_val(parent[val],parent);
}

void krushkals(Edge *arr,int e,int v)
{
    sort(arr,arr+e,compare);
    int parent[v];
    for(int i=0;i<v;i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    vector <Edge> output(v-1);
    while(count != v-1)
    {
        Edge currEdge = arr[i];
        int srcParent = parent_val(currEdge.src,parent);
        int destParent = parent_val(currEdge.dest,parent);
        if(srcParent != destParent)
        {
            output[count].src = currEdge.src;
            output[count].dest = currEdge.dest;
            output[count].weight = currEdge.weight;
            parent[srcParent] = destParent;
            count++;
        }
        i++;
    }
    for(int i=0;i<v-1;i++)
    {
        if(output[i].src < output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
}

int main()
{
    int e = 11;
    int v = 6;
    int addArr[][3] = {
        {1,3,1},
        {0,1,2},
        {0,3,3},
        {0,2,4},
        {4,5,5},
        {2,3,6},
        {3,5,7},
        {2,1,8},
        {2,4,9},
        {2,5,10},
        {3,4,11}
    }; 
    Edge *arr = new Edge[e];
    for(int i=0;i<e;i++)
    {
        arr[i].src = addArr[i][0];
        arr[i].dest = addArr[i][1];
        arr[i].weight = addArr[i][2];
    } 
    krushkals(arr,e,v);

    return 0;
}