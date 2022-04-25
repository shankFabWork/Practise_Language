#include <iostream>

using namespace std;


//purpose of inheritance:
//reusability  - u can use functions of the base class  
//polymorphism - pure virtual functions are used to achieve polymorphism


///this is abstract class
//because this is having pure virtual functions
//Car c1; 
//wrong 
// ( abstract classes can not create object , they are used for interfaces)
//Car *c2; use pointer to achieve polymorphism

class Car
{
    private:
    public:

        //these are pure virtuaal functions
        //they are just used for the interface
        //
        virtual void start()=0;

        virtual void stop()=0;

};

class Toyota:public Car
{
    public:
        void start()
        {
            cout<<endl<<"Toyota start"<<endl;
        }

        void stop()
        {
            cout<<endl<<"Toyota stop"<<endl;
        }

};

class Suzuki:public Car
{
    public:
        void start()
        {
            cout<<endl<<"Suzuki start"<<endl;
        }

        void stop()
        {
            cout<<endl<<"Suzuki stop"<<endl;
        }

};

class Honda:public Car
{
    public:
        void start()
        {
            cout<<endl<<"Honda start"<<endl;
        }

        void stop()
        {
            cout<<endl<<"Honda stop"<<endl;
        }

};

int main()
{
    Car *c=new Toyota();
    c->start();
    c=new Honda();
    c->start();


    return  0;
}