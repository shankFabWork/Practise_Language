#include <iostream>

using namespace std;

class Parent
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

    void setParent(int a=0,int b=0,int c=0)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }

    void dispVal()
    {
        cout<<"a is "<<a<<endl<<"b is "<<b<<endl<<"c is "<<c;
    }
};

// class Child:public Parent
// class Child:protected Parent
class Child:private Parent
{
    protected:
    public:
        void setChild(int a=0,int b=0,int c=0)
        {

            // can not access a as it is private
            // (public)
            // this->a=a; 


            this->b=b;
            this->c=c;
        }

        void dispVal()
        {
            cout<<"a is private not accessable"<<endl<<"b is "<<b<<endl<<"c is "<<c;
        }
};


class GrandChild:public Child
{
    public:
        void setGrandChild(int a=0,int b=0,int c=0)
        {

            // can not access a as it is private
            //(public)
            // this->a=a;

            //(private)
            // this->b=b;
            // this->c=c;
        }

        void dispVal()
        {
            cout<<"a is private not accessable"<<endl;
            // cout<<"b is "<<b<<endl;
            // cout<<"c is "<<c;
        }
};


int main()
{
    GrandChild g1;
    // cout<<g1.a;
    // cout<<g1.b;
    // cout<<g1.c;
    g1.setGrandChild(1,2,3);
    g1.dispVal();


    return 0;
}