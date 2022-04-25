#include <iostream>

using namespace std;

//build heap will make unordered heap (complete tree)
// into min_heap or max_heap (int this case max_heap() )
//then we will do heap_sort
// heap sort is based on selection sort

int left_node(int i)
{
    return 2*i+1;
}

int right_node(int i)
{
    return 2*i+2;
}

void max_heapify(int arr[], int n, int i) 
{
    int largest = i; 
    int l =  left_node(i); 
    int r = right_node(i);  
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        max_heapify(arr, n, largest); 
    } 
} 

void build_heap(int arr[],int n)
{
    for(int i=((n/2)-1);i>=0;i--)
    {
        max_heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n)
{
    for(int i=((n/2)-1);i>=0;i--)
    {
        max_heapify(arr,n,i);
    }

    for(int i=n-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);
        max_heapify(arr,i,0);
    }
}

int main()
{
    int arr[]={50,20,10,4,15};
    int n=sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(n-1 != i)
        {
            cout<<"-";
        }
    }
    cout<<endl;
    heap_sort(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}


