#include <iostream>

using namespace std;

// Here Stack Implementation is using linked list
class Node
{
    public:
    int data;
    Node *next;


    Node()
    {
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* Top;

void push()
{
    char ch;
    do
    {
        int val;
        cout<<endl<<"Please enter your value"<<endl;
        cin>>val;
        Node* New = new Node(val);
        New->next = Top;
        Top = New;        
        cout<<endl;
        cout<<" Do u want ot enter again ";
        cout<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}

void disp()
{
    cout<<endl;
    Node* temp = Top;
    if(temp == NULL)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void pop()
{
    if(Top == NULL)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<endl;
    cout<<Top->data<<" is deleted successfully";
    cout<<endl;
    Node* temp = Top;
    Top = Top->next;
    temp->next = NULL;
    delete temp;
}

int main()
{
    Top = NULL;
    int n;
    do
    {     
        cout<<endl<<"1-> Push a Stack ";
        cout<<endl<<"2-> Pop a Stack ";
        cout<<endl<<"3-> Display a Stack ";
        cout<<endl<<" Please Enter your Choice ";
        cin>>n;
        switch(n)
        {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            case 3:
                disp();
            break;
            case 4:
                exit(1);
            break;

            default: 
            cout<<endl<<"wrong choice plz try again";
        }
    }while(n != 4);



    return 0;
}