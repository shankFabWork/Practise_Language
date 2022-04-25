#include <iostream>

using namespace std;


#include <iostream>
#include <queue>

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

int Size_of_Binary_Tree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }   
    return (
                1+
                Size_of_Binary_Tree(root->left)+
                Size_of_Binary_Tree(root->right)
            );
}

// Size of Binary Tree is the total numbers 
// of nodes present in that Tree
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
    cout<<Size_of_Binary_Tree(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)

    return 0;
}