#include <iostream>

using namespace std;

// Tower of Hanoi is a mathematical puzzle
//  where we have three rods and n disks. 
//  The objective of the puzzle is to 
//  move the entire stack to another rod, 
//  obeying the following simple rules:

// 1) Only one disk can be moved at a time.
// 2) Each move consists of taking the upper disk 
// from one of the stacks and placing it on top of another 
// stack i.e. a disk can only be moved if it is the uppermost disk 
// on a stack.
// 3) No disk may be placed on top of a smaller disk.

void toh(int n,char A,char B,char C)
{
    if(n == 1)
    {
        cout<<" Move disk no "<<n<<" from "<<A<<" to "<<C<<endl;
        return;
    }
    toh(n-1,A,C,B);
    cout<<" Move disk no "<<n<<" from "<<A<<" to "<<C<<endl;
    toh(n-1,B,A,C);
}

int main()
{
    char A='A';
    char B='B';
    char C='C';
    int n=3;

    toh(n,A,B,C);
    // Time Complexity -> O(2^n - 1)


    return 0;
}