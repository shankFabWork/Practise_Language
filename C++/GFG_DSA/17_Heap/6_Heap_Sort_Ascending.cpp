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

    int left(int i)
    {
        return 2*i+1;
    }

    int right(int i)
    {
        return 2*i+2;
    }


    void minHeapify(int i,int new_size)
    {
        int smallest = i;
        int lh = left(i);
        int rh = right(i);

        if(lh < new_size && arr[lh] < arr[i])
        {
            smallest = lh;
        }
        if(rh < new_size && arr[rh] < arr[smallest])
        {
            smallest = rh;
        }
        if(i != smallest)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(smallest,new_size);
        }
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
            minHeapify(i,size);
            // Time Complexity -> O(log(n))
            // Space Complexity -> O(n)
        }
    }

    void heapSort()
    {
        buildHeap();
        for(int i = size-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            minHeapify(0,i);
            // we have passed i as size in heapify
        }
    }

};

int main()
{
    Heap h(10);
    int arr[] = {10,5,20,2,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    h.take_this_array(arr,n);
    h.disp();
    h.heapSort();
    // Time Complexity - O(n.log(n)) in all cases
    // constant hidden
    // so quick and merge sort are used
    h.disp();
    return 0;
}