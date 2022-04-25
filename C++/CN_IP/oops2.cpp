#include <iostream>

using namespace std;

class Fraction
{
    private:
    int num;
    int den;

    public:
    Fraction(int num,int den)
    {
        this->num = num;
        this->den = den;
    }

    Fraction &operator++(int)
    {
        int a = num;
        int b = den;
        a = a + den;
        
        int small = min(a,b);
        for(int i=2;i<=small;i++)
        {
            if( (a%i == 0) && (b%i == 0) )
            {
                a = a/i;
                b = b/i;
            }
        }
        
        num = a;
        den = b;
        return *this;
    }

    Fraction &operator+=(Fraction f)
    {
        int a = this->den*f.num + f.den*this->num;
        int b = this->den * f.den;
        int small = min(a,b);
        for(int i=2;i<=small;i++)
        {
            if( (a%i == 0) && (b%i == 0) )
            {
                a = a/i;
                b = b/i;
            }
        }
        this->num = a;
        this->den = b;
        return *this;
    }

    void disp()
    {
        cout<<num<<" "<<den<<endl;
    }
};

int main()
{

    Fraction f1(10,3);
    Fraction f2(5,2);
    // Fraction f2 = ++(++f1);
    // Fraction f2 = f1++;
    (f1 += f2) += f2;
    f1.disp();
    f2.disp();

}