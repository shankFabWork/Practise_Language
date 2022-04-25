#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue 
{
    public:
    
    Node* front;
    Node* rear;
    int size;

    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int val)
    {
        Node* New = new Node(val);
        if(front == NULL)
        {
            front = rear = New;
        }
        else
        {
            rear->next = New;
            rear = New;
        }
        size++;
    }

    void dequeue()
    {
        int val = front->data;
        if(front == NULL)
        {
            return;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            if(front == NULL)
            {
                rear = NULL;
            }
            delete temp;
        }
        size--;
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }


};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.getFront();
    cout<<q.getRear();
    q.dequeue();

}