#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int lcount = 0;

    Node(int d)
    {
        data = d;
        left = right = NULL;
        lcount = 0;
    }
};

// void insertNode(Node* root,Node* New)
// {
//     if(root->data > New->data)
//     {
//         if(root->left == NULL)
//         {
//             root->left = New;
//         }
//         else
//         {
//             insertNode(root->left,New);
//         }
//     }
//     else
//     {
//         if(root->right == NULL)
//         {
//             root->right = New;
//         }
//         else
//         {
//             insertNode(root->right,New);
//         }
//     }
// }

Node* insertNode(Node* root,Node* New)
{
    if(root == NULL)
    {
        return New;
    }
    if(root->data > New->data)
    {
        root->lcount++;
        root->left = insertNode(root->left,New);
    }
    else if(root->data < New->data)
    {
        root->right = insertNode(root->right,New);
    }
    return root;
}

Node* createBST()
{
    Node* root = NULL;
    Node* temp = NULL;
    char ch;

    do
    {
        int val;
        cout<<endl<<"enter the data"<<endl;
        cin>>val;
        Node* New = new Node(val);
        if(root == NULL)
        {
            root = New;
            temp = New;
        }
        else
        {
            insertNode(root,New);
        }

        cout<<endl<<"Please choose y/n"<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int counter = 0;
void find_kth_elem_one(Node* root,int k)
{
    if(root == NULL)
    {
        return;
    }
    find_kth_elem_one(root->left,k);
    counter++;
    if(counter == k)
    {
        cout<<root->data<<" ";
        return;
    }
    find_kth_elem_one(root->right,k);
}

Node* find_kth_elem_two(Node* root,int k)
{
    if(root == NULL)
    {
        return NULL;
    }
    int count = root->lcount + 1;
    if(count == k)
    {
        return root;
    }
    if(count > k)
    {
        return find_kth_elem_two(root->left,k);
    }
    return find_kth_elem_two(root->right,k-count);
}


int main()
{
    Node* root = createBST();
    inorder(root);
    int k = 3;
    cout<<endl;
    find_kth_elem_one(root,k);
    // O(n)
    cout<<endl;
    cout<<find_kth_elem_two(root,k)->data;
    // O(k)
    // k is height of binary tree
    cout<<endl;
    return 0;
}