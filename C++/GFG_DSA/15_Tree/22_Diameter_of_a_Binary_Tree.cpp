// longest path between two leaf nodes


#include <iostream>

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

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max_val(
                        height(root->left),
                        height(root->right)
                    )+1;
}

// int d1 = 1+height(root->left)+height(root->right);
// int d2 = Diameter_of_a_Binary_Tree_one(root->left);
// int d3 = Diameter_of_a_Binary_Tree_one(root->right);
// return max_val(d1,max_val(d2,d3));
int Diameter_of_a_Binary_Tree_one(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int d1 = 1+height(root->left)+height(root->right);
    int d2 = Diameter_of_a_Binary_Tree_one(root->left);
    int d3 = Diameter_of_a_Binary_Tree_one(root->right);
    return max_val(d1,max_val(d2,d3));
}

// int lh = Diameter_of_a_Binary_Tree_two(root->left);
// int rh = Diameter_of_a_Binary_Tree_two(root->right);
// res = max_val(res,1+lh+rh);
// return 1+max_val(lh,rh);
int res = 0;
int Diameter_of_a_Binary_Tree_two(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    // lh = d2 & rh = d3 ( above questions )
    int lh = Diameter_of_a_Binary_Tree_two(root->left);
    int rh = Diameter_of_a_Binary_Tree_two(root->right);
    // "res" is diameter
    res = max_val(res,1+lh+rh);
    // it will return  our height
    return 1+max_val(lh,rh);
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
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(h)
    cout<<"Diameter -> "<<Diameter_of_a_Binary_Tree_one(root);
    cout<<endl;
    cout<<"-------------------";
    cout<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)
    cout<<"height -> "<<Diameter_of_a_Binary_Tree_two(root);
    cout<<endl;
    cout<<"Diameter -> "<<res;
    return 0;
}

