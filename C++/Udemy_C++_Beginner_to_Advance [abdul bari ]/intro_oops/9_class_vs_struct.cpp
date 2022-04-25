#include <iostream>

using namespace std;

class Rectangle1
{
    private:
        int length;
        int breadth;

    public:
        Rectangle1(int l,int b)
        {
            this->length=l;
            this->breadth=b;
        }

        int area()
        {
            return this->length * this->breadth;
        }
};


struct Rectangle2
{
    // private:
        int length;
        int breadth;

    public:
        Rectangle2(int l,int b)
        {
            this->length=l;
            this->breadth=b;
        }

        int area()
        {
            return this->length * this->breadth;
        }
};


//there is only one difference between classes and structures

//in classes data members and member functions are public by default
//if u want to make it public u can use access specifier "public:"
//if u want to make it private u can use access specifier "private:"

//in structures data members and member functions are public by default

int main()
{
    Rectangle1 r1(10,20);
    cout<<r1.area();

    Rectangle2 r2(30,20);
    cout<<r2.area();


    return 0;
}