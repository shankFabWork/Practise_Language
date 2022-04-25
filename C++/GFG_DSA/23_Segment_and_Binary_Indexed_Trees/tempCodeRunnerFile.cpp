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
    if(se < qs || ss > qe)
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

    cout<<getSum(0,2,0,n-1,0,tree);
    // height of tree : O(n.log(n))
    // wenever visited more then 
    // 4 nodes on any level 
    // so we never do more than 
    // 4.log(n) work
    // Time Complexity -> O(log(n))


    return 0;
}