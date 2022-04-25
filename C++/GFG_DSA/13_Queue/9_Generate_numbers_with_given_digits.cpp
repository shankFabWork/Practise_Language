// Given a number n, print first n 
// number(in increasing order) such that 
// all these numbers have digits 
// in set {5, 6}

#include <iostream> 
#include <queue>

using namespace std; 

int main()
{
    queue <string> q;
    q.push("5");
    q.push("6");
    int n = 5;
    for(int i=0;i<n;i++)
    {
        string val = q.front();
        q.pop();
        cout<<val<<" ";
        q.push(val+"5");
        q.push(val+"6");
    }

    // Time Complexity -> O(n)
    
}
