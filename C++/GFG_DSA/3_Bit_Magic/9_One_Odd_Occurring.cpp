#include <iostream>
#include <algorithm>

using namespace std;

// Part-1

// I/P
// arr[] = {4,3,4,4,4,5,5}
// O/P
// 3
// EXPLAINATION -> 
// 4 -> 4 times
// 3 -> 1 times (odd)
// 5 -> 2 times

// I/P
// arr[] = {8,7,7,8,8}
// O/P
// 8
// EXPLAINATION -> 
// 8 -> 3 times (odd)
// 7 -> 2 times

// Part-2

// I/P
// arr[] = {1,4,3}
// O/P
// 2

// I/P
// arr[] = {1,5,3,2}
// O/P
// 4

void one_odd_occuring_1(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int counter = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] == arr[i])
            {
                counter++;
            }
        }
        if(counter % 2 != 0)
        {
            cout<<arr[i];
            break;
        }
    }
}

void one_odd_occuring_2(int arr[],int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res=res ^ arr[i];
    }
    cout<<res;
}

//works for only one
void find_missing_number_1(int arr[],int n)
{
    int res1=arr[0];
    for(int i=1;i<n;i++)
    {
        res1 = res1 ^ arr[i];
    }
    int res2=1;
    for(int i=2;i<=n+1;i++)
    {
        res2 = res2 ^ i;
    }
    cout<<(res1^res2);

}

//works for many
void find_missing_number_2(int arr[],int n)
{
    int arr_sum = 0;
    for(int i=0;i<n;i++)
    {
        arr_sum += arr[i];
    }
    // 1 4 3
    // sum = 8
    // n = 3
    // n = n+1 
    // (4*3)/2 = 6
    // 8-6 = 2
    int new_n = n+1;
    int sum = (new_n)*(new_n+1)/2;
    cout<<(sum-arr_sum);
}

int main()
{
    /// part-1
    int arr1[]={4,3,4,4,4,5,5};
    // int arr1[]={8,7,7,8,8};
    int n1=sizeof(arr1)/sizeof(int);

    one_odd_occuring_1(arr1,n1); 
    cout<<endl;
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    one_odd_occuring_2(arr1,n1);
    cout<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)

    //---------------------------------
    
    /// part-2
    int arr2[]={1,4,3};
    // int arr2[] = {1, 2, 3, 5, 6};
    int n2=sizeof(arr2)/sizeof(int);
    find_missing_number_1(arr2,n2);
    cout<<endl;
    // Time Complexity: O(n). 
    // Space Complexity: O(1). 

    // int n2=sizeof(arr2)/sizeof(int);
    find_missing_number_2(arr2,n2);
    cout<<endl;
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)



    return 0;
}
