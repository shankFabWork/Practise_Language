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


        friend Complex operator+(Complex &c1,Complex &c2);


        //can also write like this
        //in refernce "&" change will get copy and reflected back

        // friend Complex operator+(Complex c1,Complex c2);
        
        //friend function never implemented inside the class
        //we have to use it outside
        //can make prototype inside the class
};

// Complex operator+(Complex &c1,Complex &c2)

Complex operator+(Complex &c1,Complex &c2)
{
    Complex temp;
    temp.real=c1.real+c2.real;
    temp.img=c1.img+c2.img;
    return temp;
}

int main()
{
    Complex c1(1,2),c2(11,2);
    Complex c3=c1+c2;
    c3.compDisp();


    return 0;
}