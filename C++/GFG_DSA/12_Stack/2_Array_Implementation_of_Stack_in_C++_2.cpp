#include <iostream>
#include <vector>

using namespace std;
// Here Stack Implementation is using vectors

vector <int> v;

void push()
{
    char ch;
    do
    {
        cout<<"Please enter your value to be inserted ";
        cout<<endl;
        int val;
        cin>>val;
        cout<<endl;
        v.push_back(val);
        cout<<"do u want to insert again ?";        
        cout<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}


void pop()
{
    if(v.empty())
    {
        cout<<endl;
        cout<<"Stack is empty";
        cout<<endl;
        return;
    }
    cout<<endl;
    cout<<v.back()<<" is deleted successfully";
    cout<<endl;
    v.pop_back();
}

void disp()
{
    cout<<endl;
    for(auto it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
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