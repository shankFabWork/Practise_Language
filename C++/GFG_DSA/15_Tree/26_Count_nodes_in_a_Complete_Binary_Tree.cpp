// The solution does only one traversal of binary tree, 
// but assumes that both keys exist in the binary tree.


// LCA - Lowest Common Ancestor

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Node
{
    public:
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Count nodes in a Complete Binary Tree
int Count_nodes_one(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1+
                Count_nodes_one(root->left)+
                Count_nodes_one(root->right);
    }
}

int Count_nodes_two(Node* root)
{
    int lh = 0,rh = 0;
    Node* curr = root;
    // we are figuring out if it is perfect
    // binary tree
    // Perfect Binary Tree in which all the 
    // internal nodes have either zero or two children 
    // and all leaf nodes are at the same level. 
    
    // Example :
    //            18
    //        /       \  
    //      15         30  
    //     /  \        /  \
    //   40    50    100   40

    while(curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while(curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if(lh == rh)
    {
        return (pow(2,lh) - 1);
    }
    else
    {
        return (1+
                Count_nodes_two(root->left)+
                Count_nodes_two(root->right));
    }
}

int main()
{
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);

    cout<<endl;
    cout<<Count_nodes_one(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    cout<<endl;
    cout<<Count_nodes_two(root);
    // Time Complexity -> O( log(n) * log(n))
    // in perfect binary tree 
    // time complexity -
    // theta of h i.e. log(n) in best case 
    // Space Complexity -> O(1)


    return 0;
}
    

