#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;


    Node()
    {
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* Create_Linked_List()
{
    Node *temp = new Node();   
    Node *start = new Node();
    temp = NULL;   
    start = NULL;

    char ch;

    do
    {
        if(start == NULL)
        {
            Node* New = new Node();
            cout<<endl<<"please insert your node ";
            cin>>New->data;
            start = New;
            temp = New;
        }
        else
        {
            Node* New = new Node();
            cout<<endl<<"please insert your node ";
            cin>>New->data;
            temp->next = New;
            temp=New;
        }
        cout<<endl<<"Do u want insert Node again ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');


    temp->next = start;
    return start;
}


void Display_Linked_List(Node *start)
{
    Node* temp = start;
    cout<<endl<<"Nodes are ";

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp != start);

    cout<<endl;
}

Node* Insert_From_start(Node* start)
{
    Display_Linked_List(start);

    int elem;
    cout<<endl<<"enter element to insert at the start -> ";
    cin>>elem;

    Node* temp=start;
    do
    {
        temp=temp->next;
    }while(temp->next != start);

    Node* New = new Node(elem);
    New->next = start;
    start = New;

    temp->next = start;

    Display_Linked_List(start);
    return start;
}

void Insert_From_end(Node* start)
{
    int elem;
    Node* temp = start;
    cout<<endl<<"enter element to insert at the end -> ";
    cin>>elem;
    Node* New = new Node(elem);
    New->next = NULL;
    Display_Linked_List(start);

    do
    {
        temp=temp->next;
    }while(temp->next != start);
    temp->next = New;
    temp = New;
    temp->next = start;
    Display_Linked_List(start);
}

Node* Delete_From_start(Node* start)
{
    if(start == NULL)
    {
        cout<<endl<<"Linked List is empty ";
        return NULL;
    }

    Display_Linked_List(start);

    Node* temp;
    Node* prev;
    Node* rstart = start;
    temp = start;
    cout<<endl<<start->data<<" is deleted successfully ";

    do
    {
        prev = temp;
        temp=temp->next;
    }while(temp->next != start);
    temp->next = start->next;
    start = start->next;
    rstart->next = NULL;
    delete rstart;
    
    Display_Linked_List(start);
    

    return start;
}

void Delete_From_end(Node* start)
{
    if(start == NULL)
    {
        cout<<endl<<"Linked List is empty ";
        return;
    }
    Display_Linked_List(start);

    Node* temp;
    Node* prev;
    temp = start;
    do
    {
        prev = temp;
        temp=temp->next;
    }while(temp->next != start);
    temp->next = NULL;
    cout<<endl<<temp->data<<" is deleted successfully";
    delete temp;
    prev->next = start;

    Display_Linked_List(start);

}

void Delete_Specific_Elem(Node* start)
{
    Node* rstart = start;
    cout<<endl<<"enter element to delete ";
    int elem;
    cin>>elem;
    int counter = 0;
    Node* temp = start;
    Node* prev;
    while(temp->next != start && temp->data != elem)
    {
        counter++;
        prev = temp;
        temp=temp->next;
    }


    if(temp == start)
    {
        Display_Linked_List(start);
        cout<<endl<<start->data<<" is deleted successfully ";

        do
        {
            prev = temp;
            temp=temp->next;
        }while(temp->next != start);
        temp->next = start->next;
        start = start->next;
        rstart->next = NULL;
        delete rstart;
        Display_Linked_List(start);
    }
    else if(temp->next == start)
    {
        Display_Linked_List(start);
        Node* temp;
        Node* prev;
        temp = start;
        do
        {
            prev = temp;
            temp=temp->next;
        }while(temp->next != start);
        temp->next = NULL;
        cout<<endl<<temp->data<<" is deleted successfully";
        delete temp;
        prev->next = start;
        Display_Linked_List(start);
    }
    else if(temp->next != start)
    {
        Display_Linked_List(start);
        cout<<endl<<elem<<" found at "<<counter+1;
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        cout<<endl<<elem<<" is deleted successfully ";
        Display_Linked_List(start);
    }
    else
    {
        cout<<endl<<" Element Not Found ";
    }
}


Node* Insert_Specific_Elem(Node* start)
{
    Display_Linked_List(start);
    cout<<endl<<"enter element after which you want to insert ->";
    int elem;
    cin>>elem;
    
    cout<<endl<<"enter what to insert ";
    int val;
    cin>>val;

    Node* temp = start;
    Node* prev;
    
    while(temp->next != start && temp->data != elem)
    {
        prev = temp;
        temp=temp->next;
    }

    if(temp == NULL)
    {
        Node* New=new Node;
        New->data = val;
        start = New;
        New->next = New;
    }
    else if(temp->next == start)
    {
        Node* New = new Node;
        New->data = val;
        New->next = start;
        temp->next = New;
    }
    else
    {
        Node* New = new Node;
        New->data = val;
        New->next = temp->next;
        temp->next = New;
    }
    Display_Linked_List(start);
    return start;
}

void Searching_Linked_List(Node* start)
{
    Node* temp = start;
    cout<<endl<<"enter the element to be seached-> ";
    int elem;
    cin>>elem;
    int counter = 0;
    do
    {
        counter++;
        temp=temp->next;
    }while(temp->next != start && temp->data != elem);

    if(temp != NULL)
    {
        cout<<endl<<elem<<" is found at "<<counter+1;
    }
    else
    {
        cout<<endl<<elem<<" not found ";
    }
}

int main()
{
    Node* start = new Node();
    int n;
    do
    {     
        cout<<endl<<"1-> Create a Linked List ";
        cout<<endl<<"2-> Insert Element at the start ";
        cout<<endl<<"3-> Insert Element at the end";
        cout<<endl<<"4-> Insert at specific element";
        cout<<endl<<"5-> Delete Element at the start ";
        cout<<endl<<"6-> Delete Element at the end";
        cout<<endl<<"7-> Delete at specific element";
        cout<<endl<<"8-> Transverse all element ";
        cout<<endl<<"9-> Search a Particular Element ";
        cout<<endl<<"10-> Exit  ";
        cout<<endl<<" Please Enter your Choice ";
        cin>>n;
        switch(n)
        {
            case 1:
                start = Create_Linked_List();
            break;

            case 2:
                start = Insert_From_start(start);
            break;

            case 3:
                Insert_From_end(start);
            break;

            case 4:
                start = Insert_Specific_Elem(start);
            break;

            case 5:
                start = Delete_From_start(start);
            break;

            case 6:
                Delete_From_end(start);
            break;

            case 7:
                Delete_Specific_Elem(start);
            break;

            case 8:
                Display_Linked_List(start);
            break;

            case 9:
                Searching_Linked_List(start);
            break;

            case 10:
                exit(0);
            break;


            default: 
                cout<<endl<<"wrong choice plz try again";
        }
    }while(n != 10);

    return 0;
}
