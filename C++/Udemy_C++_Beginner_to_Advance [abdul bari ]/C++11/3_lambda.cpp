#include <iostream>

using namespace std;

// [capture_list](parameter_list)->return_type { body }

template <typename T>
void fun(T p)
{
    p();
}

int main()
{
    [](){
        cout<<"hello";
    }();

    cout<<endl;
    
    [](int x,int y){
        cout<<(x+y);
    }(1,4);

    cout<<endl;
    
    int sum1=[](int x,int y)
    {
        return x+y;
    }(3,4);
    cout<<sum1;

    cout<<endl;
    
    auto f=[]()
    {
        cout<<"hello";
    };
    f();

    cout<<endl;

    int s=[](int x,int y)->int{
        return x+y;
    }(10,4);
    cout<<s;

    cout<<endl;

    int a=10;
    int b=34;

    [a,b]()
    {
        cout<<a<<" "<<b;
    }();

    cout<<endl;

    [](int a,int b)
    {
        cout<<a<<" "<<b;
    }(a,b);

    cout<<endl;

    [&a,&b]()
    {
        cout<<++a<<" "<<b++;
    }();

    cout<<endl;
    cout<<b;
    cout<<endl;

    int a1=34,b1=24;
    [&]()
    {
        cout<<++a1<<" "<<++b1;
    }();

    cout<<endl;

    int c1=20;
    auto m=[&]()
    {
        cout<<c1++<<endl;
    };
    fun(m);
    fun(m);
    cout<<c1;

    return 0;
}