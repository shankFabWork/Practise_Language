#include <iostream>
#define N 10

using namespace std;

int parent[N];

void initialize()
{
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
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
    // here x_repres is a parent
    parent[y_repres] = x_repres;
}


int main()
{
    initialize();
    unions(1,2);
    unions(2,3);
    unions(0,1);

    cout<<find(1)<<endl;
    cout<<find(3)<<endl;
    // worst case time complexity -> O(n)
    // for both find() and union()



    return 0;
}