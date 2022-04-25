// Given a binary array, we need to find the minimum of 
// number of group flips to make all array elements same.  
// In a group flip, we can flip any set of consecutive 1s or 0s.

// I/P
// 1 1 0 0 0 1
//( contains 2 group of "1" )
//( contains 1 group of "0" )
// O/P
// from 2 to 4

// I/P
// 1 0 0 0 1 0 0 1 1 1 1
//( contains 3 group of "1" )
//( contains 2 group of "0" )
// O/P
// from 1 to 3
// from 5 to 6

// I/P
// 1 1 1 
//( contains 1 group of "1" )
//( contains 0 group of "0" )
// No need to flip anything 
//answer is nothing
// O/P

// I/P
// 0 1 
//( contains 1 group of "1" )
//( contains 1 group of "0" )
// O/P
// from 0 to 0
// from 1 to 1

// Two conditions are involved in it:::

// 1)->    Group count  differ by One

// 1 1 0 0 0 1 1 1 0 0 1
//( contains 3 group of "1" )
//( contains 2 group of "0" )

// 0 0 1 1 0 0 0 1 1 0 0
//( contains 2 group of "1" )
//( contains 3 group of "0" )

// 2)->    Group count  differ by Same

// 0 0 1 1 1 0 0 0 0 1 1
//( contains 2 group of "1" )
//( contains 2 group of "0" )

// 1 1 0 0 0 0 1 1 1 1 0
//( contains 2 group of "1" )
//( contains 2 group of "0" )

// -------------------------------------
// 0 0 1 1 0 0 1 1 0   ->binary array
// 0 1 2 3 4 5 6 7 8   ->index
//     ^   ^   ^   ^
//     2  4-1  6  8-1
//     2   3   6   7

// from 2 to 3
// from 6 to 7
//suppose if 1 is added in the end of the array
// 0 0 1 1 0 0 1 1 0 1  ->binary array
//     ^   ^   ^   ^ ^
//     2  4-1  6  8-1 9
//     2   3   6   7
// from 2 to 3
// from 6 to 7
// if(arr[n-1] != arr[0])
//      cout<<(n-1)<<endl;
// from 9 to 9
    
#include <iostream>

using namespace std;

void Minimum_Consecutive_Flips(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i] != arr[i-1])
        {
            // arr[i] shoulf not be equal to first element
            //which shows that it is the starting of the first loop

            if(arr[i] != arr[0])
            {
                cout<<"from "<<i<<" to ";
            }
            else
            {
                cout<<(i-1)<<endl;
            }
        }
    }

    // if first element is not equal to last element
    // example : 0101
    if(arr[0] != arr[n-1])
    {
        cout<<(n-1)<<endl;
    }
}

int main()
{
    int arr[] = {0,0,1,1,0,0,1,1,0,1};
    int n = sizeof(arr)/sizeof(int);
    Minimum_Consecutive_Flips(arr,n);
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    // Fact -
    // It is always recommended to 
    // flip the second group

    // we are always going to flip second group
    
    // starting group is same as ending group
    // 1100110011
    // 3-2 = 1 --> difference is always 1

    // starting group is not same as ending group
    // 11001100
    // 2-2 = 0 --> difference is always 0

    // best example is 11001 to work 
    return 0;
}
