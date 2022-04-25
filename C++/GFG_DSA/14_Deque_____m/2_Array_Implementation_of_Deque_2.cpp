#include <iostream>

using namespace std;

class Deque
{
    public:
    int *arr;
    int size;
    int cap;
    int front;

    Deque(int cap)
    {
        this->cap = cap;
        size = 0;
        arr = new int[cap];
        front = 0;
    }

    bool isFull()
    {
        return (size+1 == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void insertFront(int val)
    {
        if(isFull() == true)
        {
            cout<<endl<<"Queue is Full"<<endl;
            return;
        }
        front = (front+cap-1)%cap;
        arr[front] = val;
        size++;
    }
    
    void insertRear(int val)
    {
        if(isFull() == true)
        {
            cout<<endl<<"Queue is Full"<<endl;
            return;
        }
        int new_rear = (front + size)%cap;
        arr[new_rear] = val;
        size++;
    }

    void deleteFront()
    {
        if(isEmpty() == true)
        {
            return;
        }
        front = (front + 1) % cap;
        size--;
    }

    void deleteRear()
    {
        if(isEmpty() == true)
        {
            return;
        }
        size--;
    }


};

int main()
{

}