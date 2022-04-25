#include <iostream>

using namespace std;


// functions are used to perform a particular task

//functions overloading

int sum(int a,int b)
{
    return a+b;
}

int sum(int a,int b,int c)
{
    return a+b+c;
}

float sum(float a,float b,float c)
{
    return a+b+c;
}


int main()
{
    int d=sum(1,2);
    int e=sum(1,2,3);
    float f=sum(1.2f,2.1f,3.9f);
    // float f=sum(1.2f,2.1f,3.9f);
    cout<<d<<" "<<e<<" "<<f;

    return 0;
}