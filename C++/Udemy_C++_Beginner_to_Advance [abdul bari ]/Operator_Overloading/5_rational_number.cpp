#include <iostream>

using namespace std;

class Rational
{
    private:
        int num,den;
    public:
        Rational(int n=0,int d=0)
        {
            num=n;
            den=d;
        }


        void Disp()
        {
            cout<<endl;
            cout<<num<<" "<<den;
            cout<<endl;
        }

        friend Rational operator+(Rational &r1,Rational &r2);

        friend Rational operator/(Rational &r1,Rational &r2);

        friend ostream& operator<<(ostream &o,Rational &r);

};

Rational operator+(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.num=r1.num+r2.num;
    temp.den=r1.den+r2.den;
    return temp;
}

Rational operator/(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.num=(r1.num*r2.den)+(r2.num*r1.den);
    temp.den=r1.den*r2.den;
    cout<<endl<<temp.num<<" / "<<temp.den<<" = "<<endl;

    int n;
    if(temp.num > temp.den)
    {
        n=temp.num;
    }
    else
    {
        n=temp.den;
    }

        for(int i=2;i<n;i++)
        {
            while( temp.num % i ==0 && temp.den % i ==0)
            {
                if( temp.num % i ==0 && temp.den % i ==0)
                {
                    temp.num=temp.num/i;
                    temp.den=temp.den/i;
                }
            }
        }


    return temp;
}


ostream & operator<<(ostream &o,Rational &r)
{
    o<<endl<<r.num<<" + "<<r.den<<endl;
    return o;
}

int main()
{
    Rational r1(1,4),r2(10,4),r3;
    r3=r1/r2;

    // r1.Disp();
    // r2.Disp();
    // r3.Disp();
    
    cout<<r1<<r2<<r3;
    // operator<<(cout,r3);


    return 0;
}