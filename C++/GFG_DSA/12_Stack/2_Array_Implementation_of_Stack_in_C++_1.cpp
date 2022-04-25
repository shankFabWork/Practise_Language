#include <iostream>
#define SIZE 5
// this is called macros
// represented with capital letters
using namespace std;

// Here Stack Implementation is using linked list

int stack[SIZE];
int Top;

bool isEmpty()
{
    if(Top == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(Top == SIZE-1)
    {
        return true;
    }
    return false;
}

void push()
{
    if(isFull())
    {
        cout<<endl;
        cout<<"Stack is full";
        cout<<endl;
        return;
    }
    cout<<endl;
    char ch;
    do
    {
        if(isFull())
        {
            cout<<endl;
            cout<<"Stack is full";
            cout<<endl;
            return;
        }

        Top++;
        cout<<"Please enter your value to be inserted ";
        cout<<endl;
        cin>>stack[Top];
        cout<<endl;
        cout<<"do u want to insert again ?";        
        cout<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}

void pop()
{
    if(isEmpty())
    {
        cout<<endl;
        cout<<"Stack is empty";
        cout<<endl;
        return;
    }
    cout<<endl;
    cout<<stack[Top]<<" is successfully deleted";
    cout<<endl;
    --Top;
}

void disp()
{
    cout<<endl;
    for(int i=Top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Top = -1;
    int n;
    do
    {     
        cout<<endl<<"1-> Push a Stack ";
        cout<<endl<<"2-> Pop a Stack ";
        cout<<endl<<"3-> Display a Stack ";
        cout<<endl<<" Please Enter your Choice ";
        cin>>n;
        switch(n)
        {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            case 3:
                disp();
            break;
            case 4:
                exit(1);
            break;

            default: 
            cout<<endl<<"wrong choice plz try again";
        }
    }while(n != 4);

    return 0;

}