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

bool myComp(Node* a,Node* b)
{
    return a->weight < b->weight;
}

int findParent(vector <int> &parent_arr,int elem)
{
    if(parent_arr[elem] == elem)
    {
        return elem;
    }
    return findParent(parent_arr,parent_arr[elem]);
}


void union_node(vector <int> &parent_arr,vector <int> &rank,int a,int b)
{
    int x_rep = findParent(parent_arr,a);
    int y_rep = findParent(parent_arr,b);
    if(findParent(parent_arr,a) == findParent(parent_arr,b) )
    {
        return;
    }
    
    if(rank[x_rep]<rank[y_rep])
        parent_arr[x_rep] = y_rep;
    
    else if(rank[y_rep]<rank[x_rep])
        parent_arr[y_rep]=x_rep;
    
    else
        {
            parent_arr[y_rep] = x_rep;
            
            rank[x_rep]++;
        }
}

int main()
{
    int v = 5;
    int e = 7;
    vector <Node*> edge;

    // (src,dest,weight)
    edge.push_back(new Node(0,1,10));
    edge.push_back(new Node(0,2,8));
    edge.push_back(new Node(1,2,5));
    edge.push_back(new Node(1,3,3));
    edge.push_back(new Node(2,3,4));
    edge.push_back(new Node(2,4,12));
    edge.push_back(new Node(3,4,15));
    

    sort(edge.begin(),edge.end(),myComp);
    for(auto itr:edge)
    {
        cout<<itr->src<<" "<<itr->dest<<" "<<itr->weight<<endl;
    }

    vector <int> parent_arr;
    for(int i=0;i<v;i++)
    {
        parent_arr.push_back(i);
    }

    vector <int> rank(v,0);
    int cost = 0;

    vector <pair<int,int>> mst;
    for(auto itr:edge)
    {
        if(findParent(parent_arr,itr->src) != findParent(parent_arr,itr->dest) )
        {
            cost += itr->weight;
            mst.push_back({itr->src,itr->dest});
            union_node(parent_arr,rank,itr->src,itr->dest);
        }
    }

    cout<<cost;
    cout<<endl;
    // for(int i=0;i<v;i++)
    // {
    //     cout<<parent_arr[i]<<" ";;
    // }

    for(auto itr:mst)
    {
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    cout<<endl;   
}