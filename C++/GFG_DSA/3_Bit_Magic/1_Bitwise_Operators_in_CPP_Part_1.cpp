#include <iostream>

using namespace std;

int main()
{
    // there are total 6 bitwise operator in c++
    // AND -> &
    // OR  -> |
    // XOR -> ^
    // Left Shift Operator -> <<
    // Right Shift Operator -> >>
    // Bitwise Not -> ~

    int x=3;
    int y=6;

    cout<<(x&y)<<endl;
    cout<<(x|y)<<endl;
    cout<<(x^y)<<endl;

    cout<<(x<<1)<<endl;
    cout<<(x<<2)<<endl;

    // (x / (2^y) )
    x=33;
    cout<<(x>>1)<<endl;
    cout<<(x>>2)<<endl;



    //vaue of unsigned int -> 0 to 2^32 - 1
    // maximum value in 
    // unsigned integer -> 
    // 2^32 - 1
    // 4294967296 - 1
    // 4294967295
    unsigned int a=1;
    
    //2^32 - 1 
    //000001 -> 111110
    //2^32 - 1 -1
    // ans -> -2
    cout<<(~a)<<endl;  

    //2^32 - 1 
    //000101 -> 111010
    //2^32 - 1 -5
    // ans -> -6

    a=5;
    cout<<(~a)<<endl;

    //vaue of int -> // -2^32 to 2^32 - 1
    int b=1;
    
    //2^32 - 1 -1
    //-2

    cout<<(~b)<<endl;  

    //000101 -> 111010
    //2^32 - 1 -5
    //-6

    b=5;
    cout<<(~b)<<endl;


    return 0;
}