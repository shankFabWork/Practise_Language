#include <bits/stdc++.h>

using namespace std;

class Heap
{
    int *arr;
    int cap;
    int size;
    public:
    Heap(int c)
    {
        cap = c;
        arr = new int[cap];
        size = 0;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return 2*i+1;
    }

    int right(int i)
    {
        return 2*i+2;
    }

    void insert(int val)
    {
        if(size == cap)
        {
            return;
        }
        size++; 
        arr[size-1] = val;
        int i = size-1;
        while(i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        } 
    }

    void minHeapify(int i)
    {
        int smallest = i;
        int lh = left(i);
        int rh = right(i);

        if(lh < size && arr[lh] < arr[i])
        {
            smallest = lh;
        }
        if(rh < size && arr[rh] < arr[smallest])
        {
            smallest = rh;
        }
        if(i != smallest)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    {
        if(size <= 0)
        {
            return INT_MIN;
        }
        if(size == 1)
        {
            size--;
            return arr[0];
        }

        swap(arr[0],arr[size-1]);
        size--;
        minHeapify(0);
        // Time Complexity -> O(log(n))
        // Space Complexity -> O(n)
        return arr[size];
    }

    void update(int i,int val)
    {
        arr[i] = val;
        while(i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
        minHeapify(0);
    }

    void delete_val(int i)
    {
        update(i,INT_MIN);
        extractMin();
    }

    void disp()
    {
        cout<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void take_this_array(int copy_arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            arr[i] = copy_arr[i];
        }
        size = n;
    }

    void buildHeap()
    {
        for(int i=(size-2)/2;i>=0;i--)
        {
            minHeapify(i);
            // Time Complexity -> O(log(n))
            // Space Complexity -> O(n)
        }

    }

};

int main()
{
    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.disp();
    cout<<h.extractMin();
    h.disp();
    h.update(3,22);
    // Time Complexity -> O(log(n))
    // Space Complexity -> O(n)
    h.disp();
    h.delete_val(2);
    // Time Complexity -> O(log(n))
    // Space Complexity -> O(n)
    h.disp();
    int arr[] = {10,5,20,2,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    h.take_this_array(arr,n);
    h.disp();
    h.buildHeap();
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    h.disp();
    return 0;
}