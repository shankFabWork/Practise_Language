#include <iostream>

using namespace std;

class Poly
{
    private:
    int *degCoeff;
    int cap;

    public:
    Poly()
    {
        cout<<endl;
        cout<<" Enter no of polynomial you want to enter => ";
        cout<<endl;
        cin>>cap;
        degCoeff = new int[cap];
        for(int i=0;i<cap;i=i+2)
        {
            cin>>degCoeff[i]>>degCoeff[i+1];
        }
    }

    Poly add(Poly p)
    {
        int start = 1;
        int end = 1;
        while(
            this->degCoeff[start] != p.degCoeff[end]
            && start < this->cap && end < p.cap
            )
        {
            if(this->degCoeff[start] > p.degCoeff[end])
            {
                start = start+2;
            }
            else if(this->degCoeff[start] > p.degCoeff[end])
            {
                end = end+2;
            }
            else if(this->degCoeff[start] == p.degCoeff[end])
            {
                this->degCoeff[start-1] = this->degCoeff[start-1] + p.degCoeff[end];
            }
            else
            {
                this->degCoeff[start-1] = this->degCoeff[start-1] + p.degCoeff[end];
            }
        }

        return *this;
    }

    void disp()
    {
        cout<<endl;
        for(int i=0;i<this->cap;i++)
        {
            cout<<this->degCoeff[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Poly p1;
    Poly p2;
    p1.add(p2);
    p1.disp();
}