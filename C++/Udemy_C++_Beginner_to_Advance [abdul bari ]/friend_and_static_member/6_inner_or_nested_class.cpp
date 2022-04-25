//writing a class inside another class
#include <iostream>

using namespace std;

class Outer
{
    public:
        int a=10;
        static int x;

        void fun()
        {
            i.display();
        }

        class Inner
        {
            public:
                int y=10;
                void display()
                {
                    //i can only access 'x' not 'a'
                    //as inner class only access->
                    //static data members as well as member functions

                    // invalid use of non-static data member 'Outer::a'   
                    // cout<<a;

                    cout<<endl<<"Display Inner "<<x<<endl;
                }
        };

        Inner i;
};

int Outer::x=20;

int main()
{

    Outer o1;
    o1.fun();

    Outer::Inner i;
    i.display();
    
    return 0;
}