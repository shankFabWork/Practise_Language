#include <iostream>

using namespace std;

class Complex
{
    private:
        int real;
        int img;
    public:


        Complex(int r=0,int i=0)
        {
            real=r;
            img=i;
        }

        void compDisp()
        {
            cout<<endl;
            cout<<real<<" + "<<img<<" i ";
            cout<<endl;
        }

        
        void compAdd(Complex &c1,Complex &c2)
        {
            Complex temp;
            real=c1.real+c2.real;
            img=c1.img+c2.img;
        }


        friend ostream& operator<<(ostream &o,Complex &c);
        // friend void operator<<(ostream &o,Complex &c);
};

ostream& operator<<(ostream &o,Complex &c)
// void operator<<(ostream &o,Complex &c)
{
    o<<endl<<c.real<<" + "<<c.img<<" i "<<endl;
    return o;
}


int main()
{
    Complex c1(1,2),c2(11,2);
    Complex c3;
    c3.compAdd(c1,c2);
    // c3.compDisp();

    //both are same
    // operator<<(cout,c3);
    // cout<<c3;

    // void operator<<(ostream &o,Complex &c)
    //we can not write endl
    
    cout<<c3<<c1;
    return 0;
}