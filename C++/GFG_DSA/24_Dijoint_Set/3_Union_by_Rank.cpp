#include <iostream>
#define N 10

using namespace std;

int parent[N];
int ranks[N];

void initialize()
{
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
    }
    for(int i=0;i<N;i++)
    {
        ranks[i] = 0;
    }
}

// if x is the representative of itself do return
// else find the parent of x (representative)
int find(int x)
{
    if(parent[x] == x)
    {
        return x;
    }
    else
    {
        return find(parent[x]);
    }
}

void unions(int x,int y)
{
    int x_repres = find(x);
    int y_repres = find(y);
    if(x_repres == y_repres)
    {
        return;
    }
    if(ranks[x_repres] > ranks[y_repres])
    {
        parent[y_repres] =  x_repres;   
    }
    else if(ranks[y_repres] > ranks[x_repres])
    {
        parent[x_repres] =  y_repres;   
    }
    else
    {
        parent[y_repres] = x_repres;
        ranks[x_repres]++;
    }
}

int main()
{
    initialize();
    unions(1,2);
    unions(2,3);
    // unions(0,1);
    // time complexity -> O(n)

    // find will return representative
    // of a value
    
    cout<<find(1)<<endl;
    cout<<find(3)<<endl;
    // time complexity -> O(n)
    cout<<ranks[1]<<endl;
    cout<<ranks[3]<<endl;
    // time complexity -> O(log(n))



    return 0;
}