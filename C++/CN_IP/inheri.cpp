#include <iostream>

using namespace std;

class Vehicle 
{
    private:
        string color;
    protected:
        string glassType;
    public:
        string materialType;

    void disp()
    {
        cout<<color<<" "<<glassType<<" "<<materialType<<endl;
    }

    ~Vehicle()
    {
        cout<<endl<<"Vehicle's destructor"<<endl;
    }


};

class Car:public Vehicle
{
    public:
    string gearType;

    Car(string glassType)
    {
        this->glassType = glassType;
    }

    void disp()
    {
        cout<<glassType<<" ";
        // cout<<materialType<<" "<<gearType<<endl;
    }

    ~Car()
    {
        cout<<endl<<"Car's destructor"<<endl;
    }
};


int main()
{
    Vehicle v;
    // v.color = "red";
    // v.glassType = "glass";
    v.materialType = "steel";
    // v.disp();

    Car c("glass");
    // c.color = "red";
    // c.glassType = "glass";
    c.materialType = "steel";
    c.disp();
}