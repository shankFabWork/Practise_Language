#include <iostream>

using namespace std;


template <class T>
class Stack
{
    private:
        T *stk;
        int top;
        int size;

    public:
        Stack(int sz)
        {
            size=sz;
            top=-1;
            stk=new T[size];
        }

        auto getStack()
        {
            return stk;
        }

        void push(T);
        T pop();


};

        template <class T>
        void Stack<T>::push(T x)
        {
            if(top == size)
            {
                cout<<endl<<"stack is full"<<endl;
            }
            else
            {
                top++;
                stk[top]=x;
            }
            
        }

        template <class T>
        T Stack<T>::pop()
        {
            T x=0;
            if(top == -1)
            {
                cout<<endl<<"stack is empty"<<endl;
            }
            else
            {
                x=stk[top];
                top--;
            }
            return x;            
        }


int main()
{
    Stack<float> s(10);
    s.push(23);
    s.push(45);
    s.push(41.123);

    for(int i=0;i<sizeof(s.getStack())-1;i++)
    {
        cout<<s.getStack()[i]<<"\t";
    }

    return 0;
}