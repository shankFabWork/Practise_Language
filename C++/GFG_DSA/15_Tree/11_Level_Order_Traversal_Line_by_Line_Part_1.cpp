// step-1-> find height of binary tree
// step-2-> find all nodes at distance K

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

void Level_Order_Traversal_line_by_line_one(Node* root)
{
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1)
    {
        Node* curr = q.front();
        q.pop();
        if(curr == NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
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

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
    cout<<endl;
    Level_Order_Traversal_line_by_line_one(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)

    return 0;
}