#include <iostream>

using namespace std;

class BasicCar
{

    public:
        void fun1()
        {
            cout<<endl<<"fun1 of BasicCar"<<endl;
        }
};

class AdvanceCar:public BasicCar
{
    public:
        void fun2()
        {
            cout<<endl<<"fun2 of AdvanceCar"<<endl;
        }


};

int main()
{
    BasicCar *b1,*b2;

    AdvanceCar c;
    b1=&c;
    b1->fun1();

    b2=new AdvanceCar();
    b2->fun1();

    // invalid conversion from 'BasicCar*' to 'AdvanceCar*'
    // AdvanceCar *r1;
    // r1=new BasicCar();
    // r1->fun1();

    



    return 0;
}

