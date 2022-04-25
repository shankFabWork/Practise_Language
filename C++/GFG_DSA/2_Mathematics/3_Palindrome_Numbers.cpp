#include <iostream>

using namespace std;

// I/P
// n = 78987
// O/P
// yes

// I/P
// n = 8668
// O/P
// no

// I/P
// n = 8
// O/P
// yes

// I/P
// n = 21
// O/P
// no

// I/P
// n = 367
// O/P
// no

bool pallindrome_number(int no)
{
    int sum=0,last_digit=0,no_copy=no;
    while(no_copy > 0)
    {
        last_digit=no_copy%10;
        sum=(sum*10) + last_digit;
        no_copy=no_copy/10;
    }
    if(sum == no)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

int main()
{
    bool is_pallindrome=pallindrome_number(12321);
    // Time Complexity -> O(d)
    // "d" is the number of digit

    if(is_pallindrome)
    {
        cout<<endl<<"it is pallindrome"<<endl;
    }
    else
    {
        cout<<endl<<"it is not pallindrome"<<endl;
    }    
    
    return 0;
}