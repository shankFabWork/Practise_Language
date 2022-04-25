#include <iostream>

using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray()
    {
        capacity = 1;
        data = new int[capacity];
        nextIndex = 0;
    }

    void insert(int val)
    {
        if(capacity == nextIndex)
        {
            int *nextData = new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                nextData = data;
            }
            nextData[nextIndex] = val;
            nextIndex++;
            delete []data;
            data = nextData;
            capacity = 2*capacity;
            return;
        }
        data[nextIndex] = val;
        nextIndex++;
    }

    int get(int i) const
    {
        if(i < nextIndex)
        {
            return data[i];
        }
        return -1;
    }

    void addValue(int i,int element)
    {
        if(i < nextIndex)
        {
            data[i] = element;
        }
        else if(i == nextIndex)
        {
            insert(element);
        }
        else
        {
            return;
        }
    }

    void disp() const
    {
        for(int i=0;i<nextIndex;i++)
        {
            cout<<data[i]<<" ";
        }
    }

    DynamicArray(DynamicArray &d)
    {
        this->capacity = d.capacity;
        this->data = new int[d.capacity];
        for(int i=0;i<=d.nextIndex;i++)
        {
            this->data[i] = d.data[i]; 
        }
        this->nextIndex = d.nextIndex;
    }

    
    void operator=(DynamicArray &d) const
    {
        this->capacity = d.capacity;
        this->data = new int[d.capacity];
        for(int i=0;i<=d.nextIndex;i++)
        {
            this->data[i] = d.data[i]; 
        }
        this->nextIndex = d.nextIndex;
    }

};

int main()
{
    DynamicArray d1;
    d1.insert(100);
    d1.insert(200);
    d1.insert(300);
    d1.insert(400);
    d1.insert(500);
    // DynamicArray d2(d1);
    DynamicArray d2 = d1;
    d2.addValue(0,10);
    d1.disp();
}