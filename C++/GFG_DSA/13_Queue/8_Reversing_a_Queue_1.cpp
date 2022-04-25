#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack <int> s;
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    while(q.empty() != true)
    {
        s.push(q.front());
        q.pop();
    }
    while(s.empty() != true)
    {
        q.push(s.top());
        s.pop();
    }
    while(q.empty() != true)
    {
        cout<<q.front()<<" ";
        q.pop();
    }

}