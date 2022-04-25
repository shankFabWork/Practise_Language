#include <iostream>

using namespace std;

class Shape
{
    public:
        virtual void disp()=0;
        virtual void area()=0;
        virtual void perimeter()=0;
};

class Rectangle:public Shape
{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l=1,int b=1)
        {
            cout<<endl<<"Rectangle------------->"<<endl;
            this->length=l;
            this->breadth=b;
        }

        void area()
        {
            cout<<endl;
            cout<<"area is "<<length*breadth;
            cout<<endl;
        }
        void perimeter()
        {
            cout<<endl;
            cout<<"perimeter is "<<2*(length+breadth);
            cout<<endl;
        }

        void disp()
        {
            cout<<endl;
            cout<<"length is "<<length<<endl;
            cout<<"breadth is "<<breadth<<endl;
            cout<<endl<<endl;
        }
};


class Cuboid:public Shape
{
    private:
        int length;
        int breadth;
        int height;
    public:
        Cuboid(int l=1,int b=1,int h=1)
        {
            cout<<endl<<"Cuboid------------->"<<endl;
            this->length=l;
            this->breadth=b;
            this->height=h;
        }

        void area()
        {
            cout<<endl;
            cout<<"area is "<<length*breadth;
            cout<<endl;
        }
        void perimeter()
        {
            cout<<endl;
            cout<<"perimeter is "<<2*(length+breadth);
            cout<<endl;
        }

        void disp()
        {
            cout<<endl;
            cout<<"length is "<<length<<endl;
            cout<<"breadth is "<<breadth<<endl;
            cout<<"height is "<<height<<endl;
            cout<<endl;
        }

};

class Circle:public Shape
{
    private:
        int radius;
    public:
        Circle(int r=0)
        {
            cout<<endl<<"Circle------------->"<<endl;
            this->radius=r;
        }

        void area()
        {
            cout<<endl;
            cout<<"area is "<<(3.14*radius*radius);
            cout<<endl;
        }
        void perimeter()
        {
            cout<<endl;
            cout<<"perimeter is "<<(2*3.14*radius);
            cout<<endl;
        }

        void disp()
        {
            cout<<endl;
            cout<<"radius is "<<radius<<endl;
            cout<<endl;
        }

};

int main()
{

    Shape *r1=new Rectangle(2,3);
    r1->area();

    Shape *r2=new Rectangle();
    r2->area();

    Shape *c1=new Cuboid(2,3,5);
    c1->perimeter();

    c1->disp();


    Shape *cir1=new Circle(10);
    cir1->area();
    cir1->perimeter();

    cir1->disp();

    return 0;
}