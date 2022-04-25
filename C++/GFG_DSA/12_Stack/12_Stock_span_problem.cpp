// number of day on the left side 
// which is consecutive
// should be smaller or equal
// including the current date  

// I/P
// 13 15 12 14 16 8 6  4 10 30
// O/P
// 1   2  1  2  5  1 1  1 4  10

// I/P
// 10 20 30 40 
// O/P
// 1 2 3 4

// I/P
// 40 30 20 10
// O/P
// 1   1   1  1

// I/P
// 30 20 25 28 27 29
// O/P
// 1   1  2  3  1  5

#include <iostream>
#include <stack>

using namespace std;

void Stock_span_problem_one(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        int span = 1;
        for(int j=i-1;j>=0 && arr[j] <= arr[i];j--)
        {
            span++;
        }
        cout<<span<<" ";
    }
}


void Stock_span_problem_two(int arr[],int n)
{
    stack <int> s;
    s.push(0);
    cout<<1<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty() != true && arr[s.top()]<=arr[i])
        {
            s.pop();
        }
        int span = (s.empty() == true)?(i+1):(i-s.top());
        cout<<span<<" ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {30,20,25,28,27,29};
    int n = sizeof(arr)/sizeof(int);
    // similar to "previous greater element" problem
    // but in this we push index
    // but in "previous greater element" 
    // we push element in that index
    Stock_span_problem_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)
    cout<<endl;
    // find the closest or first gratest element
    //  on the left and subtract thier indexes
    // it the element itself is greater 
    // than any other element
    // then just add +1
    Stock_span_problem_two(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)


    return 0;
}