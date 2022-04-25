#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void print_content(map <int,vector<int>> mp)
{
    for(auto a:mp)
    {
        for(auto b:a.second)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
}

void Vertical_Traversal_of_Binary_Tree(Node* root)
{
    map <int,vector<int>> mp;
    queue <pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty() != true)
    {
        auto p = q.front();
        Node* curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->data);
        q.pop();
        if(curr->left != NULL)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right != NULL)
        {
            q.push({curr->right,hd+1});
        }
    }
    print_content(mp);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    Vertical_Traversal_of_Binary_Tree(root);
}