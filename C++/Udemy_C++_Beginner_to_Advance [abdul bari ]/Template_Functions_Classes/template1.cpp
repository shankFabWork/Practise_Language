#include <iostream>

using namespace std;

// template <class T>
// T maximum(T x,T y)
// {
//     return (x>y)?x:y;
// }

template <class T,class R>
float add(T x,R y)
{
    return (x+y);
}


int main()
{
    // cout<<maximum(2,4.6);
    
    cout<<add(2,4.6666);

    return 0;
}