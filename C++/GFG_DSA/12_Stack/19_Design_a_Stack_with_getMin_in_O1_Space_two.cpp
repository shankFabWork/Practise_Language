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

// handles -ve value

// replace 
// 1) 0 with min
// 2)  min - x to 2*min-x
// 2)  x - min to 2*x-min
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
            s.push(2 * x - min);
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
        if(x <= min)
        {
            int res = min;
            min = 2*min - x;
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
        return (s.top()<=min)?(min):x;
    }
    int getMin()
    {
        return min;
    }
};

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin();


    return 0;
}