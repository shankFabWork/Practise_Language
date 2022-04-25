#include <iostream>
#include <limits.h>
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

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int Maximum_Width_of_Binary_Tree(Node* root)
{
    int maximum_value = INT_MIN;
    queue <Node*> q;
    q.push(root);
    while(q.empty() != true)
    {
        int count = q.size();
        maximum_value = max_val(maximum_value,count);
        for(int i=0;i<count;i++)
        {
            Node* curr = q.front();
            q.pop();
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
    return maximum_value;
}

int main()
{
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(27);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    cout<<Maximum_Width_of_Binary_Tree(root);
    // Time Complexity -> O(n)
    // Space Complexity -> O(w)
    // where w is width
    // width is almost equal to n/2 in a tree
    // in terms of n
    // Space Complexity is n/2
    // which is equal to O(n) (n/2 = n)


    return 0;
}