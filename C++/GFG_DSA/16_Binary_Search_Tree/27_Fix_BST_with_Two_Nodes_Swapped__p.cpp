#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node* insertBST()
{
    // not bst as two nodes are wrong
    // and become bst if these two nodes 
    // will get swapped
	Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    return root;
}


Node *previous = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    fixBST(root->left);
    if(previous != NULL && root->key < previous->key)
    {
        if(first == NULL)
        {
            first = previous;
        }
        second = root;
    }
    previous = root;

    fixBST(root->right);
}

int prevv = INT_MIN;
bool isBST(Node *root)
{
    if(root == NULL)
    {
        return true;
    }
    // two false conditions
    if(isBST(root->left) == false)
    {
        return false;
    }
    if(prevv >= root->key)
    {
        return false;
    }
    prevv = root->key;
    return isBST(root->right);
}

int main()
{
    int n;
    Node* root;
    int val;
    do
    {
        cout<<"1-> Create a BST"<<endl;
        cout<<"2-> Inorder Transversal in BST"<<endl;
        cout<<"3-> Fix BST"<<endl;
        cout<<"4-> Check for BST two"<<endl;
        cout<<"5-> Exit in BST"<<endl;
        cout<<"Please enter your choice "<<endl;
        cin>>n;
        // four method are there in it
        // 1 - ignore
        // 2 - it is easy
        // 3 - ignore
        // 4 - it is simple inorder traversal
        switch(n)
        {
            case 1:root = insertBST();
            break;
            case 2:
                cout<<endl;
                inorder(root);
                cout<<endl;
            break;
            case 3:
                fixBST(root);
                swap(first->key,second->key);
            break;
            case 4:
            // A Binary tree is BST if inorder 
            // transversal of it is in increasing order
                if(isBST(root))
                // TC - O(n)
                // SC - O(h)
                {
                    cout<<endl;
                    cout<<"Given treee is BST";
                    cout<<endl;
                }
                else
                {
                    cout<<endl;
                    cout<<"Given treee is not BST";
                    cout<<endl;
                }
            break;
            case 5:
                exit(0);
            default:
                cout<<endl;
                cout<<"Wrong Choice";
                cout<<endl;
        }   
    }while(n != 5);
   return 0;
}