// Stack in C++ STL

// Stacks are a type of container adaptors with 
// LIFO(Last In First Out) type of working, where 
// a new element is added at one end and (top) an 
// element is removed from that end only.
 
// The functions associated with stack are:
// empty() – Returns whether the stack is empty
//         Time Complexity : O(1)
// size() – Returns the size
//         Time Complexity : O(1)
// top() – Returns a reference to top most element
//         Time Complexity : O(1)
// push(g) – Adds the element ‘g’ at the top
//         Time Complexity : O(1)
// pop() – Deletes the top most element
//         Time Complexity : O(1)

// Underflow -> when u pop empty stack
// Overflow -> when u push full stack

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"size is "<<s.size();
    cout<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}