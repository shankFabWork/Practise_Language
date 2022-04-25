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


// Time Complexity -> O(n)
// Space Complexity -> O(h)
void preorder(Node* root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Time Complexity -> O(n)
// Space Complexity -> O(h)
void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

// Time Complexity -> O(n)
// Space Complexity -> O(h)
void postorder(Node* root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        postorder(root->left);
        postorder(root->right);
    }
}

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
// we are given a binary tree 
// we need to find the height of it
// Time Complexity -> O(n)
// Space Complexity -> O(h)
int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max_val(height(root->left),height(root->right))+1;
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(41);
    root->right->left = new Node(25);
    root->right->right = new Node(29);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"height of binary search tree is ";
    cout<<height(root);
    cout<<endl;
    return 0;
}