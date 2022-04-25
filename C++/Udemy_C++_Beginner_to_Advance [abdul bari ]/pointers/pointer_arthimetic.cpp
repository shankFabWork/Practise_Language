// pointer is a type of variable used to store address of another variable

#include <iostream>

using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6};
    int *p=arr;
    cout<<*p<<"\t";
    p++;
    //incremented now starts with '2'
    cout<<*p<<"\t"; 

    cout<<*(p+2)<<"\t";
    cout<<endl<<"--------------"<<endl;
    for(int i=0;i<sizeof(arr)/sizeof(int)-1;i++)
    {
        // cout<<endl<<*(arr+i)<<endl;
        // cout<<endl<<p[i]<<endl;
        cout<<endl<<*p<<endl;
        p++;
    }

    return 0;
}