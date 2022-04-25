#include <iostream>

using namespace std;

class Car
{
    public:
    void disp();
};

class vehicle
{
    private:
    string color;
    protected:
    string materialType;

    public:
    friend void Car :: disp();
    friend void show();
};

void show()
{
    vehicle v;
    v.color = "red";
    v.materialType = "steel";
    cout<<v.color<<" "<<v.materialType<<endl;
}

void Car :: disp()
{
    vehicle v;
    v.color = "red";
    v.materialType = "steel";
    cout<<v.color<<" "<<v.materialType<<endl;
}


int main()
{
    // Car c;
    // c.disp();
    show();
}