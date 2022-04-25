#include <iostream>
#include <unordered_set>

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

// ignore 1st solution
// do only this solution
bool pair_sum(Node* root,int sum,unordered_set <int> &s)
{
    if(root == NULL)
    {
        return false;
    }
    if(pair_sum(root->left,sum,s) == true)
    {
        return true;    
    }
    if(s.find(sum - root->key) != s.end())
    {
        return true;    
    }
    else
    {
        s.insert(root->key);
    }
    return pair_sum(root->right,sum,s);
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(40);

    unordered_set <int> s;
    int sum = 21;
    // Time Complexity-> O(n)
    // Space Complexity-> O(n)

    cout<<pair_sum(root,sum,s);
}