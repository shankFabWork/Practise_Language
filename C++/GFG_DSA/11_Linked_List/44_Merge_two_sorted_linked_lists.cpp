// I/P
// 10->20->30
// 5->25
// O/P
// 5->10->20->25->30 

// I/P
// 10->20
// NULL
// O/P
// 10->20

// I/P
// 10
// 40->50
// O/P
// 10->40->50

// we need to merge inplace
// it means that we should not use any space for this
// we need to link up the current linked list

// first of all we need to find 
// which one is tail and which one is head

#include <iostream>

using namespace std;

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

Node* h1;
Node* h2;
void create_node()
{   
    // linked list will become
    // 4 10 14 17 21
    Node* head1 = new Node();
    head1 = new Node(4);
    head1->next = new Node(10);
    head1->next->next = new Node(14);
    head1->next->next->next = new Node(17);
    head1->next->next->next->next = new Node(21);
    // linked list will become
    // 2 5 6
    Node* head2 = new Node();
    head2 = new Node(2);
    head2->next = new Node(5);
    head2->next->next = new Node(6);
    // merge linked list will be 
    // 2 4 5 6 10 14 17 21
    h1 = head1;
    h2 = head2;
}

void Disp_both_linked_list()
{
    cout<<endl;
    Node* temp1 = h1;
    while(temp1 != NULL)
    {
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;
    Node* temp2 = h2;
    while(temp2 != NULL)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }
    cout<<endl;
}

void Disp_merged_array(Node* head)
{
    cout<<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Merge_two_sorted_linked_lists()
{
    Node* a = h1;
    Node* b = h2;
    Node* head = NULL;
    Node* tail = NULL;
    if(a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    while(a != NULL && b != NULL)
    {
        if(a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if(a == NULL)
    {
        tail->next = b;
    }
    else
    {
        tail->next = a;
    }
    return head;
}

int main()
{
    Node* head = new Node();
    int choice;
    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse both Linked List";
        cout<<endl<<"3-> Merge two sorted linked lists";
        cout<<endl<<"4-> Transverse merged Linked List";
        cout<<endl<<"5-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            // 1 
            // 2 
            // 3 
            // 4
            case 1: create_node();
                break;
            case 2: Disp_both_linked_list();
                break;           
            case 3: head = Merge_two_sorted_linked_lists();
                    // Time Complexity -> O(m+n)
                    // "m" is the size of "a"
                    // "n" is the size of "b"
                    // Space Complexity -> O(1)
                break;           
            case 4: Disp_merged_array(head);
                break;           
            case 5: exit(1);       
                break;           
            defualt:
                cout<<endl;
                cout<<"you entered wrong choice ";
                cout<<"please enter again";
        }

    }while(choice != 5);

    return 0;
}

