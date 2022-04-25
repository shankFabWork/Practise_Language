// the problem of detecting a loop using the 
// method of Floyd cycle detection

// I/P
// head->13->10->17->15->12->20
//                ^          |
//                |          | 
//                ------------
//       ------   ------------
//         |            |
//         O(2)         O(4)
//         O(m)         O(n)
// Time Complexity -> O(m+n)
// Space Complexity -> O(1)

// 20 is pointing to 17 instead to NULL
// O/P
// YES

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
    Node* head = new Node(5);
    Node* second = head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next = new Node(20);
    head->next->next = new Node(17);
    head->next->next->next = second;
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

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a node";
        cout<<endl<<"3-> detecting a loop using the ";
        cout<<endl<<"method of Floyd cycle detection";        cout<<endl<<"4-> Exit ";
        cout<<endl<<" Please enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_node();
                break;
            case 2: Disp_all(head);
                break;           
            case 3:
                // I/P
                // head->13->10->17->15->12->20
                //                ^          |
                //                |          | 
                //                ------------
                //       ------   ------------
                //         |            |
                //         O(2)         O(4)
                //         O(m)         O(n)

                // Time Complexity -> O(m+n)
                // m is the "non-loop length"
                // n is the "loop length"
                // it takes linear time complexity
                // O(length of linked list) = O(m+n)
                // Space Complexity -> O(1)
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
            case 4: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 4);

    return 0;
}