#include <iostream>
#include <queue>

using namespace std;

// stack using two queue

class MyStack
{
    public:
    queue <int> q1,q2;

    void insert(int x)
    {
        while(q1.empty() != true)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.empty() != true)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

};

int main()
{
    MyStack s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    cout<<s.pop()<<endl;
    s.insert(40);
    cout<<s.pop()<<endl;

}