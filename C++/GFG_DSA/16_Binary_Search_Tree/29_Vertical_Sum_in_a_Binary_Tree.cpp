#include <iostream>
#include <map>

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

// pr - pair
// hd - horizontal distance
void Vertical_Sum_in_a_Binary_Tree(Node* root,int hd,map <int,int> &pr)
{
    if(root == NULL)
    {
        return;
    }
    Vertical_Sum_in_a_Binary_Tree(root->left,hd-1,pr);
    pr[hd] += root->key;
    Vertical_Sum_in_a_Binary_Tree(root->right,hd+1,pr);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(30);
    root->left->right = new Node(40);

    map <int,int> pr;

    Vertical_Sum_in_a_Binary_Tree(root,0,pr);
    for(auto x:pr)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    
}