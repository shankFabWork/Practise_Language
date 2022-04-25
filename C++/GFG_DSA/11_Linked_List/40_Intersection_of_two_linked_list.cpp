// I/P
// 5 8 7 --10 12 15
//        / 
//       9
// O/P
// 10 is the intersection point



#include <iostream>
#include <cstdlib>
#include <unordered_set>

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

Node* h1;
Node* h2;
void create_node()
{   
    Node* head1 = new Node(5);
    h1 = head1;
    head1->next = new Node(6);
    head1->next->next = new Node(7);
    // 20 is the intersection point
    head1->next->next->next = new Node(20);
    head1->next->next->next->next = new Node(13);
    head1->next->next->next->next->next = new Node(23);
    Node* intersection_point = head1->next->next->next;
    Node* head2 = new Node(14);
    h2 = head2;
    head2->next = new Node(17);
    head2->next = intersection_point;
    // 5 6 7 
    //      \ 
    //       20 13 23
    //      /
    // 14 17
}

void Disp_all()
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

int Intersection_of_two_linked_list_one()
{
    unordered_set <Node*> us;
    for(Node* itr = h1;itr != NULL;itr = itr->next)
    {
        us.insert(itr);
    } 
    for(Node* itr = h2;itr != NULL;itr = itr->next)
    {
        if(us.find(itr) != us.end())
        {
            return itr->data;
        }
    }
}

int Intersection_of_two_linked_list_two()
{
    int count1 = 0;
    int count2 = 0;
    for(Node* itr = h1;itr != NULL;itr = itr->next)
    {
        count1++;
    } 
    for(Node* itr = h2;itr != NULL;itr = itr->next)
    {
        count2++;
    } 

    int diff = llabs(count1 - count2);
    int counter = 0;
    if(count1 > count2)
    {
        Node* temp = NULL;
        Node* itr2 = NULL;
        for(temp = h1;temp != NULL && counter < diff;temp = temp->next)
        {
            counter++;
        }
        Node* itr1 = temp;
        itr2 = h2;
        while(itr1 != NULL && itr2 != NULL)
        {
            if(itr1 == itr2)
            {
                return itr1->data;
            }
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        if(itr1 == NULL || itr2 == NULL)
        {
            return -1;
        }

    }
    else
    {
        Node* temp = NULL;
        Node* itr2 = NULL;
        for(temp = h2;temp != NULL && counter < diff;temp = temp->next)
        {
            counter++;
        }
        Node* itr1 = temp;
        itr2 = h1;
        while(itr1 != NULL && itr2 != NULL)
        {
            if(itr1 == itr2)
            {
                return itr1->data;
            }
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        if(itr1 == NULL || itr2 == NULL)
        {
            return -1;
        }
    }
    return -1;
}

// No head is given here
int main()
{
    Node* head = new Node();
    int choice;
    do
    {
        cout<<endl<<"1-> Create a node";
        cout<<endl<<"2-> Transverse a Linked List";
        cout<<endl<<"3-> Intersection point of linked list";
        cout<<endl<<"4-> Exit ";
        cout<<endl<<" Please enter your choice ";;
        cin>>choice;
        switch(choice)
        {
            case 1: create_node();
                break;
            case 2: Disp_all();
                break;           
            case 3: 
                cout<<endl;
                cout<<endl;
                // cout<<Intersection_of_two_linked_list_one();
                // Time Complexity -> O(m+n)
                // Space Complexity -> O(m)
                cout<<endl;
                cout<<Intersection_of_two_linked_list_two();
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