#include <iostream>
#include <limits.h>

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

void insertNode(Node* temp,int val)
{
    Node* New = new Node(val);
    if(temp->data > New->data)
    {
        if(temp->left == NULL)
        {
            temp->left = New;
        }
        else
        {
            insertNode(temp->left,val);
        }
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = New;
        }
        else
        {
            insertNode(temp->right,val);
        }
    }
}

Node* insertBST()
{
    // Not BST
    Node* root = new Node(20);
    root->left = new Node(18);
    root->right = new Node(25);
    root->right->left = new Node(19);
    root->right->right = new Node(26);
    return root;

    // Is BST
    // Node *root = new Node(4);  
    // root->left = new Node(2);  
    // root->right = new Node(5);  
    // root->left->left = new Node(1);  
    // root->left->right = new Node(3);  
    // return root;
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

int minValue(Node* root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    int res = root->data;
    int lres = minValue(root->left);
    int rres = minValue(root->right);
    if(res > lres)
    {
        res = lres;
    }
    if(res > rres)
    {
        res = rres;
    }
    return res;
}

int maxValue(Node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    int res = root->data;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);
    if(res < lres)
    {
        res = lres;
    }
    if(res < rres)
    {
        res = rres;
    }
    return res;
}

// ignore this one [ do only efficient one ]
bool Check_for_BST_one(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->left != NULL && maxValue(root->left) >= root->data)
    {
        return false;
    }
        
    if(root->right != NULL && minValue(root->right) <= root->data)
    {
        return false;
    }
    if(
        Check_for_BST_one(root->left) == false 
        || 
        Check_for_BST_one(root->right) == false
    )
    {
        return false;
    } 
    return true;
}

// A Binary tree is BST if inorder 
// transversal of it is in increasing order
int prevv = INT_MIN;
bool Check_for_BST_two(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    // two false conditions
    if(Check_for_BST_two(root->left) == false)
    {
        return false;
    }
    if(prevv >= root->data)
    {
        return false;
    }
    prevv = root->data;
    return Check_for_BST_two(root->right);
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
        cout<<"3-> Check for BST one"<<endl;
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
                InorderTrans(root);
                cout<<endl;
            break;
            case 3:
            // for every node , 
            // 1) find maximum value in left subtree
            // 2) find minimum value in right subtree
            // 3) check if the current node is greater 
            // than the maximum and smaller than the minimum

                if(Check_for_BST_one(root))
                // TC - O(n^2)
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
            case 4:
            // A Binary tree is BST if inorder 
            // transversal of it is in increasing order
                if(Check_for_BST_two(root))
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