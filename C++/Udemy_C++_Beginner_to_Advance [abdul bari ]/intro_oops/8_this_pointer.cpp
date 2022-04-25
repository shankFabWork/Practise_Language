#include <iostream>

using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;

    public:
        Rectangle(int length,int breadth)
        {
            //this will cause ambiguity
            // length=length;
            // breadth=breadth;
            this->length=length;
            this->breadth=breadth;
        }

        int area()
        {
            return this->length * this->breadth;
        }
};


int main()
{
    Rectangle r1(10,20);
    cout<<r1.area();

    return 0;
}