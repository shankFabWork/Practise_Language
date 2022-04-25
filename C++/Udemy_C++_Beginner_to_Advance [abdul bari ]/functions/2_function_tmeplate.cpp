#include <iostream>

using namespace std;

template <class T>
T sum(T a,T b)
{
    return a+b;
}

int main()
{
    //d ==> double
    auto c=sum(1.1,2.2);
    cout<<typeid(c).name()<<"\n";

    //f ==> float
    auto d=sum(1.1f,2.2f);
    cout<<typeid(d).name()<<"\n";

    //i ==> integer
    auto e=sum(1,2);
    cout<<typeid(e).name()<<"\n";

    return 0;
}