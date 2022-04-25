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
};

Node* create_node()
{   
    Node* New = new Node();
    Node* temp = new Node();
    Node* ptr = NULL;
    char ch;
    do
    {
        cout<<endl<<"Plz enter your node data :: ";
        New = (Node*)malloc(sizeof(Node));
        New->next = NULL;
        cin>>New->data;
        if(ptr == NULL) 
        {
            ptr = New;
            temp = New;
        }       
        else
        {
            temp->next = New;
            temp = New;
        }
        cout<<endl<<" Do u want to continue again y/n ::";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return ptr;
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

Node* reverse_linked_list(Node* start)
{
    Node* temp;
    Node* prev;
    Node* curr;
    temp = start;
    prev = temp;
    temp = temp->next;
    prev->next = NULL;
    while(temp != NULL)
    {   
        curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

// ignore this 
// reverse linked list recursively has two solutions
// do 2nd one [ not first one ]
Node* reverse_linked_list_recursively_part_1(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* res_head = reverse_linked_list_recursively_part_1(head->next);
    Node* res_tail = head->next;
    res_tail->next = head;
    head->next = NULL;
    return res_head;
}

// i prefer this
// tail recursive solution
Node* reverse_linked_list_recursively_part_2(Node* prev,Node* curr)
{
    if(curr == NULL)
    {
        // your "head" is this
        return prev;
    }
    Node* Next = curr->next;
    curr->next = prev;
    reverse_linked_list_recursively_part_2(curr,Next);
}

int main()
{
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        cout<<endl<<"3-> Reverse Linkedlist ";
        cout<<endl<<"4-> Reverse Linkedlist recursively Part 1";
        cout<<endl<<"5-> Reverse Linkedlist recursively Part 2";
        cout<<endl<<"6-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: Disp_all(head);
                    head = reverse_linked_list(head);
                    Disp_all(head);
                    break;           
            case 4: head = reverse_linked_list_recursively_part_1(head);
                    Disp_all(head);
                break;           
            case 5: head = reverse_linked_list_recursively_part_2(NULL,head);
                    Disp_all(head);
                break;           
            case 6: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 6);

    return 0;
}