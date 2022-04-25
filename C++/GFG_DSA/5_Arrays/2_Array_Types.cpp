#include <iostream>
#include <vector>

using namespace std;

// Array Data Structure Type
// ->fixed size array
// ->dynamic size array


int main()
{
    // ->fixed sized array

    // fixed size array storage types ::
    // 1) area in the stack segment
    // 2) area in the heap segment

    int n=10;
    int arr1[100];  //stack allocated
    int arr2[n]; //stack allocated
    int *arr3=new int[n]; //heap allocated
    int arr4[]={30,10,70,20}; //stack allocated

    // ->dynamic sized array
    //resize automatically

    vector <int> data;
    for(int i=0;i<20;i++)
    {
        cout<<data.size()<<" "<<data.capacity()<<endl;
        data.push_back(i);
    }




    return 0;
}
