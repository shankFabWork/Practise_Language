// Now we can use 
// push()
// pop()
// getMin()
// peek()
// in O(1) time complexity

// Space Complexity -> O(1)

// learn
// x - min
// min - x

#include <iostream>
#include <stack>

using namespace std;

struct MyStack
{
    public:
    stack <int> s;
    int min;
    
    void push(int x)
    {
        if(s.empty())
        {
            min = x;
            s.push(x);
        }
        else if(x <= min)
        {
            s.push(x - min);
            min = x;
        }
        else
        {
            s.push(x);
        }
    }

    int pop()
    {
        int x = s.top();
        s.pop();
        if(x <= 0)
        {
            int res = min;
            min = min - x;
            return res;
        }
        else
        {
            return x;
        }
    }

    int peek()
    {
        int x = s.top();
        return (s.top()<=0)?(min):x;
    }
    int getMin()
    {
        return min;
    }
};

int main()
{
    // works only for positive values
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin();


    return 0;
}