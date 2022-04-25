// This is one of the tricky problem asked in an interview
// where a random address to a node of the linked list is given 
// and the user needs to delete the node of the given address. 
// The address can point to any random node in-between 
// a linked list

// I/P
// 10->20->30->40->25->NULL
// O/P
// list should change to 
// 10->20->40->25->NULL

// we can assume that the node reference 
// given is never a last node

#include <iostream>

using namespace std;

// this trich will not work it node reference 
// given is the last node

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        next = NULL;
    }
    Node(int d)
    {
        next = NULL;
        data = d;
    }

};

Node* create_node()
{   
    // linked list will become
    // 12 4 14 17 21
    Node* head = new Node();
    head = new Node(12);
    head->next = new Node(4);
    head->next->next = new Node(14);
    head->next->next->next = new Node(17);
    head->next->next->next->next = new Node(21);
    return head;
}

void Disp_all(Node* head)
{
    Node* temp = head;
    cout<<endl;
        while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void DeleteNode(Node* ptr)
{
    cout<<ptr->data<<" is deleted successfully";
    Node* temp = ptr->next;
    ptr->next = temp->next;
    ptr->data = temp->data;
    cout<<endl;
    cout<<endl;
    delete temp;
}   

// No head is given here
int main()
{
    Node* head = new Node();
    int choice;
    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a Linked List";
        // No head is given here
        cout<<endl<<"3-> Delete node with only given pointer";
        cout<<endl<<"4-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: 
                // any node will be given to it except 
                // the last one
                // if u wiill give last node to delete 
                // then it will give segmentation error
                // Orignal linked list is ::
                // 12 4 14 17 21
                // 14 is to be deleted
                DeleteNode(head->next->next);
                break;           
            case 4: exit(1);       
                break;           
            defualt:
                cout<<endl;
                cout<<"you entered wrong choice ";
                cout<<"please enter again";
        }

    }while(choice != 4);

    return 0;
}