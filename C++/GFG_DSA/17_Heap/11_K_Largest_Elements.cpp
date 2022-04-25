#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// I/P->
// 5 15 10 20 8
// k=2
// O/P->
// 15 20

bool comp(int a,int b)
{
  return a > b;
}

int main()
{
    int arr[]={5,15,10,20,8,25,18};
    int n=sizeof(arr)/sizeof(int);
    int k=3;    

    // sort(arr,arr+n,comp);
    // n.log(n)
    // for(int i=0;i<k;i++)
    // {
    //   cout<<arr[i]<<" ";
    // }

    // by default - max heap
    // priority_queue <int,vector<int>,greater<int>> pq;
    // make it min heap
    priority_queue <int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++)
    {
      pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
      if(pq.top() < arr[i])
      {
        pq.pop();
        pq.push(arr[i]);
      }
      else
      {
        continue;
      }
    }
    while(pq.empty() != true)
    {
      cout<<pq.top()<<" ";
      pq.pop();
    }

  // TC - O( k+(n-k).log(k) )

    return 0;
}


