// Design The data structure that allows 
// the following operations efficiently
// -> search
// -> insert
// -> delete
// -> Kth smallest

// Example :
// Insert(10)
// Insert(4)
// Insert(15)
// Insert(20)
// Insert(2)
// Kth_smallest(3)
// O/P
// 2 4 10 15 20
// 10

#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int lcount;
    Node(int d)
    {
        lcount = 0;
        data = d;
        left = right = NULL;
    }
};

Node* insertBST()
{
	Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    return root;
    // 18 60 70 4 8 80
    // 3
    // 18
}

Node* DeleteNode(Node* root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data > val)
    {
        root->left = DeleteNode(root->left,val);
    }
    else if(root->data < val)
    {
        root->right = DeleteNode(root->right,val);
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* successor = root->right;
            while(successor->left != NULL)
            {
                successor = successor->left;
            }
            root->data = successor->data;
            root->right = DeleteNode(root->right,val);
        }
    }
    return root;
}

void InorderTrans(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InorderTrans(root->left);
    cout<<root->data<<" ";
    InorderTrans(root->right);
}

void SearchNode(Node* root,int val)
{
    if(root == NULL)
    {
        return;
    }
    while(root != NULL && root->data != val)
    {
        if(root->data > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(root == NULL)
    {
        cout<<endl;
        cout<<"Element Not found";
        cout<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Element found Successfully";
        cout<<endl;
    }
}

int count = 0;
void Kth_smallest_element_one(Node* root,int k)
{
    if(root != NULL)
    {
        Kth_smallest_element_one(root->left,k);
        count++;
        if(count == k)
        {
            cout<<endl;
            cout<<root->data<<" ";
            cout<<endl;
            return;
        }
        Kth_smallest_element_one(root->right,k);
    }
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
        cout<<"3-> Kth smallest element one in BST"<<endl;
        cout<<"4-> Exit in BST"<<endl;
        cout<<"Please enter your choice "<<endl;
        cin>>n;
        switch(n)
        {
            case 1:root = insertBST();
            break;
            case 2:
                cout<<endl;
                InorderTrans(root);
                cout<<endl;
            break;
            case 3:
                cout<<endl;
                cout<<"Enter Kth smallest number to search";
                cout<<endl;
                cin>>val;
                Kth_smallest_element_one(root,val);
                // Time Complexity-> O(n)
                cout<<endl;
            break;

            case 4:
                exit(0);
            default:
                cout<<endl;
                cout<<"Wrong Choice";
                cout<<endl;
        }   
    }while(n != 4);
   return 0;
}