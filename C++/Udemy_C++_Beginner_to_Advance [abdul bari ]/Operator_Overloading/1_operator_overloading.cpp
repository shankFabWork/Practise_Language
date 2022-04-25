// +
// *
// -
// ()
// ++  
// new delete

// Overloaded operators are functions with special names: the keyword 
// "operator" followed by the symbol for the operator being defined. 
// Like any other function, an overloaded operator has a return type 
// and a parameter list.

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

        void exprDisp()
        {
            cout<<endl;
            cout<<real<<" + "<<img<<" i ";
            cout<<endl;
        }

        void exprAdd1(Complex &c1,Complex &c2)
        {
            real=0;
            img=0;
            real=c1.real+c2.real;
            img=c1.img+c2.img;
        }

        Complex exprAdd2(Complex &c)
        {
            Complex temp;
            temp.real=real+c.real;
            temp.img=img+c.img;
            return temp;
        }

        Complex operator+(Complex &c)
        {
            Complex temp;
            temp.real=real+c.real;
            temp.img=img+c.img;
            return temp;
        }
};

int main()
{
    Complex c1(10,4);  
    Complex c2(20,23);  
    Complex c3(7,6);  
    c1.exprDisp();  
    c1.exprAdd1(c2,c3); 
    c1.exprDisp();


    Complex c4(5,4);  
    Complex c5(2,7); 

    Complex c6;
    c6=c4.exprAdd2(c5);
    c6.exprDisp();  

    Complex c7;
    //method - 1
    c7=c4.operator+(c5);
    c7.exprDisp();
    //method - 2
    c7=c4+c5; 
    c7.exprDisp();


    return 0;
}

