#include <iostream>

using namespace std;


class BasicCar
{
    public:
        // void display()
        virtual void display()
        {
            cout<<endl<<" BasicCar class property"<<endl;
        }

};

class AdvanceCar:public BasicCar
{
    public:
        //comment and see output
        //
        void display()
        {
            cout<<endl<<" AdvanceCar class property"<<endl;
        }
        //

};

int main()
{

    BasicCar *b1=new AdvanceCar();
    b1->display();

    return 0;
}