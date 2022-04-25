#include <iostream>

using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int capacity;

    public:

        MinHeap(int c)
        {
            arr=new int[c];
            size=0;
            capacity=c;
        }

        int leftNode(int i)
        {
            return 2*i+1;
        }

        int rightNode(int i)
        {
            return 2*i+2;
        }

        int parentNode(int i)
        {
            return (i-1)/2;
        }

};

int main()
{


    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<'-';
    // }
    
    return 0;
}


