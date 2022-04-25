// Josephus Problem

#include <iostream>

using namespace std;

// I/P
// n = 7 , k= 3
// O/P
// 3

// I/P
// n = 8 , k= 2
// O/P
// 0    

int jos(int n,int k)
{
    if(n == 1)
    {
        return 0;
    }
    
    return (jos(n-1,k)+k)%n;
}

int myJos(int n,int k,int start=0)
{
    return jos(n,k) + start;
}

int main()
{
     int n=5;
     int k=3;

    cout<<jos(n,k)<<endl;

    cout<<myJos(n,k,1)<<endl;

    cout<<myJos(n,k,3)<<endl;


    // Time Complexity -> O(n)

    return 0;
}