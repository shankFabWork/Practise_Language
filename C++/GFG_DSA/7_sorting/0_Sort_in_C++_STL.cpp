// containers->array, vector,degree

#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

struct Point{
    int x,y;
};

bool myComp(Point &p1,Point &p2)
{
    return p1.x > p2.x;
}

int main()
{
    int arr[]={40,20,30};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    for(int elem:arr)
        cout<<elem<<"\t";
    cout<<endl;
    sort(arr,arr+n,greater <int> ());
    for(int elem:arr)
        cout<<elem<<"\t";
    cout<<endl;
    // sort a vector
    vector <int> v {5,2,7,3,7,2};
    sort(v.begin(),v.end() );
    for(int elem:v)
        cout<<elem<<"\t";
    cout<<endl;
    sort(v.begin(),v.end(),greater <int> ());
    for(int elem:v)
        cout<<elem<<"\t";
    cout<<endl;

    Point parr[]={ {1,4},{2,6},{5,8} };
    sort(parr,parr+sizeof(parr)/(sizeof(int)*2),myComp);
    for(auto elem:parr)
        cout<<elem.x<<"-"<<elem.y<<" ";

    //worst and average case complexity is O(nlog(n))
    //sort function internally uses quick sort
    //if it will take more than O(nlogn) time then it will switch to heap sort
    //of array size is small it will switch to insertion sort







    return 0;
}