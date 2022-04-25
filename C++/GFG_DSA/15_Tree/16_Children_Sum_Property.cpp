#include <iostream>

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

bool Children_Sum_Property(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if(root->left != NULL)
    {
        sum += root->left->key;
    }
    if(root->right != NULL)
    {
        sum += root->right->key;
    }
    return (
                sum == root->key &&
                Children_Sum_Property(root->left) && 
                Children_Sum_Property(root->right) 
            );
}


int main()
{
    // Tree do not follow child sum properties
    // Node* root = new Node(10);
    // root->left = new Node(15);
    // root->right = new Node(20);
    // root->left->left = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);
    // root->right->left->left = new Node(60);
    // root->right->left->right = new Node(70);

    // Tree follows child sum properties
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    if(Children_Sum_Property(root))
    {
        cout<<"Tree follows child sum properties";
    }
    else
    {
        cout<<"Tree do not follow child sum properties";
    }

    return 0;
}