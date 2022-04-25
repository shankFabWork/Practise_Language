#include <iostream>

using namespace std;

class Vehicle
{
    private:
        int tyres;
    protected:
        string name;
    public:
        string color;

        Vehicle(int tyres,string name,string color)
        {
            this->tyres = tyres;
            this->name = name;
            this->color = color;
        }
};

class Car:public Vehicle
{
    public:
        string engine;


};

int main()
{
    Vehicle v(12,"ford","white");

    Car c;
}