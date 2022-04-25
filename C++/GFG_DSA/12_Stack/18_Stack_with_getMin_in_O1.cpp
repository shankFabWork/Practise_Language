// I/P
// push(20)
// push(10)
// getMin()
// push(5)
// getMin()
// pop()
// getMin()
// pop()
// getMin()
// O/P
// 10 5 10 20 

// I/P
// push(5)
// push(4)
// push(3)
// getMin()
// pop()
// getMin()
// push(2)
// getMin()
// O/P
// 3 4 2  


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyStack
{
    public:
    stack <int> ms;
    stack <int> as;

    void push(int x)
    {
        if(ms.empty() == true)
        {
            as.push(x);
            ms.push(x);
        }
        ms.push(x);
        if(as.top() >= ms.top())
        {
            as.push(x);
        }
    }
    void pop()
    {
        if(as.top() == ms.top())
        {
            as.pop();
        }
        ms.pop();
    }

    int getMin()
    {
        return as.top();
    }
};

int main()
{
    MyStack ms; 
    ms.push(4);
    ms.push(5);
    ms.push(8);
    ms.push(1);
    ms.pop();
    cout<<endl<<ms.getMin();

    // TC - O(1)
    // SC - O(n)

    return 0;
}