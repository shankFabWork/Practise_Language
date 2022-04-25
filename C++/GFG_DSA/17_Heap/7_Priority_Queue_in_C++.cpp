#include <iostream>
#include <queue>
//contains priority_queue data type

using namespace std;

// Priority_Queue in C++ is by default Max Heap

int main()
{
    // Priority_Queue in C++ is by default Max Heap
    //they are vectors (container) by default
    cout<<"==>Priority_Queue in C++ is by default Max Heap"<<endl;
    priority_queue <int> pq1;
    pq1.push(15);
    pq1.push(10);
    pq1.push(5);

    cout<<"size is "<<pq1.size()<<endl;
    cout<<"top element is "<<pq1.top()<<endl;

    while(pq1.empty() == false)
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;
    // we can implement min heap in priority queue using this syntax
    cout<<"==>Priority_Queue in C++ can be made as Min Heap"<<endl;
    cout<<"syntax :: 'priority_queue <int,vector<int>,greater<int>> pq2' ";
    cout<<endl;
    priority_queue <int,vector<int>,greater<int>> pq2;
    pq2.push(15);
    pq2.push(10);
    pq2.push(5);

    cout<<"size is "<<pq2.size()<<endl;
    cout<<"top element is "<<pq2.top()<<endl;

    while(pq2.empty() == false)
    {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    cout<<endl;
    cout<<"making priority queue using existing array/vectors"<<endl;

    //using array
    int arr[]={10,5,15};
    int n=sizeof(arr)/sizeof(int);
    priority_queue <int> pq3(arr,arr+n);
    // Time Complexity -> O(n) 
    while(pq3.empty() == false)
    {
        cout<<pq3.top()<<" ";
        pq3.pop();

    }

    cout<<endl;
    //using vector
    vector <int> v1;
    v1={10,5,15};
    priority_queue <int> pq4(v1.begin(),v1.end());
    // Time Complexity -> O(n) 

    cout<<endl;
    while(pq4.empty() == false)
    {
        cout<<pq4.top()<<" ";
        pq4.pop();
    }

    cout<<endl;
    //if you do not want to learn this sytax for min heap
    //priority_queue <int,vector<int>,greater<int>> pq2;
    cout<<" without this syntax "<<endl;
    cout<<" priority_queue <int,vector<int>,greater<int>> pq2"<<endl;
    vector <int> v2;
    v2={10,5,15};
    for(int i=0;i<v2.size();i++)
    {
        v2[i] = -1*v2[i];
    }
    priority_queue <int> pq5(v2.begin(),v2.end());

    cout<<endl;
    while(pq5.empty() == false)
    {
        cout<<(pq5.top()*-1)<<" ";
        pq5.pop();
    }

    // push()  and pop() -> O(log(n))
    // top() and empty() and size() -> O(1)

    //Application of Priority Queue :: 
    // =>Dijkstra Algorithm
    // =>Prim Algorithm
    // =>Huffman Algorithm
    // =>Heap Algorithm
    // =>Any other place where heap is used
    
    return 0;
}


