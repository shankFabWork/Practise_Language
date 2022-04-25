// I/P
// R->A->D->A->R
// O/P
// yes

// I/P
// G->F->G
// O/P
// yes

// I/P
// G->E->E->K
// O/P
// no

// R A D A I

// in linked list it is like this :
// R A D A I -> result

// but in stack it is like this :
// R
// A R
// D A R
// A D A R
// I A D A R -> result

// in this the top is I

#include <iostream>
#include <stack>

using namespace std;

class Node
{
    public:
    char data;
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
        New = new Node();
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

// in linked list it is like this :
// R A D A I -> result

// but in stack it is like this :
// R
// A R
// D A R
// A D A R
// "I A D A R" -> result
// in this the top is I
// after pop() reult is "A D A R"
bool Palindrome_Linked_List_one(Node* head)
{
    stack <char> s;
    Node* temp = head;
    for(Node* curr=head;curr != NULL;curr=curr->next)
    {
        s.push(curr->data);
    }
    for(Node* curr=head;curr != NULL;curr=curr->next)
    {
        if(s.top() != curr->data)
        {
            return false;
        }
        s.pop();
    }
    return true;
}

Node* reverseLinkedListFromNode(Node* head)
{
    Node* temp = head;
    Node* prev;
    Node* curr;
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
    head = prev;
    return head;
}

// ===> for odd linked list
// we will find middle node
// x1->x2->x3->x4->x5
// middle is x3
// we will reverse the linked after middle
// it will become->
// x1->x2->x3->x5->x4
// we will compare 
// x1<->x5
// x2<->x4

// ===> for even linked list
// we will find middle node
// x1->x2->x3->x4->x5->x6
// middle is x3 and x4in this case
// (we will only consider x3 as middle)
// we will reverse the linked after middle
// it will become->
// x1->x2->x3->x6->x5->x4
// we will compare 
// x1<->x6
// x2<->x5
// x3<->x4

bool Palindrome_Linked_List_two(Node* head)
{
    if(head == NULL)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* rev = reverseLinkedListFromNode(slow->next);
    Node* curr = head;
    while(rev != NULL)
    {
        if(rev->data != curr->data)
        {
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        cout<<endl<<"3-> Palindrome Linked List 1";
        cout<<endl<<"4-> Palindrome Linked List 2";
        cout<<endl<<"5-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: // Time Complexity -> O(n)
                    // Space Complexity -> O(n)
                    if(Palindrome_Linked_List_one(head))
                    {
                        cout<<"LinkedList is pallindrome";
                    }
                    else
                    {
                        cout<<"LinkedList is not pallindrome";
                    }
                break;           
            case 4: // efficient approach
                    // Time Complexity -> O(1)
                    // Space Complexity -> O(n)
                    if(Palindrome_Linked_List_two(head))
                    {
                        cout<<"LinkedList is pallindrome";
                    }
                    else
                    {
                        cout<<"LinkedList is not pallindrome";
                    }
                break;           
            case 5: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 5);

    return 0;
}