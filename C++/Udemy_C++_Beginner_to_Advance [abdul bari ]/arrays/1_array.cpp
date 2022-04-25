#include <iostream>


using namespace std;

int main()
{
    float arr[]={1,2,3.3f};
    // int n=sizeof(arr)/sizeof(int);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<"\t";
    // }
    cout<<endl;
    for(auto x:arr)
        cout<<x<<"\t";

    char arr2[]={'a','b',65,90};
    cout<<endl;
    for(auto x:arr2)
        cout<<x<<"\t";


    return 0;
}