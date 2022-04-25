// I/P
// Weights : 50 20 30
// Values : 600 500 400
// Knapsack Capacity -> 70
// O/P
// 1140

// I/P
// Weights : 10 5 20
// Values : 200 50 100
// Knapsack Capacity -> 15
// O/P
// 15

#include <iostream>
#include <algorithm>

using namespace std;

bool myComp(pair <int,int> a1,pair <int,int> a2)
{
    double r1 = (double)(a1.first/a1.second);
    double r2 = (double)(a2.first/a2.second);
    return r1 > r2;
}

int Fractional_Knapsack(pair <int,int> arr[],int n,int weight)
{
    sort(arr,arr+n,myComp);

    int total_profit = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].second <= weight)
        {
            weight = weight - arr[i].second;
            total_profit += arr[i].first;
        }
        else
        {
            total_profit += (double)(arr[i].first * weight/arr[i].second);
            break;
        }
    }
    return total_profit;
}



int main()
{
    // In Fractional Knapsack, we can break items 
    // for maximizing the total value of knapsack
    
    // Items has two parts :-
    // first -> value
    // second -> weight
    pair <int,int> arr[] = 
    {
        make_pair(120,30),
        make_pair(100,20),
        make_pair(60,10)
    };
    // after sorting values 
    // according to (value/weight) fraction
    // (60,10) (100,20) (120,30)
    int n =sizeof(arr)/sizeof(pair <int,int>);
    int weight = 50;
    cout<<Fractional_Knapsack(arr,n,weight);

    return 0;
}
