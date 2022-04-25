// I/P
// arr[] = {10,20,30,40}
// O/P
// tree[] = {100,30,70,10,20,30,40}

// I/P
// arr[] = {10,20,30,40,50,60}
// O/P
// tree[] = {210,60,50,30,30,90,60,10,20,-,-,40,50,-,-}

#include <iostream>

using namespace std;

// constructing segement tree includes 
// segment start -> ss
// segment end -> se
// segment index -> si

// initial values
// ss = 0
// se = n-1
// si = 0

int ConstructST(int tree[],int arr[],int ss,int se,int si)
{
    if(ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    tree[si] =  ConstructST(tree,arr,ss,mid,2*si+1) + 
                ConstructST(tree,arr,mid+1,se,2*si+2);
    return tree[si];
}

int getSum(int qs,int qe,int ss,int se,int si,int tree[])
{
    // --------------
    // way of craming
    // --------------
    // se is always smaller
    // ss is always larger
    // || and &&
    // learn only this 
    // se < qs

    // in ConstructST , we make tree from given array
    // in updateQuery , we pass diff between old val at index and new value 

    // ConstructST -> ss,se,si,tree,arr
    // getSum ->      ss,se,si,tree,qs,qe
    // updateQuery -> ss,se,si,tree,index,diff
    
    if(se < qs || qe < ss)
    {
        return 0;
    }
    if(se <= qe && qs <= ss)
    {
        return tree[si];
    }
    int mid = (ss + se)/2;
    return (
        getSum(qs,qe,ss,mid,2*si+1,tree) + 
        getSum(qs,qe,mid+1,se,2*si+2,tree)
    );  
}

void updateQuery(int ss,int se,int si,int tree[],int index,int diff)
{
    if(index<ss || index>se)
    {
        return;
    }
    tree[si] = tree[si] + diff;
    if(se > ss)
    {
        int mid = (ss + se)/2;
        updateQuery(ss,mid,2*si+1,tree,index,diff);
        updateQuery(mid+1,se,2*si+2,tree,index,diff);
    }
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    int tree[4*n];
    // it should exactly has a size of
    // 2*2^(log(base 2(n))) - 1
    // but for easiness
    // we write it's size as 4*n
    // as it is easier to learn

    ConstructST(tree,arr,0,n-1,0); 
    // Time Complexity -> O(n)

    cout<<getSum(2,3,0,n-1,0,tree);
    // height of tree : O(log(n))
    // we never visited more then 
    // 4 nodes on any level 
    // so we never do more than 
    // 4.c.log(n) work
    // Time Complexity -> O(log(n))

    int new_val = 45;
    int index = 2;
    int diff = new_val - arr[index];
    cout<<"--"<<diff<<"--";
    updateQuery(0,n-1,0,tree,index,diff);
    // Time Complexity -> O(log(n))
    cout<<getSum(2,3,0,n-1,0,tree);
    // Time Complexity -> O(log(n))

    return 0;
}