#include <iostream>
#include <limits.h>

using namespace std;

// I/P->

// O/P->

int leftNode(int i)
{
    return 2*i+1;
}

int rightNode(int i)
{
    return 2*i-1;
}


// Time Complexity -> O(log(n))
void min_heapify(int arr[], int n, int i) 
{ 
    int smallest = i; // Initialize smallest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is larger than smallest so far 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) 
    { 
        swap(arr[i], arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        min_heapify(arr, n, smallest); 
    } 
} 

void build_heap(int arr[],int n,int i,int x)
{
    arr[i]=x;
    //O(log(n))
    for(int i=(n/2-1);i>=0;i--) 
    {
        min_heapify(arr,n,i); 
        // O(log(n))
    }
    // but the reality is it is taking O(n) time
}

int parent(int i)
{
    return ((i-1)/2);
}

void update_key(int arr[],int i,int x)
{
    arr[i]=x;
    while( i != 0 && arr[i] < arr[parent(i)])
    {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

int extract_min(int arr[],int &n)
{
    if(n == 0)
    {
        return INT_MAX;
    }
    if(n == 1)
    {
        n--;
        return arr[0];
    }
    swap(arr[0],arr[n-1]);
    min_heapify(arr,n,0);
    n--;
    return n;
}

// ----------------------------------------------
void delete_key(int arr[],int &n,int i,int x)
{
    arr[i]=x;
    while( i != 0 && arr[i] < arr[parent(i)])
    {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }   
    extract_min(arr,n);
}

int extract_min_content(int arr[],int &n)
{
    if(n == 0)
    {
        return INT_MAX;
    }
    if(n == 1)
    {
        n--;
        return arr[0];
    }
    swap(arr[0],arr[n-1]);
    min_heapify(arr,n,0);
    n--;
    return n;
}

void make_min_heap(int arr[],int n)
{
    for(int i=((n/2)-1);i>=0;i--)
    {
        min_heapify(arr,n,i);
    }
}


int main()
{
    int arr[]={10,50,90,80,100,70};
    int n=sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i != n-1)
        {
            cout<<'-';
        }
    }
    cout<<endl;

    // build_heap(arr,n,3,5);
    //using array


    make_min_heap(arr,n);


    // decreasing_key_then_extract_min(arr,n,3);
    //decreasing_key by comparing it with -INFINITY i.e. INT_MIN (limits.h)
    
    delete_key(arr,n,3,INT_MIN);

    //using while loop
    update_key(arr,3,5);


    // n=extract_min(arr,n);
    //removing root element i.e. root element
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i != n-1)
        {
            cout<<'-';
        }
    }

    
    return 0;
}

    //      0        height=2
    //    /   \      
    //   0     0     height=1
    //  / \   /  \
    // 0   0  0   0  height=0

    //n=7
    // nodes at level h is 
    // -->     ceil[n/(2^(h+1))]