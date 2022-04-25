// the problem of implementation of 
// Two stacks in a single array.

// we are given an array we need to
// implement to two stack operations 
// using sigle array

// not doing method-1
// Method-2 : "A space efficient implementation"

#include <iostream>

using namespace std;

class MyStack
{
    public:
        int *arr;
        int cap;
        int top1,top2;

    MyStack(int n)
    {
        arr = new int[n];
        cap = n;
        top1 = -1;
        top2 = n;
    }

    void push1()
    {
            char ch;
            do
            {
                if(top1 < top2-1)
                {
                    top1++;
                    int val;
                    cout<<endl;
                    cout<<"please enter your value";
                    cout<<endl;
                    cin>>val;
                    arr[top1] = val;                
                    cout<<endl;
                    cout<<"do u want to insert again";
                    cout<<endl;
                    cin>>ch;
                }
                else
                {
                    cout<<endl;
                    cout<<"stack overflow";
                    cout<<endl;
                    return;
                }
            }while(ch == 'y' || ch == 'Y');
    }
    
    void push2()
    {
            char ch;
            do
            {
                if(top1 < top2)
                {
                    top2--;
                    int val;
                    cout<<endl;
                    cout<<"please enter your value";
                    cout<<endl;
                    cin>>val;
                    arr[top2] = val;
                    cout<<endl;
                    cout<<"do u want to insert again";
                    cout<<endl;
                    cin>>ch;
                }
                else
                {
                    cout<<endl;
                    cout<<"stack overflow";
                    cout<<endl;
                    return;
                }
            }while(ch == 'y' || ch == 'Y');
    }

    void pop1()
    {
        if(top1 >= 0)
        {
            cout<<endl;
            cout<<arr[top1]<<" is deleted";
            cout<<endl;
            top1--;
        }
        else
        {
            cout<<endl;
            cout<<"stack1 is empty";
            cout<<endl;
        }
    }
    
    void pop2()
    {
        if(top2 < cap)
        {
            cout<<endl;
            cout<<arr[top2]<<" is deleted";
            cout<<endl;
            top2++;
        }
        else
        {
            cout<<endl;
            cout<<"stack2 is empty";
            cout<<endl;
        }
    }

    void disp()
    {
        cout<<endl;
        cout<<"Stack 1";
        cout<<endl;
        for(int i=0;i<=top1;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Stack 2";
        cout<<endl;
        for(int i=cap-1;i>=top2;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int n;
    cout<<endl;
    cout<<"enter the size of the stack";
    cout<<endl;
    int val;
    cin>>val;
    MyStack s(val);
    do
    {     
        cout<<endl<<"1-> Push element in Stack1";
        cout<<endl<<"2-> Push element in Stack2";
        cout<<endl<<"3-> Pop element in Stack1";
        cout<<endl<<"4-> Pop element in Stack2";
        cout<<endl<<"5-> Display Stacks ";
        cout<<endl<<"6-> Display Capacity of array ";
        cout<<endl<<"7-> Change Capacity of array ";
        cout<<endl<<"8-> Exit ";
        cout<<endl<<" Please Enter your Choice ";
        cin>>n;
        switch(n)
        {
            case 1:
                s.push1();
            break;
            case 2:
                s.push2();
            break;
            case 3:
                s.pop1();
            break;
            case 4:
                s.pop2();
            break;
            case 5:
                s.disp();
            break;
            case 6:
                cout<<endl;
                cout<<"capacity of array is "<<s.cap;
                cout<<endl;
            break;
            case 7:
                cout<<endl;
                int val;
                cout<<"Enter your new capacity";
                cout<<endl;
                cin>>val;
                s.cap = val;
                cout<<endl;
            break;
            case 8:
                exit(1);
            break;

            default: 
            cout<<endl<<"wrong choice plz try again";
        }
    }while(n != 8);


    return 0;
}
