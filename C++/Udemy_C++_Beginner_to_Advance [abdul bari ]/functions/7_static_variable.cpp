#include <iostream>

using namespace std;

void incr_val()
{
    static int val=0;
    val=val+1;
    cout<<val<<"\t";
}

int main()
{
    for(int i=0;i<5;i++)
    {
        incr_val();
    }

    return 0;
}