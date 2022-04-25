#include <iostream>

using namespace std;

class Test
{


    //access specifier
    public:
        void fun1()
        {
            cout<<"Inline function"<<endl;
        }

        void fun2();
        inline void fun3();

};

void Test::fun2()
{
    cout<<"Non-Inline function"<<endl;
}

void Test::fun3()
{
    cout<<"Non-Inline function"<<endl;
}


// function which is expand in the same line
// where they are called

//in inline function (function code inside the class)
//copy-paste is done in which fun1() call is replace with the code

//non-inline function  (function code outside the class)
//it will have seperate machine code

int main()
{
    Test t1;
    t1.fun1();
    t1.fun2();

    return 0;
}