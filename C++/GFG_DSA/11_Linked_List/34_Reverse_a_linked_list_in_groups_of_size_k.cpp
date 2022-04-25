// I/P
// 10 20 30 40 50 60
// k=3
// O/P
// 30 20 10 60 50 40

// I/P
// 10 20 30 40 50 
// k=3
// O/P
// 30 20 10 50 40

// I/P
// 10 20 30  
// k=3
// O/P
// 30 20 10 
// Ignore recursive solution


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
// Ignore recursive solution
Node* Reverse_linked_list_in_groups_of_size_k_recur(Node* head,int k)
{
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* Next = NULL;
    while(curr != NULL && count<k)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        count++;
    }
    if(Next != NULL)
    {
        Node* rest_head = Reverse_linked_list_in_groups_of_size_k_recur(Next,k);
        head->next = rest_head;
    }
    return prev;
}

Node* Reverse_linked_list_in_groups_of_size_k_iterative(Node* start,int k)
{
    // => Outside 
    // curr = start;
    // prevFirst = NULL;
    // isFirstPass = true;

    // => Inside
    // prev = NULL;
    // first = curr;
    // counter = 0;

    // rest is easy

    Node* curr = start;
    Node* prevFirst = NULL;
    bool isFirstPass = true;
    while(curr != NULL)
    {
        Node* prev = NULL;
        Node* first = curr;
        int counter = 0;
        while(curr != NULL && counter < k)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        if(isFirstPass)
        {
            start = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return start;
}   

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        // Ignore recursive solution , TC - O(n) , SC - O(n/k)
        cout<<endl<<"3-> Reverse a linked list in groups of size k recursion";
        // Do iterative solution , TC - O(n) , SC - O(1)
        cout<<endl<<"4-> Reverse a linked list in groups of size k iterative";
        cout<<endl<<"999-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: 
                    Disp_all(head);
                    // 1) Recursive solution (ignore)
                    // because it has
                    // Time complexity - O(n)
                    // Space complexity - O(n/k)
                    // and difficult to learn
                    
                    head = Reverse_linked_list_in_groups_of_size_k_recur(head,3);
                    // Time complexity - O(n)
                    // Space complexity - O(n/k)
                    Disp_all(head);

                break;           
            case 4:
                    Disp_all(head);
                    // 2) Iterative solution
                    // Time complexity - O(n)
                    // Space complexity - O(1)
                    
                    head = Reverse_linked_list_in_groups_of_size_k_iterative(head,3);
                    Disp_all(head);
                break;
            case 999: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 999);

    return 0;
}