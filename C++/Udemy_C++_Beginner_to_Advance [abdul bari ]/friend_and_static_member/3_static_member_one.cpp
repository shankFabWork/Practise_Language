#include <iostream>

using namespace std;

class Test
{
    public:
        int a;
        static int count;

        Test()
        {
            count++;
        }

        static int getCount()
        {
            //can not access any data member 
            //if it is not static data member
            // a++;    
            return count;
        }
};

int Test::count = 0;

int main()
{
    Test t1,t2;
    cout<<endl<<t1.count<<endl;
    cout<<endl<<t2.count<<endl;
    cout<<endl<<Test::count<<endl;
    t1.count=20;
    cout<<endl<<t1.getCount()<<endl;
    cout<<endl<<Test::getCount()<<endl;


    return 0;
}