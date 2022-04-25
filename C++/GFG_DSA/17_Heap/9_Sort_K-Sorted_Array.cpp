#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


// K-Sorted_Array (Nearly Sortd Array)

// Element at index 'i' will be parent between 
// the index (i-k) to (i+k) in the sorted array

// I/P->
// 9 8 7 18 19 17
// k=2


// O/P->
// 7 8 9 17 18 19

void sorting_of_k_sorted_array(int arr[],int n,int k)
{
    // priority_queue is by default a max heap
    // but we can make it min heap with this syntax ::
    // priority_queue < int , vector<int> , greater<int> > pq;

    priority_queue < int , vector<int> , greater<int> > pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(arr[i]);
    }
    // K.log(k)

    int index=0;
    for(int i=k+1;i<n;i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        // O(log(n))
        pq.push(arr[i]);
        // O(log(n))
    }
    // (n-k)*log(k)

    while(pq.empty() != true)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
    // k.log(k)

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
// O(n-k+k).log(k)
// O(n).log(k)


int main()
{
    int arr[]={9,8,7,18,19,17};
    int n=sizeof(arr)/sizeof(int);

    //Naive Approach :
    //Time Complexity -> O(n.log(n) )
    //Space Complexity -> O(1)
    // 1)
    // sort(arr,arr+n);

    // 2)
    int k=2;
    sorting_of_k_sorted_array(arr,n,k);



    
    return 0;
}


