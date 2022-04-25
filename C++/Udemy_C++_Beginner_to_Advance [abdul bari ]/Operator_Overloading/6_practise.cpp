#include <iostream>

using namespace std;

class Coordinate
{
    public:
        int x;
        int y;

        Coordinate()
        {
            x=0;
            y=0;
        }

        void setCoord(int x=0,int y=0)
        {
            this->x=x;
            this->y=y;
        }

        void dispCoord()
        {
            cout<<endl<<"x is "<<x<<" y is "<<y<<endl;
        }

        friend Coordinate operator+(Coordinate &c1,Coordinate &c2);
        friend void operator==(Coordinate &c1,Coordinate &c2);
        friend void operator^(Coordinate &c1,Coordinate &c2);
        friend void operator>(Coordinate &c1,Coordinate &c2);
        friend ostream& operator<<(ostream &o,Coordinate &c);
        friend istream& operator>>(istream &i,Coordinate &c);
    };

        ostream& operator<<(ostream &o,Coordinate &c)
        {
            o<<endl<<"x is "<<c.x<<" y is "<<c.y;
            return o;
        }


        istream& operator>>(istream &i,Coordinate &c)
        {
            i>>c.x>>c.y;
            return i;
        }


        Coordinate operator+(Coordinate &c1,Coordinate &c2)
        {
            Coordinate c;
            c.x=c1.x+c2.x;
            c.y=c1.y+c2.y;
            return c;
        }

        void operator==(Coordinate &c1,Coordinate &c2)
        {
            if(c1.x == c2.x && c1.y == c2.y)
            {
                cout<<endl<<"both are equal"<<endl;
            }
            else
            {
                cout<<endl<<"both are not equal"<<endl;
            }
        }

        void operator^(Coordinate &c1,Coordinate &c2)
        {
            c1.x=c1.x+c2.x;
            c1.y=c1.y+c2.y;
        }

        void operator>(Coordinate &c1,Coordinate &c2)
        {
            if(c1.x == c2.x && c1.y == c2.y)
            {
                cout<<endl<<"both are equal"<<endl;
            }
            if(c1.x >c2.x)
            {
                cout<<endl<<"c1 is greater than c2 in x"<<endl;
            }
            else if(c1.x < c2.x)
            {
                cout<<endl<<"c2 is greater than c1 in x"<<endl;
            }
            else
            {
                cout<<endl<<"c2 is same as c1 in x"<<endl;
            }
            if(c1.y > c2.y)
            {
                cout<<endl<<"c1 is greater than c2 in y"<<endl;
            }
            else if(c1.y < c2.y)
            {
                cout<<endl<<"c2 is greater than c1 in y"<<endl;
            }
            else
            {
                cout<<endl<<"c2 is same as c1 in y"<<endl;
            }
        }


int main()
{
    Coordinate c1;
    c1.setCoord(2,5);
    c1.dispCoord();

    Coordinate c2;
    c2.setCoord(8,5);
    c2.dispCoord();

    Coordinate c3;
    c3=c1+c2;
    c3.dispCoord();

    (c1==c1);

    c1>c2;

    c1.dispCoord();
    c2.dispCoord();
    c1^c2;
    c1.dispCoord();

    Coordinate c4;
    cin>>c4;
    cout<<c4;





    return 0;
}