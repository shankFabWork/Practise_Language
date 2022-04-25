#include <iostream>
#include <fstream>

using namespace std;


//once the function ends 
//automatically the destructor gets destroyed

class Test
{
    public:
        //contructor is used for allocating purposes
        
        int *arr;
        ifstream fis;

        Test()
        {
            //memory allocation
            cout<<endl<<"Test Created"<<endl;
            arr=new int[10];
            fis.open("shank.txt");
        }

        ~Test()
        {
            cout<<endl<<"Test Destroyed"<<endl;
            delete []arr;
            fis.close();
            //otherwise it will cause memory leak problem   
            //memory deallocation
        }

};

int main()
{
    Test *t1=new Test();
    delete t1;
    
    return 0;
}