#include <iostream>

using namespace std;

// Tail recursion always take less no of time
// as compared with the normal recursion function

//no function is waiting for its call to happen

// in modern compiler Tail recursion
// takes less time as compared to the
// normal recursive functions

#include <iostream>

using namespace std;

void fun1(int n)
{
    if(n == 0)
    {
        return;
    }
    cout<<n<<" ";
    fun1(n-1);
}

void fun2(int n)
{
    if(n == 0)
    {
        return;
    }
    fun2(n-1);
    cout<<n<<" ";
}


//this is tail recursive function
void fun3(int n)
{
    start:
    if(n == 0)
    {
        return;
    }
    cout<<n<<" ";
    // fun3(n-1);
    // tail recusion is replaced by this code in modern compilers
    //this is knows as tail recursion elemination
    // or
    n=n-1;
    goto start;
}


//convert a non-tail recursion to a tail recursion i.e. fun2()
void fun4(int n,int k=1)
{
    if(n == 0)
    {
        return;
    }
    cout<<k<<" ";
    fun4(n-1,k+1);
}

int fact1(int n)
{
    if( n == 1 || n == 0)
    {
        return 1;
    }
    return n*fact1(n-1);
}

int fact2(int n,int k=1)
{
    if( n == 1 || n == 0)
    {
        return k;
    }
    return fact2(n-1,k*n);
}

int main()
{
    fun1(5);
    cout<<endl;
    fun2(5);
    cout<<endl;
    fun3(5);
    cout<<endl;
    fun4(8);
    cout<<endl;
    cout<<fact1(4); //this is not a tail recursion
    cout<<endl;
    cout<<fact2(4); //this is a tail recursion

    return 0;
}