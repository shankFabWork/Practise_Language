
// I/P->
// int a[] = {15,20,5,15};
// int b[] = {15,15,15,20,10};
// O/P->
// 4

// I/P->
// int a[] = {10,12,15};
// int b[] = {18,12};
// O/P->
// 4

// I/P->
// int a[] = {3,3,3};
// int b[] = {3,3};
// O/P->
// 1

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void Union_of_two_unsorted_arrays_one(int a[],int b[],int n1,int n2)
{
    unordered_set <int> um;
    for(int i=0;i<n1;i++)
    {
        um.insert(a[i]);
    }
    for(int i=0;i<n2;i++)
    {
        um.insert(b[i]);
    }
    for(auto val:um)
    {
        cout<<val<<" ";
    }
}


int main()
{
    int a[] = {15,20,5,15};
    int b[] = {15,15,15,20,10};

    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);

    Union_of_two_unsorted_arrays_one(a,b,n1,n2);
    //Time Complexity -> O(m+n)
    //Space Complexity -> O(m+n)
    cout<<endl;

    return 0;
}


