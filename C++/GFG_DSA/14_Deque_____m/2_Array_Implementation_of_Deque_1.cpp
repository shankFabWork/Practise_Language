#include <iostream>

using namespace std;

// Simple Implementation
class Deque
{
    public:

    int size;
    int cap;
    int *arr;

    Deque(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void insertFront(int data)
    {
        if(isFull())
        {
            cout<<endl<<"Queue is Full"<<endl;
        }
        else if(size+1 <= cap)
        {
            for(int i=0;i<size;i++)
            {
                arr[i] = arr[i+1];
            }
            arr[0] = data;
            size++;
        }
    }
    
    void insertRear(int data)
    {
        if(isFull())
        {
            cout<<endl<<"Queue is Full"<<endl;
        }
        else if(size+1 <= cap)
        {
            arr[size] = data;
            size++;
        }
    }

    void deleteFront()
    {
        if(isEmpty())
        {
            cout<<endl<<"Queue is Empty"<<endl;
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
        }
    }

    void deleteRear()
    {
        if(isEmpty())
        {
            cout<<endl<<"Queue is Empty"<<endl;
        }
        else
        {
            size--;
        }
    }

    void printAll()
    {
        cout<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Deque d(3);
    d.insertRear(10);
    d.insertRear(20);
    d.insertRear(30);
    d.printAll();
    d.insertRear(40);
    d.deleteRear();
    d.printAll();
    d.deleteFront();
    d.printAll();
}