#include <iostream>

using namespace std;

// I/P->
// 1 3 2 4 6 5 7 3
// O/P->
// 3

// 1 3 2 4 6 5 7 3
// 0 1 2 3 4 5 6 7

// I phase
// slow = 1 (arr[0]), fast = 1 (arr[0])
// slow = 3, fast = 4 
// slow = 4, fast = 7 
// slow = 6, fast = 4 
// slow = 7, fast = 7 

// II phase
// slow = 1, fast = 7
// slow = 3, fast = 3
// answer is 3

// => theory : 
// if fast is moving at the double speed than slow
// then it calims that it is moving with the double speed

// this is two step algorithm
// Note : in this case minimum element is 1
int Repeating_Elements_one(int arr[],int n)
{
    int slow =  arr[0];
    int fast =  arr[0];

    do
    {
        slow =  arr[slow];
        fast =  arr[arr[fast]];
    }while(slow != fast);

    slow = arr[0];
    do
    {
        slow =  arr[slow];
        fast =  arr[fast];
    }while(slow != fast);

    return slow;
}


// 0 2 1 3 5 4 6 2
// 0 1 2 3 4 5 6 7

// I phase
// slow = 1 (arr[0]+1), fast = 1 (arr[0]+1)
// slow = 3, fast = 4
// slow = 4, fast = 7 
// slow = 6, fast = 4 
// slow = 7, fast = 7 

// II phase
// slow = 1, fast = 7
// slow = 3, fast = 3
// answer is 3

// this is two step algorithm
// Note : in this case minimum element is 0
// replace ']' with ']+1'
int Repeating_Elements_two(int arr[],int n)
{
    int slow =  arr[0]+1;
    int fast =  arr[0]+1;

    do
    {
        slow =  arr[slow]+1;
        fast =  arr[arr[fast]+1]+1;
    }while(slow != fast);

    slow = arr[0];
    do
    {
        slow =  arr[slow]+1;
        fast =  arr[fast]+1;
    }while(slow != fast);

    return slow;
}

int main()
{
    int arr[]={1,3,2,4,6,5,7,3};
    int n=sizeof(arr)/sizeof(int);

    // Note : in this case minimum element is 0
    cout<<Repeating_Elements_one(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    cout<<endl;

    // Note : in this case minimum element is 1
    cout<<Repeating_Elements_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)
    
    return 0;
}



