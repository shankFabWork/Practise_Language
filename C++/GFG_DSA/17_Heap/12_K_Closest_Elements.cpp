#include <iostream>
#include <limits.h>
#include <cstdlib> 
#include <queue> 

using namespace std;

// I/P->
// 10 15 7 3 4
// x=8
// k=2
// ----------
// O/P->
// 7 10 

// I/P->
// 100 80 10 5 70
// x=2
// k=3
// -----------
// O/P->
// 5 10 70

void K_Closest_Elements_one(int arr[],int n,int x,int k)
{
    bool visited[n] = {false};
    for(int i=0;i<k;i++)
    {
        int min_diff = INT_MAX;
        int min_diff_index;
        for(int j=0;j<n;j++)
        {
            if(visited[j] == false && min_diff >= llabs(arr[j] - x))
            {
                min_diff = llabs(arr[j] - x); 
                min_diff_index = j;           
            }
        }
        visited[min_diff_index] = true;
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i] == true)
        {
            cout<<arr[i]<<" ";
        }
    }

}

typedef pair<int,int> data;

void K_Closest_Elements_two(int arr[],int n,int x,int k)
{
  priority_queue <pair<int,int>> pq;
  for(int i=0;i<k;i++)
  {
    pq.push({llabs(arr[i]-x),i});
  }

  for(int i=k;i<n;i++)
  {
    if(pq.top().first > llabs(arr[i]-x))
    {
      pq.pop();
      pq.push({llabs(arr[i]-x),i});
    }
  }

  while(pq.empty() != true)
  {
    cout<<arr[pq.top().second]<<" ";
    pq.pop();
  }

    // Time Complexity : O(n Log k)
}


int main()
{
    // int arr[]={100,80,10,5,70};
    // int x=2;
    // int k=3;
    
    // int arr[]={10,30,5,40,38,80,70};
    // int x=35;
    // int k=3;

    int arr[] = { -10, -50, 20, 17, 80 }; 
    int x = 20, k = 2; 

    int n=sizeof(arr)/sizeof(int);

    // K_Closest_Elements_one(arr,n,x,k);
    //Time Complexity -> O(n.k)
    //Space Complexity -> O(n)
    // visited array space

    K_Closest_Elements_two(arr,n,x,k);
    // Time Complexity -> O( n.log(k) )
    // if I will insert all elements 
    // time complexity will become n.log(n)
    // Space Complexity -> O(k) [ not O(n) ]
  
    return 0;
}

