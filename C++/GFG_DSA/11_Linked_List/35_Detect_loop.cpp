// I/P
// head->10->15->12->20
//           ^       |
//           |       | 
//           ---------  
// 20 is pointing to 15 instead to NULL
// O/P
// YES

// I/P
// head = NULL
// O/P
// No

// I/P
// head->10->20->NULL
// O/P
// NO

// I/P
// head->10->20->30
//        ^       |
//        |       | 
//        --------- 
// 30 is pointing to head(10) instead to NULL
// O/P
// YES

#include <iostream>
#include <unordered_set>

using namespace std;

class Node
{
    public:
        int data;
        bool visited;
        Node* next;
        Node()
        {
            next = NULL;
            visited = false;
        }
        Node(int d)
        {
            data = d;
            next = NULL;
            visited = false;
        }
};

Node* create_ll_loop()
{   
    // It has Loop
    Node* head = new Node(5);
    Node* second = head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next = new Node(20);
    head->next->next = new Node(17);
    head->next->next->next = second;
    return head;
}

Node* create_ll_no_loop()
{    
    // It has no Loop
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(1);
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

// ignore O(n^2) first solution in video
// use these 3 solutions
bool Detect_loop_1(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->visited == 0)
        {
            temp->visited = 1;
            temp = temp->next;            
        }
        if(temp->visited == 1)
        {
            return true;
        }
        if(temp == NULL)
        {
            return false;
        }
    }
    return false;
}


bool Detect_loop_2(Node* head)
{
    Node* curr = head;
    Node* temp = new Node();
    Node* curr_next = new Node();
    while(curr != NULL)
    {
        if(curr == NULL)
        {
            return false;
        }
        if(curr->next == temp)
        {
            return true;
        }
        curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }

    return false;
}

bool Detect_loop_3(Node* head)
{
    // Node* curr = head;
    // unordered_set <Node*> us;
    // for(Node* itr = curr;itr != NULL ;itr = itr->next)
    // {
    //     if(us.find(itr) != us.end())
    //     {
    //         return true;
    //     }
    //     us.insert(itr);
    // }
    // return false;

    unordered_set<Node*> s; 
    for(Node *curr=head;curr!=NULL;curr=curr->next) {  
        if (s.find(curr) != s.end()) 
            return true; 
        s.insert(curr); 
    } 
    return false; 
}

int main()
{   
    Node* head = new Node();
    int choice;

    do
    {
        cout<<endl<<"1-> Create a node with loop";
        cout<<endl<<"2-> Create a node with no loop";
        cout<<endl<<"3-> Transverse a node";

        
        // Method 1 ->
        // Do not do or Ignore O(n^2) first solution in video

        // Method 2 ->
        // It Need modifications of linked list
        // by adding visited as data members
        // TC - O(n)
        // SC - O(1)
        cout<<endl<<"4-> Has Loop or Not";

        // Method 3 ->
        // It destroys orignal linked list
        // TC - O(n)
        // SC - O(1)
        cout<<endl<<"5-> Has Loop or Not ";
        cout<<endl<<" ( Do not run anything after that as , ";
        cout<<"It has destroyed orignal linked list )";

        // Method 4 ->
        // Best Solution using STL (unordered_set)
        // works in 
        // TC - O(n)
        // SC - O(n)  

        cout<<endl<<"6-> Has Loop or Not";
        cout<<endl<<"999-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: head = create_ll_loop();
                break;
            case 2: head = create_ll_no_loop();
                break;
            case 3: Disp_all(head);
                break;     

        // Method 1 ->
        // Ignore O(n^2) first solution in video

        // Method 2 ->
        // It Need modifications of linked list
        // by adding visited as data members
        // TC - O(n)
        // SC - O(1)

        // Method 3 ->
        // It destroys orignal linked list
        // TC - O(n)
        // SC - O(1)

        // Method 4 ->
        // Best Solution using STL (unordered_set)
        // works in 
        // TC - O(n)
        // SC - O(n)  
        
            case 4:
                if(Detect_loop_1(head))
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
            case 5:
                if(Detect_loop_2(head))
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
            case 6:
                // Best Solution
                if(Detect_loop_3(head) == true)
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
            case 999: exit(1);       
                break;           
            defualt:
                cout<<endl<<" you entered wrong choice please enter again";
        }

    }while(choice != 999);

    return 0;
}