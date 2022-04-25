#include <iostream>
#include <algorithm>
#include <queue>

// I/P
// {25,7,10,15,20}
// O/P
// 25 16 10 12.5 15

using namespace std;


void Median_of_a_Stream_1(float arr[],int n)
{
    vector <float> v;
    for(int i=0;i<n;i++)    
    {
        v.push_back(arr[i]);

        sort(v.begin(),v.end());
        if(v.size() % 2 != 0)
        {
            cout<<v[(v.size()/2)]<<" ";
        }
        else
        {
            cout<<( ( v[v.size()/2] + v[(v.size()-1)/2] )/2 )<<" ";
        }
    }
}

void Median_of_a_Stream_2(float arr[],int n)
{
    priority_queue<float> max;
    priority_queue<float, vector<float>,greater<float>> min;
    max.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        float x = arr[i];
        if(max.size() > min.size())
        {
            if(max.top() > x)
            {
                min.push(max.top());
                max.pop();
                max.push(x);
            }
            else
            {
                min.push(x);
            }
            cout<<(float)( (max.top()+min.top()) /2)<<" ";
        }
        else
        {
            if(max.top() >= x)
            {
                max.push(x);
            }
            else
            {
                min.push(x);
                max.push(min.top());
                min.pop();
            }
            cout<<max.top()<<" ";
        }
    }
}

int main()
{
    // float arr[]={25,7,10,15,20};
    float arr[] = { 12, 15, 10, 5, 8, 7, 16};
    float n=sizeof(arr)/sizeof(float);

    Median_of_a_Stream_1(arr,n);
    cout<<endl;
    Median_of_a_Stream_2(arr,n);

    return 0;
}