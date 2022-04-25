#include <iostream>

using namespace std;

//parameter passing

//call by value 
//->when u want to perform some functions like addition and return something

//call by address


//call by reference

//formal parameters
void swap(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout<<x<<" "<<y<<"\n";
}


int main()
{

    //actual parameters
    int x=10;
    int y=20;
    cout<<x<<" "<<y<<"\n";
    swap(x,y);
    cout<<x<<" "<<y<<"\n";

    
    return 0;
}