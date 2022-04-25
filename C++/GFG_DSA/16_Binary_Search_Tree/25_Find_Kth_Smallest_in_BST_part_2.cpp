// Design The data structure that allows 
// the following operations efficiently
// -> search
// -> insert
// -> delete
// -> Kth smallest

// Example :
// Insert(10)
// Insert(5)
// Insert(15)
// Insert(20)
// Insert(2)
// Kth_smallest(3)
// O/P
// 2 5 10 15 20
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

Node* insertNode(Node* root,int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left = insertNode(root->left,val);
        root->lcount++;
    }
    else if(val > root->data)
    {
        root->right = insertNode(root->right,val);
    }
    return root;
}

// 18 60 70 4 8 80
// 3
// 18
Node* insertBST()
{
    Node* root = NULL;
    Node* temp = NULL;
    char ch;
    do
    {
        cout<<endl<<"Please enter the node to be inserted ";
        int val;
        cin>>val;
        if(root == NULL)
        {
            root = new Node(val);
            temp = root;
        }
        else    
        {
            insertNode(temp,val);
        }
        cout<<endl;
        cout<<"Do u want to insert again?? ";
        cout<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return root;
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

Node* Kth_smallest_element_two(Node* root,int k)
{
    if(root == NULL)
    {
        return NULL;
    }
    // see insertNode()
    int count = root->lcount+1;
    if(count == k)
    {
        return root;
    }
    if(count > k)
    {
        return Kth_smallest_element_two(root->left,k);
    }
    return Kth_smallest_element_two(root->right,k-count);
}

int main()
{
    int n;
    Node* root;
    int val;
    do
    {
        cout<<"1-> Create a BST"<<endl;
        cout<<"2-> Delete in BST"<<endl;
        cout<<"3-> Search in BST"<<endl;
        cout<<"4-> Insert in BST"<<endl;
        cout<<"5-> Inorder Transversal in BST"<<endl;
        cout<<"6-> Kth smallest element two in BST"<<endl;
        cout<<"7-> Exit in BST"<<endl;
        cout<<"Please enter your choice "<<endl;
        cin>>n;
        switch(n)
        {
            case 1:root = insertBST();
            break;
            case 2:
                cout<<endl;
                cout<<"Enter element to be deleted";
                cout<<endl;
                cin>>val;
                root = DeleteNode(root,val);
            break;
            case 3:
                cout<<endl;
                cout<<"Enter element to search";
                cout<<endl;
                cin>>val;
                SearchNode(root,val);
            break;
            case 4:                
                cout<<endl;
                cout<<"Enter element to be inseted";
                cout<<endl;
                cin>>val;
                insertNode(root,val);
            break;
            case 5:
                cout<<endl;
                InorderTrans(root);
                cout<<endl;
            break;
            case 6:
                cout<<endl;
                cout<<"Enter Kth smallest number to search";
                cout<<endl;
                int k;
                cin>>k;
                cout<<endl;
                root = Kth_smallest_element_two(root,k);
                // Time Complexity -> O(h)
                cout<<root->data;
                cout<<endl;
            break;
            case 7:
                exit(0);
            default:
                cout<<endl;
                cout<<"Wrong Choice";
                cout<<endl;
        }   
    }while(n != 7);
   return 0;
}