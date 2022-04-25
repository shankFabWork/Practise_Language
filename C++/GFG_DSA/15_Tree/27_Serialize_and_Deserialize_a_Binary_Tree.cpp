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

void Serialize_a_Binary_Tree(Node* root,vector <int> &v)
{   
    if(root == NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->key);
    Serialize_a_Binary_Tree(root->left,v);
    Serialize_a_Binary_Tree(root->right,v);
}

int index = 0;
// this function returns NULL two times
Node* DeSerialize_a_Binary_Tree(vector <int> &v)
{
    if(index == v.size())
    {
        return NULL;
    }
    int val = v[index];
    index++;
    if(val == -1)
    {
        return NULL;
    }
    Node* root = new Node(val);
    root->left = DeSerialize_a_Binary_Tree(v);
    root->right = DeSerialize_a_Binary_Tree(v);
    return root;
}

void printVector(vector <int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

// preorder
void transverseNode(Node* root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        transverseNode(root->left);
        transverseNode(root->right);
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->right = new Node(40);
    cout<<endl;

    vector <int> v;
    Serialize_a_Binary_Tree(root,v);
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    printVector(v);
    cout<<endl;
    root = DeSerialize_a_Binary_Tree(v);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    transverseNode(root);
    return 0;
}
    

