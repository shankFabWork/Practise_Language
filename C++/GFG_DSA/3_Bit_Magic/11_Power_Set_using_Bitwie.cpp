//  Power Set of a given Set
#include <iostream>
#include <math.h>

using namespace std;

void printPowerSet(string str)
{
    int len=str.length(); //3
    int n=pow(2,len);  //8

    // 000 -> "" 
    // 001 -> "c"
    // 010 -> "b"
    // 011 -> "bc"
    // 100 -> "a"
    // 101 -> "ac"
    // 110 -> "ab"
    // 111 -> "abc"
    // if the bit is set then we 
    // print the corroponding character

    // I/P
    // s = "abc"
    // O/P
    // "","a","b","c","ab","ac","bc","abc"

    // I/P
    // s = "ab"
    // O/P
    // "","a","b","ab"

    for(int counter=0;counter<n;counter++)
    {
        for(int j=0;j<len;j++)
        {
            // (n & (1 << (k -1 ))) != 0
            if( (counter & ( 1 << j )) != 0)
            {
                cout<<str[j];
            }
        }
        cout<<endl;
    }

}

int main()
{
    string str="abc";
    printPowerSet(str); 
    // O(2^n * n)

    return 0;
}