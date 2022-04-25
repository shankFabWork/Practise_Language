// Designing a data structure that 
// supports the following 
// operations in O(1) time.

// 1) Get Minimum
// 2) Get Maximum
// 3) Insert Minimum
// 4) Insert Maximum
// 5) Delete Minimum
// 6) Delete Maximum

#include <iostream>
#include <deque>

using namespace std;

class MyDS
{
    public:
    deque <int> dq;

    void insertMin(int x)
    {
        dq.push_front(x);
    }

    void insertMax(int x)
    {
        dq.push_back(x);
    }

    int getMin()
    {
        return dq.front();
    }

    int getMax()
    {
        return dq.back();
    }

    int extractMin()
    {
        int val = dq.front();
        dq.pop_front();
        return val;
    }

    int extractMax()
    {
        int val = dq.back();
        dq.pop_back();
        return val;
    }

};

int main()
{
    MyDS dq;
    dq.insertMin(5);
    dq.insertMax(10);
    dq.insertMin(3);
    dq.insertMax(15);
    dq.insertMin(2);
    dq.insertMax(20);

    cout<<dq.getMin()<<endl;
    dq.extractMin();
    cout<<dq.getMin()<<endl;

    cout<<dq.getMax()<<endl;
    dq.extractMax();
    cout<<dq.getMax()<<endl;
    



}