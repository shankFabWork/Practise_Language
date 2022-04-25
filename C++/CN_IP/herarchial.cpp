#include <iostream>

using namespace std;

class A
{
    public:
    // A()
    // {
    //     cout<<endl<<"A constructor called "<<endl;
    // }
    A(string name,int age)
    {
        cout<<endl<<"A parameterized constructor called "<<endl;
        cout<<endl<<name<<" "<<age<<endl;
    }   
    ~A()
    {
        cout<<endl<<"A Destructor called "<<endl;
    }
    void disp()
    {
        cout<<"hello";
    }
};

class B:public A
{
    public:
    B(string name,int age) : A(name,age)
    {
        cout<<endl<<"B constructor called "<<endl;
    }
    ~B()
    {
        cout<<endl<<"B Destructor called "<<endl;
    }
};

class C:public A
{
    public:
    C(string name,int age) : A(name, age)
    {
        cout<<endl<<"C constructor called "<<endl;
    }
    ~C()
    {
        cout<<endl<<"C Destructor called "<<endl;
    }
};


class D:public B , public C
{
    public:
    D(string name,int age) : B(name, age) , C(name, age)
    {
        cout<<endl<<"D constructor called "<<endl;
    }
    ~D()
    {
        cout<<endl<<"D Destructor called "<<endl;
    }
};

int main()
{
    D d("shank",20);
    d.C::disp();

    // Constructor
    // A B A C D
    // D C A B A
}