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
void Print_Nodes_at_K_distance(Node* root,int k)
{
    if(root == NULL) 
    {
        return;
    }
    if(k == 0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        Print_Nodes_at_K_distance(root->left,k-1);
        Print_Nodes_at_K_distance(root->right,k-1);
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    cout<<endl;
    int k = 2;
    Print_Nodes_at_K_distance(root,k);
    cout<<endl;

    return 0;
}