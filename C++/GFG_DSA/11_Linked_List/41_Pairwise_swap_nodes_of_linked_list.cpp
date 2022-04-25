// I/P
// 1->2->3->4->5->6 
// O/P
// 2->1->4->3->4->6->5 

// I/P
// 1->2->3->4->5
// O/P
// 2->1->4->3->5

#include <iostream>
#include <algorithm>

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

void Swap_val(Node* a,Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Method 1(Swapping Data)
void Pairwise_swap_nodes_of_linked_list_one(Node* head)
{
    Node* curr = head;
    while(curr != NULL && curr->next != NULL)
    {
        Swap_val(curr,curr->next);
        curr=curr->next->next;
    }
}

// Method 2(Changing Pointers/References)
Node* Pairwise_swap_nodes_of_linked_list_two(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* curr = head->next->next;
    Node* prev = head;
    head = head->next;  
    head->next = prev;
    while(curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node* Next = curr->next->next;
        curr->next->next = curr;
        curr =  Next;
    }
    prev->next = curr;
    return head;
}


Node* Reverse_linked_list_in_groups_of_size_k_iterative(Node* start,int k)
{
    // => Outside 
    // isFirstPass
    // curr
    // prevFirst

    // => Inside
    // prev
    // first
    // count

    // => thing to remember
    // if(isFirstPass)
    // {
    //     start = prev;
    //     isFirstPass = false;
    // }
    // else
    // {
    //     prevFirst->next = prev;
    // }
    // prevFirst = first;

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
        cout<<endl<<"3-> Pairwise swap nodes method one";
        cout<<endl<<"4-> Pairwise swap nodes method two";
        cout<<endl<<"5-> Exit ";
        cout<<endl<<" Please enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: 
                    Pairwise_swap_nodes_of_linked_list_one(head);
                    // Time Complexity -> O(n)
                    // Space Complexity -> (1)                                        
                break;           
            case 4: 
                    // head = Pairwise_swap_nodes_of_linked_list_two(head);    
                    // ignore this recursive solution
                    // do Reverse linked list in groups of size k iterative
                    // it also takes O(n) Time Complexity
                    head = Reverse_linked_list_in_groups_of_size_k_iterative(head,2);                
                    // Time Complexity -> O(n)
                    // Space Complexity -> (1)                    
                break;           
            case 5: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 5);

    return 0;
}