#include <iostream>

using namespace std;

class Car
{
    public:
        static int price;
        static int getPrice()
        {
            return price;
        }

};

int Car::price=0;

int main()
{
    Car c1;
    cout<<c1.price<<endl;
    cout<<c1.getPrice()<<endl;
    c1.price=10;
    cout<<Car::price<<endl;

    return 0;
}