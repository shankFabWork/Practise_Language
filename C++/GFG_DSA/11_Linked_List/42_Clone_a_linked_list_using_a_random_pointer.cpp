// see 42_Clone_a_linked_list_using_a_random_pointer.gif
// for see input and output

// I/P
// 1->2->3->4->5->6 
// O/P
// 2->1->4->3->4->6->5 

// I/P
// 1->2->3->4->5
// O/P
// 2->1->4->3->5

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* random;

    Node()
    {
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }

};

Node* create_node()
{   
    // Orignal Linked List
    // 2 7 5 1 11 
    // ^ a b c  d 
    // |
    // (head)
    // random Linked List
    // 2 5 1 
    Node* head = new Node(2);
    Node* a = head->next = new Node(7);
    Node* b = head->next->next = new Node(5);
    Node* c = head->next->next->next = new Node(1);
    Node* d = head->next->next->next->next = new Node(11);
    head->random = b;
    head->next->random = a;
    head->next->next->random = d;
    head->next->next->next->random = NULL;
    head->next->next->next->next->random = c;
    return head;
    
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

Node* Clone_a_linked_list_using_a_random_pointer_one(Node* head)
{
    unordered_map <Node*,Node*> s;
    Node* orignalCurr = head;
    Node* cloneCurr = NULL;

    // 1) insert a cloneCurr node in unordered_map "s" 
    while(orignalCurr)
    {
        Node* cloneCurr = new Node(orignalCurr->data);
        s.insert(make_pair(orignalCurr,cloneCurr));
        // s[orignalCurr] = cloneCurr;
        orignalCurr = orignalCurr->next;
    }

    // 2) connect random in unordered_map
    orignalCurr = head;
    while(orignalCurr)
    {
        cloneCurr = s[orignalCurr];
        cloneCurr->next = s[orignalCurr->next];   
        cloneCurr->random = s[orignalCurr->random];   
        orignalCurr = orignalCurr->next;
    }
    Disp_all(s[head]);
    // cloneCurr first node address
    // head is "orignalCurr" first node
    return head;
}


Node* Clone_a_linked_list_using_a_random_pointer_two(Node* head)
{
    Node* curr = head;

    while(curr)
    {
        Node* temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    for(Node* curr = head ; curr != NULL;curr=curr->next->next)
    {
        curr->next->random =    (curr->random!=NULL)?
                                (curr->random->next):
                                NULL;
    }

    Node* original = head;
    Node* clone = head->next;
    Node* temp = clone;
    while(original && clone)
    {
    original->next = original->next? original->next->next : original->next; 
  
    clone->next = clone->next?clone->next->next:clone->next; 

    original = original->next; 
    clone = clone->next; 
    }
    Disp_all(temp);
    return head;
}

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        cout<<endl<<"3-> Clone linked list using random pointer one";
        cout<<endl<<"4-> Clone linked list using random pointer two";
        cout<<endl<<"5-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3: 
                    head = Clone_a_linked_list_using_a_random_pointer_one(head);
                    // Time Complexity -> O(n)
                    // Space Complexity -> (n)                                        
                break;           
            case 4: 
                    head = Clone_a_linked_list_using_a_random_pointer_two(head);                    
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