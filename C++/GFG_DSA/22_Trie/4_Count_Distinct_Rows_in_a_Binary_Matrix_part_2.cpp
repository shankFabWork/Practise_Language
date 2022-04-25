#include <iostream>
#define row 6
#define col 4

using namespace std;

class Trie
{
    public:
    Trie *child[2];
    Trie()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};

bool insertTrie(int arr[],Trie *root)
{
    Trie *copy_root = root;
    bool flag = false;
    int k;
    for(k=0;k<col;k++)
    {
        int val = arr[k];
        if(copy_root->child[val] == NULL)
        {
            copy_root->child[val] = new Trie();
            flag = true;
        }
        copy_root = copy_root->child[val];
    } 
    return flag;
}

int countDistinct(int mat[row][col],Trie *root)
{
    int res = 0;
    for(int i=0;i<row;i++)
    {
        if(insertTrie(mat[i],root))
        {
            res++;
        }
    }
    return res;
}

int main()
{
    Trie *root = new Trie();
    int mat[row][col] = 
    {
        {1,0,0,0},
        {1,1,1,1},
        {1,1,1,0},
        {1,1,0,1},
        {1,1,1,0},
        {1,1,1,0}
    };
    // it has 4 distinct rows
    cout<<countDistinct(mat,root);
    // TC - O(m*n)
    // SC - O(m*n)


}