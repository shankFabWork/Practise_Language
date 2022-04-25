#include <iostream>

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


void insertNode(Node* root,Node* New)
{
    if(root->data > New->data)
    {
        if(root->left == NULL)
        {
            root->left = New;
        }
        else
        {
            insertNode(root->left,New);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = New;
        }
        else
        {
            insertNode(root->right,New);
        }
    }
}

Node* createBST()
{
    int val;
    char ch;
    Node* root = NULL;
    Node* temp = NULL;
    do
    {
        cout<<"please enter your value"<<endl;
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
        cout<<"please enter your choice y/n "<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return root;
}

void insertBST(Node* root)
{
    int val;
    cout<<"Please enter the value to insert"<<endl;
    cin>>val;
    Node* temp = root;
    Node* parent;
    while(temp != NULL)
    {
        parent = temp;
        if(temp->data >= val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    Node* New = new Node(val);
    if(parent->data > val)
    {
        parent->left = New;
    }
    else
    {
        parent->right = New;
    }
}

void searchBST(Node* root)
{
    Node* temp = root;
    int val;
    cout<<"Enter the element to be inserted "<<endl;
    cin>>val;
    while(temp != NULL && temp->data != val)
    {
        if(temp->data >= val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if(temp == NULL)
    {
        cout<<"Element Not Found"<<endl;
    }
    else
    {
        cout<<"Element Successfully Found"<<endl;
    }
}

Node* deleteBST(Node* root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data > val)
    {
        root->left = deleteBST(root->left,val);
    }
    else if(root->data < val)
    {
        root->right = deleteBST(root->right,val);
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
            root->right = deleteBST(root->right,successor->data);
        }
    }
    return root;
}

void inorderTransversalBST(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTransversalBST(root->left);
    cout<<root->data<<" ";
    inorderTransversalBST(root->right);
}

// less than or equal [r]
Node* floorBST(Node* root)
{
    Node* res;
    cout<<"Enter the value to be deleted";
    cout<<endl;
    int val;
    cin>>val;
    while(root != NULL)
    {
        if(root->data == val)
        {
            return root;
        }
        if(root->data > val)
        {
            root = root->left;
        }
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

// greater than or equal [l]
Node* ceilBST(Node* root)
{
    Node* res;
    cout<<"Enter the value to be deleted";
    cout<<endl;
    int val;
    cin>>val;
    while(root != NULL)
    {
        if(root->data == val)
        {
            return root;
        }
        if(root->data > val)
        {
            res = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return res;
}

int main()
{
    Node* root = NULL;
    int n;
    char ch;
    do
    {
        cout<<"1-> Create BST"<<endl;
        cout<<"2-> Insert BST"<<endl;
        cout<<"3-> Delete BST"<<endl;
        cout<<"4-> Search BST"<<endl;
        cout<<"5-> Inorder Transversal BST"<<endl;
        
        // smallest or equal
        cout<<"6-> Floor BST"<<endl;
        cout<<"7-> Ceil BST"<<endl;
        cout<<"8-> Exit"<<endl;
        cout<<"Please enter your choice"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:root = createBST();
            break;
                  
            case 2:insertBST(root);
            break;

            case 3:
                cout<<"Enter the value to be deleted"<<endl;
                int val;
                cin>>val;
                root = deleteBST(root,val);
            break;

            case 4:searchBST(root);
            break;

            case 5:
                cout<<endl;
                inorderTransversalBST(root);
                cout<<endl;
            break;

            case 6:
                // right
                cout<<floorBST(root)->data<<endl;
            break;
            case 7:
                // left
                cout<<ceilBST(root)->data<<endl;
            break;
            case 8:exit(1);
            break;
            default:cout<<"wrong choice";
        }
    }while(n != 8);
    return 0;
}

// 1
// 30
// y
// 90
// y
// 40
// y
// 60
// y
// 10
// n
// 3
// 30
// 5