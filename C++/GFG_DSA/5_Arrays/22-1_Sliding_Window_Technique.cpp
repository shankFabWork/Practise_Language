#include <iostream>

using namespace std;

// N-bonacci Numbers
// Input : N = 3, M = 8
// Output : 0, 0, 1, 1, 2, 4, 7, 13
// We need to print first M terms.
// First three terms are 0, 0 and 1.
// Fourth term is 0 + 0 + 1 = 1
// Fifth term is 0 + 1 + 1 = 2
// Sixth terms is 1 + 1 + 2 = 4
// Seventh term is 7 (1 + 2 + 4) and eighth
// term is 13 (7 + 4 + 2).

// Input : N = 4, M = 10
// Output : 0 0 0 1 1 2 4 8 15 29 

// print all the terms of the series upto 
// M-terms of the N-bonacci Numbers

void n_bonacci_numbers_one(int m,int n)
{
    int arr[m] = { 0 };
    arr[n-1] = 1;
    for(int i=n;i<m;i++)
    {
        for(int j=i-n;j<i;j++)
        {
            arr[i] += arr[j];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<arr[i]<<" ";
    }
}


// We can optimize for large values of N. The idea is based on 
// sliding window. The current term a[i] can be computed 
// as a[i-1] + a[i-1] – a[i-n-1]
void n_bonacci_numbers_two(int m,int n)
{
    int arr[m] = {0};
    arr[n-1] = 1;
    arr[n] = 1;

    for(int i=n+1;i<m;i++)
    {
        arr[i] = 2 * arr[i-1] - arr[i-n-1];
    }

    for(int i=0;i<m;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{    
    // //m is number of element you want
    int m = 10;
    // n is "N-bonacci series"
    int n = 4;

    // n_bonacci_numbers_one(m,n);
    // Time Complexity : O(M * N)
    // Auxiliary Space : O(M)


    n_bonacci_numbers_two(m,n);
    // Time Complexity : O(M)
    // Auxiliary Space : O(M)

    // m = 10
    // n = 4
    // 0 0 0 0 0 0 0 0 0  0
    // 0 0 0 1 1 0 0 0 0  0
    // 0 0 0 1 1 2 4 8 15 29 
    // 2*1-0 = 2
    // 2*2-0 = 4
    // 2*4-0 = 8
    // 2*8-1 = 15
    // 2*15-1 = 29
    // 2 * arr[i-1] - arr[i-n-1]



    // Count Distinct elements m every window of size k
    // I/P
    // 1 2 1 3 4 3 3
    // k=4
    // O/P
    // 3 4 3 2

    return 0;
}