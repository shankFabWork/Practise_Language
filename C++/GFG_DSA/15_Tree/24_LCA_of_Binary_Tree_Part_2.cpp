// The solution does only one traversal of binary tree, 
// but assumes that both keys exist in the binary tree.


// LCA - Lowest Common Ancestor

#include <iostream>
#include <vector>

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

Node* findLCA(Node* root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    } 
    if(root->key == n1 || root->key == n2)
    {
        return root;
    }

    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    if(left_lca && right_lca)  return root;
 
    return (left_lca != NULL)? left_lca: right_lca;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);
    cout<<endl;

    int n1 = 60;
    int n2 = 50;
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    Node* curr = findLCA(root,n1,n2);
    cout<<curr->key;

    // both the solution this and previous 
    // one requires : 
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    // but this solution requires only one 
    // transversal and also requires 
    // less space in worst case
    return 0;
}
    

