#include <iostream>

using namespace std;

class Demo
{
    public:
        int x;
        int y;

        Demo(int x=0,int y=0)
        {
            this->x=x;
            this->y=y;
        }

        void display() const 
        {
            // you can not modify 'x' and 'y' in constant function
            // x++;
            cout<<x<<" "<<y;
        }
};

void fun(const int &a,int &b)
{
    cout<<endl<<"Main "<<a<<" "<<b<<endl;
    //if const u wonn't be able to modify thi
    // a++;
}

int main()
{
    Demo d(1,2);
    d.display();
    int a=10;
    int b=20;
    fun(a,b);
    cout<<endl<<"Main "<<a<<" "<<b<<endl;
    
    return 0;
}