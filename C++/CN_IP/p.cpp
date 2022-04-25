#include <iostream>
#include <cstring>

using namespace std;

class fraction
{
    private:
    int num;
    int den;

    public:
    fraction(int n,int d)
    {
        num = n;
        den = d;
    }

    fraction add(fraction const &f) const
    {
        int a = this->den*f.num + f.den*this->num;
        int b = this->den * f.den;
        fraction fnew(a,b);
        int small = min(fnew.num,fnew.den);
        for(int i=2;i<=small;i++)
        {
            if( (fnew.num%i == 0) && (fnew.den%i == 0) )
            {
                fnew.num = fnew.num/i;
                fnew.den = fnew.den/i;
            }
        }
        return fnew;
    }   

    fraction operator+(fraction const &f) const
    {
        int a = this->den*f.num + f.den*this->num;
        int b = this->den * f.den;
        fraction fnew(a,b);
        int small = min(fnew.num,fnew.den);
        for(int i=2;i<=small;i++)
        {
            if( (fnew.num%i == 0) && (fnew.den%i == 0) )
            {
                fnew.num = fnew.num/i;
                fnew.den = fnew.den/i;
            }
        }
        return fnew;
    }   

    fraction operator*(fraction const &f) const
    {
        int a = this->num * f.num;
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
        fraction fnew(a,b);
        return fnew;
    }

    void disp()
    {
        cout<<num<<" "<<den<<endl;
    }

    bool operator==(fraction f)
    {
        return ( (this->num == f.num ) && (this->den == f.den) );
    }
};

int main()
{
    fraction f1(10,2);
    fraction f2(15,4);
    // fraction frac = f1.add(f2);
    // frac.disp();
    fraction f = f1 + f2;
    f.disp();
    if(f1 == f1)
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"different"<<endl;
    }
    fraction fmul = f1*f2;
    fmul.disp();
}