#include <iostream>

#define X 10
#define c cout
#define square(x) x*x
#define msg_under_double_qoutes(x) #x

// if u won't define it it will define PI as 3
#define PI 3.14

#ifndef PI
    #define PI 3
    // it won't run until PI is defined
#endif

#define max(x,y) (x>y?x:y)

//preprocessor directive
//also called macros
//defined by capital letters
//executed before compilation

using namespace std;



int main()
{
    c<<endl<<X<<endl;
    c<<square(20)<<endl<<msg_under_double_qoutes(shank)<<endl;
    c<<PI<<endl;
    c<<max(24,35);

     return 0;
}