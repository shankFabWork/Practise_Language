#include <iostream>

using namespace std;

class Test2;

class Test1
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

        Test1(int a=0,int b=0,int c=0)
        {
            this->a=a;
            this->b=b;
            this->c=c;
        }

        friend Test2;

};

class Test2
{

    public:
        void getAll(Test1 t1)
        {
            cout<<t1.a<<" "<<t1.b<<" "<<t1.c;
        }

};

//or

class Simple2;
class Simple1
{
    private:
        int a=10;
        friend Simple2;
};

class Simple2
{
    public:
        void fun()
        {
            Simple1 s1;
            cout<<endl<<s1.a<<endl;
        }
};


int main()
{

    Test1 t1(1,2,3);
    Test2 t2;
    t2.getAll(t1);

    Simple2 s2;
    s2.fun();
    

    return 0;
}
