// In a Balanced Binary Tree for every node, 
// the difference between heights of 
// left subtree and right subtree 
// should not be more than one.
// or less than or equal to 1

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
    if(a > b)
    {
        return a;
    }
    return b;
}

int Height_Of_Binary_Tree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max_val(
                    Height_Of_Binary_Tree(root->left),
                    Height_Of_Binary_Tree(root->right)
                )+1;
}

bool Check_for_Balanced_Binary_Tree_one(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    int lh = Height_Of_Binary_Tree(root->left);
    int rh = Height_Of_Binary_Tree(root->right);
    // ((lh-rh)>0?(lh-rh):(lh-rh)*-1)<=1
    // use labs instead of abs
    return (
        // (lh-rh) may be -ve we want only +ve 
        // value to make it true
        (labs(lh-rh) <= 1)&&
        Check_for_Balanced_Binary_Tree_one(root->left) &&
        Check_for_Balanced_Binary_Tree_one(root->right)
    );
}

// in this -1 is returned three times
int Check_for_Balanced_Binary_Tree_two(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = Check_for_Balanced_Binary_Tree_two(root->left);
    if(lh == -1)
    {
        return -1;
    }
    int rh = Check_for_Balanced_Binary_Tree_two(root->right);
    if(rh == -1)
    {
        return -1;
    }
    if(labs(lh-rh)>1)
    {
        return -1;
    }
    else
    {
        return max_val(lh,rh)+1;
    }
}

int main()
{
    // tree is balanced
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    // tree is not balanced
    // Node* root = new Node(10);
    // root->left = new Node(5);
    // root->right = new Node(30);
    // root->right->left = new Node(15);
    // root->right->right = new Node(20);
    // root->right->right->right = new Node(21);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(h)
    // if(Check_for_Balanced_Binary_Tree_one(root))
    // {
    //     cout<<"tree is balanced";
    // }
    // else
    // {
    //     cout<<"tree is not balanced";
    // }

    // Time Complexity -> O(n)
    // Space Complexity -> O(h)


    if(Check_for_Balanced_Binary_Tree_two(root) != -1)
    {
        cout<<"Height of BST->"<<Check_for_Balanced_Binary_Tree_two(root);
        cout<<endl;
        cout<<"tree is balanced";
    }
    else
    {
        cout<<"tree is not balanced";
    }


    return 0;
}