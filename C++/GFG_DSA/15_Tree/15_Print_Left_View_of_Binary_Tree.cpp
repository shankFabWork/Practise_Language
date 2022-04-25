#include <iostream>
#include <queue>
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

// it is just pre-order traversal
// you can ignore it
int maxLevel = 0;
void Print_Left_View_of_Binary_Tree(Node* root,int level)
{
    if(root == NULL)
    {
        return;
    }   
    if(maxLevel < level)
    {
        cout<<root->key<<" ";
        maxLevel = level;
    }
    Print_Left_View_of_Binary_Tree(root->left,level+1);
    Print_Left_View_of_Binary_Tree(root->right,level+1);
}

void Print_Left_one(Node* root)
{
    Print_Left_View_of_Binary_Tree(root,1);
}

void Print_Left_two(Node* root)
{
    queue <Node*> q;
    q.push(root);
    while(q.empty() != true)
    {
        int count = q.size();
        for(int i=0;i<count;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(i == 0)
            {
                cout<<curr->key<<" ";
            }
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
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
    Print_Left_one(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    cout<<endl;
    Print_Left_two(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(w)
    // where "w" is the width of the tree
    // in worst case -> Space Complexity -> O(n)
    return 0;
}