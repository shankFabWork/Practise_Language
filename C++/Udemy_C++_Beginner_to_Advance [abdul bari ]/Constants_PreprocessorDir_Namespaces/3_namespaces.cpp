#include <iostream>

using namespace std;


//when we have a same name of the function then 
//we can seperate it with the help of the namespace

namespace First
{
    void fun()
    {
        cout<<endl<<"first function"<<endl;
    }
}
    
    
namespace Second
{
    void fun()
    {
        cout<<endl<<"second function"<<endl;
    }
}

using namespace First;

int main()
{
    fun();
    Second::fun();


    return 0;
}