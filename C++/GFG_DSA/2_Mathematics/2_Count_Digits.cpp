#include <iostream>

using namespace std;

// I/P
// x = 9235
// O/P
// 4

// I/P
// x = 38
// O/P
// 2

// I/P
// x = 7
// O/P
// 1

int count_digits(int n)
{
    int no=n,sum=0,counter=0;
    while(no)
    {
        if(no == 0)
        {
            return 0;
        }
        counter++;
        sum+=no%10;
        no=no/10;
    }
    cout<<endl<<counter<<endl;


    return sum;
}

int main()
{
    int n=1234421;
    int sum=count_digits(n);
    // Time Complexity -> O(d)
    // "d" is the number of digit
    cout<<endl<<sum<<endl;
    
    return 0;
}