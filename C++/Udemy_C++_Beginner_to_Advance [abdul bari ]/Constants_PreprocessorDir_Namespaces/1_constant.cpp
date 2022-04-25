#include <iostream>

#define X 10
//preprocessor directive
//also called macros
//defined by capital letters
//executed before compilation

using namespace std;



int main()
{
    //both are same
    // const int a=10;
    int const a=10;

    //cpnstant identifier
    //executed after compilation


    //will give u error
    // a++;
    cout<<a;

    int b=20;
    int *ptr1=&b;
    ++(*ptr1);
    cout<<endl<<b;


    const int c=20;
    //can not store constant identifier in the pointer
    // int *ptr2=&c;
    const int *ptr2=&c;

    //ptr2 is constant
    *ptr2=a;
    
    // ++(*ptr2);
    cout<<endl<<c;


     return 0;
}