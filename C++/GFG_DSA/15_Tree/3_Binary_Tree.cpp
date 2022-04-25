// In Binary Tree every node 
// has at most two children.
// that means degree of every node is 2

#include <bits/stdc++.h>

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

void insert(Node* root,int val)
{
    queue <Node*> q;
    q.push(root);
    while(q.empty() != true)
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = new Node(val);
            return;
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = new Node(val);
            return;
        }
    }
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(40);

    insert(root,90);
    inorder(root);

    return 0;
}