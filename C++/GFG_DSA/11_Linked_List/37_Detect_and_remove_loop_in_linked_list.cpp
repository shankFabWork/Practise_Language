// I/P
// head->10->15->12->20
//           ^       |
//           |       | 
//           ---------  
// 20 is pointing to 15 instead to NULL
// O/P
// head->10->15->12->20->NULL

// the problem of detecting a loop using the 
// method of Floyd cycle detection

//  head->10->19->40->91->15->12->20
            // ^                   |
            // |                   | 
            // --------------------- 

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
        data = d;
        next = NULL;
    }

};

Node* create_node()
{   

    // It has no Loop
    // Node* head = new Node(5);
    // head->next = new Node(2);
    // head->next->next = new Node(6);
    // head->next->next->next = new Node(1);
    // return head;

    // It has Loop
    // 5 6 7 20 13 15
    // 15 is pointing to 6
    // loop length is 5
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(7);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(13);
    Node* second = head->next->next->next->next->next = new Node(15);
    second->next = head->next;
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


// Floyd cycle detection
bool floyd_cycle_detection(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

// Floyd cycle detection
void Detect_and_remove_loop_in_linked_list(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            break;
        }
    }
    if(fast != slow)
    {
        return;
    }
    else
    {
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

int length_of_loop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            break;
        }
    }
    int count = 0;
    if(fast == NULL || fast->next == NULL)
    {
        return 0;
    }
    else
    {
        Node* temp = slow;
        do
        {
            ++count;
            temp = temp->next;
        }while(temp != slow);
    }
    return count;
}

int find_first_node_of_loop(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            break;
        }
    }
    if(fast == NULL || fast->next == NULL)
    {
        return 0;
    }
    slow = head;
    do
    {   
        if(fast->next == slow->next)
        {
            return fast->next->data;
        }
        fast =fast->next;
        slow =slow->next;
    }while(fast->next != slow->next);
}

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        cout<<endl<<"3-> detecting a loop ";
        cout<<endl<<"4-> detecting and removing a loop";
        cout<<endl<<"5-> length of a loop";
        cout<<endl<<"6-> find first node of a loop";
        cout<<endl<<"7-> Exit ";
        cout<<endl<<" Please enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3:            
                // Time Complexity -> O(m+n)
                if(floyd_cycle_detection(head))
                    {
                        cout<<endl;
                        cout<<"Linked List has Loop";
                        cout<<endl;
                    }
                else
                    {
                        cout<<endl;
                        cout<<"Linked List has No Loop";
                        cout<<endl;
                    }
                break;           
            case 4:
                Detect_and_remove_loop_in_linked_list(head);
                // Time Complexity: O(n)
                // Space Complexity: O(1)
                cout<<endl;
                cout<<"Loop removed";
                cout<<endl;
                break;           
            case 5:
                cout<<endl;
                cout<<"length of linked list is ";
                cout<<length_of_loop(head);
                cout<<endl;
                break;           
            case 6:
                cout<<endl;
                cout<<find_first_node_of_loop(head);
                cout<<endl;
                break;           
            case 7: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 7);

    return 0;
}

