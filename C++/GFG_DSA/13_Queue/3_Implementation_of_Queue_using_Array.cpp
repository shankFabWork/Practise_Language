#include <iostream>
#include <stack>

using namespace std;


class MyQueue
{
    public:
    int size;
    int cap;
    int *arr;
    int front;
    int rear;

    MyQueue(int c)
    {
        arr = new int[c];
        cap = c;
        size = 0;
        front = 0;
        rear = cap - 1;    
    }

    bool isFull()
    {
        if(size == cap)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if(size == 0)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if(isFull() == true)
        {
            cout<<endl<<"Queue is Full"<<endl;
        }
        rear = (front+size-1)%cap;
        rear = (rear+1)%cap;
        arr[rear] = val;
        size++;
    }

    int dequeue()
    {
        if(isEmpty() == true)
        {
            cout<<endl<<"Queue is Empty"<<endl;
        }
        int item = arr[front];
        front = (front+1)%cap;
        size--;
        return item;
    }

    int getFront()
    {
        if(isEmpty() == true)
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if(isEmpty() == true)
        {
            return -1;
        }
        return arr[rear];
    }

};

// deletion from "front"
// insertion from "rear"
int main()
{
    // MyQueue q(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // cout<<q.getFront()<<endl;
    // cout<<q.getRear()<<endl;
    // q.dequeue();
    // cout<<q.getRear()<<endl;
    // cout<<q.getFront()<<endl;


    MyQueue q(5);
	q.enqueue(10); 
	q.enqueue(20); 
	q.enqueue(30); 
	q.enqueue(40); 

	cout<<q.dequeue()<<" dequeued from queue \n"; 

	cout<<"Front item is "<<q.getFront()<<endl; 
	cout<<"Rear item is "<<q.getRear()<<endl; 

    // Apart from dequeue which is O(n)
    // All operation has time complexity -> O(1)
}