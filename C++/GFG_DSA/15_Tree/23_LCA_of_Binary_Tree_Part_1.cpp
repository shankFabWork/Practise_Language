// LCA - Lowest Common Ancestor

#include <iostream>
#include <vector>

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

bool findPath(Node* root,vector <Node*> &v,int n)
{
    if(root == NULL)
    {
        return false;
    }
    v.push_back(root);
    if(root->key == n)
    {
        return true;
    }
    if(
            findPath(root->left,v,n) ||
            findPath(root->right,v,n)
    )
    {
        return true;
    }
    v.pop_back();
    return false;
}

Node* LCA_of_Binary_Tree_Part_1(Node* root,int n1,int n2)
{
    vector <Node*> path1;
    vector <Node*> path2;
    if(
        findPath(root,path1,n1) == false 
        ||
        findPath(root,path2,n2) == false 
    )
    {
        return NULL;
    }
    for(int i=0;i<path1.size() && i<path2.size();i++)
    {
        if(path1[i+1]->key != path2[i+1]->key)
        {
            return path1[i];
        }
    }
    return NULL;
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
    // vector <Node*> v;
    // if(findPath(root,v,70) == true)
    // {
    //     for(int i=0;i<v.size();i++)
    //     {
    //         cout<<v[i]->key<<" ";
    //     }
    // }
    // else
    // {
    //     cout<<"not found";
    // }

    int n1 = 60;
    int n2 = 50;
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    Node* curr = LCA_of_Binary_Tree_Part_1(root,n1,n2);
    cout<<curr->key;
    return 0;
}
    