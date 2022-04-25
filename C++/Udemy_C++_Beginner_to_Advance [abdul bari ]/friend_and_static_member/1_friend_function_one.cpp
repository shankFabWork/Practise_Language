#include <iostream>

using namespace std;

class Test
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

        Test(int a=0,int b=0,int c=0)
        {
            this->a=a;
            this->b=b;
            this->c=c;
        }

        friend void getAll();
};

void getAll()
{
    Test t(1,2,3);
    cout<<t.a<<" "<<t.b<<" "<<t.c;
}

int main()
{
    getAll();

    return 0;
}