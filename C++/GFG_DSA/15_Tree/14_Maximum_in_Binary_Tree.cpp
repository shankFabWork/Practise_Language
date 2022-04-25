#include <iostream>
#include <limits.h>

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

int max_val(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int Maximum_in_Binary_Tree(Node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }   
    return max_val(
                    root->key,
                    max_val
                    (
                        Maximum_in_Binary_Tree(root->left),
                        Maximum_in_Binary_Tree(root->right)
                    )
    );
}

// Largest node(key) in a Tree is the maximum
// of the Tree
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
    cout<<Maximum_in_Binary_Tree(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)

    return 0;
}