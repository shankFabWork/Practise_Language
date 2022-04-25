#include <iostream>
#include <limits.h>

using namespace std;

struct KStacks
{
    int *arr,*next,*top;
    int freeTop,cap,k1;
    KStacks(int n,int k)
    {
        k1 = k;
        cap = n;
        arr = new int[n];
        next = new int[n];
        top = new int[k];
        for(int i=0;i<n-1;i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i=0;i<k1;i++)
        {
            top[i] = -1;
        }
        freeTop = 0;
    }

    bool isFull()
    {
        return (freeTop == -1);
    }

    bool isEmpty(int sn)
    {
        return (top[sn] == -1);
    }
    // i f n t i
    void push(int x,int sn)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        // i f n t i
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }


    // i t n f i
    int pop(int sn)
    {
        if(isEmpty(sn))
        {
            cout<<"Stack Underflow"<<endl;
            return INT_MAX;
        }
        // i t n f i
        int i = top[sn];
        top[sn]  =next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

int main()
{
    int cap = 10,k = 3;
    KStacks kn(cap,k);
    kn.push(100,0);
    kn.push(200,0);
    kn.push(300,1);
    kn.push(400,2);
    kn.push(500,2);

    cout << "Popped element from stack 2 is " << kn.pop(2);
    cout<< endl; 
    cout << "Popped element from stack 1 is " << kn.pop(1); 
    cout<< endl; 
    cout << "Popped element from stack 0 is " << kn.pop(0); 
    cout<< endl; 




    return 0;
}