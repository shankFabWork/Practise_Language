// even first and then odd
// I/P
// 17->15->8->12->10->5->4
// O/P
// 8->12->10->4->17->15->5

// I/P
// 8->12->10
// O/P
// 8->12->10 

// I/P
// 1->3->5
// O/P
// 1->3->5

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

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* create_node()
{   
    // Node* New = new Node();
    // Node* temp = new Node();
    // Node* ptr = NULL;
    // char ch;
    // do
    // {
    //     cout<<endl<<"Plz enter your node data :: ";
    //     New = new Node();
    //     New->next = NULL;
    //     cin>>New->data;
    //     if(ptr == NULL) 
    //     {
    //         ptr = New;
    //         temp = New;
    //     }       
    //     else
    //     {
    //         temp->next = New;
    //         temp = New;
    //     }
    //     cout<<endl<<" Do u want to continue again y/n ::";
    //     cin>>ch;
    // }while(ch == 'y' || ch == 'Y');
    // return ptr;

    // 1 4 5 8 9 10 11
    // Later Linked will Become
    // linked list will become
    // 4 8 10 1 5 9 11

    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);
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


Node* Segregate_even_odd_nodes_of_linked_list(Node* head)
{
    Node* curr = head;
    Node* eS = NULL;
    Node* eE = NULL;
    Node* oS = NULL;
    Node* oE = NULL;
    for(auto itr = head;itr != NULL;itr=itr->next)
    {
        if(itr->data % 2 == 0)
        {
            if(eS == NULL)
            {
                eS = itr;
                eE = itr;
            }
            else
            {
                eE->next = itr;
                eE = eE->next;
            }
        }
        else
        {
            if(oS == NULL)
            {
                oS = itr;
                oE = itr;
            }
            else
            {
                oE->next = itr;
                oE = oE->next;
            }
        }
    }

    if(eE == NULL || oE == NULL)
    {
        return head;
    }
    eE->next = oS;
    oE->next = NULL;
    return eS;
}

// No head is given here
int main()
{
    Node* head = new Node();
    Node* seg_head;
    int choice;
    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a Linked List";
        cout<<endl<<"3-> Segregate even odd nodes of linked list";
        cout<<endl<<"4-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
            // 1 4 5 8 9 10 11
                break;
            case 2: Disp_all(head);
                break;           
            case 3: 
                seg_head=Segregate_even_odd_nodes_of_linked_list(head);
                Disp_all(seg_head);
                // Time Complexity -> O(n)
                // Space Complexity -> O(1)
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