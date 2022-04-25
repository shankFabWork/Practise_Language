#include <iostream>

using namespace std;

class Car
{
    private:
    public:
        //no reason to write like this
        // virtual void start()
        // {
        //     cout<<endl<<"car start"<<endl;
        // }

        // virtual void stop()
        // {
        //     cout<<endl<<"car stop"<<endl;
        // }

        //these are pure virtuaal functions
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