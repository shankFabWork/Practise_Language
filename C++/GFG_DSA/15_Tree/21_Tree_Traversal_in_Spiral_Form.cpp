// step-1-> find height of binary tree
// step-2-> find all nodes at distance K

#include <iostream>
#include <queue>
#include <stack>

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

void Level_Order_Traversal_line_by_line(Node* root)
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
        cout<<endl;
    }
}

void Tree_Traversal_in_Spiral_Form(Node* root)
{
    queue <Node*> q;
    stack <int> s;
    int reverse = false;
    q.push(root);
    while(q.empty() != true)
    {
        int count = q.size();
        for(int i=0;i<count;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(reverse)
            {
                s.push(curr->key);
            }
            else
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
        if(reverse)
        {
            while(s.empty() != true)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout<<endl;
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
    cout<<"Level Order Traversal line by line::`";
    cout<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    Level_Order_Traversal_line_by_line(root);
    cout<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(w)
    // where "w" is the tree
    // "w" is approximatly equal to n/2
    // so we can say it O(n)
    // after remocing constants
    cout<<"Tree Traversal in Spiral Form::";
    cout<<endl;
    Tree_Traversal_in_Spiral_Form(root);

    return 0;
}