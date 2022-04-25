
// I/P->
// arr[] = {15,12,13,12,13,13,18};
// O/P->
// 4

// I/P->
// arr[] = {10,10,10};
// O/P->
// 1

// I/P->
// arr[] = {10,11,12};
// O/P->
// 3    

#include <iostream>
#include <unordered_set>

using namespace std;

int Count_Distinct_Elements_one(int arr[],int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j=0;j<i;j++)
        {
            if(arr[i] == arr[j])
            {
                flag = true;
            }
        }
        if(flag == false)
        {
            res++;
            cout<<arr[i]<<" ";
        }
    }
    return res;
}

int Count_Distinct_Elements_two(int arr[],int n)
{
    unordered_set <int> us;

    for(int i=0;i<n;i++)
    {
        us.insert(arr[i]);
    }
    return us.size();
}

int Count_Distinct_Elements_improved(int arr[],int n)
{
    unordered_set <int> us(arr,arr+n);
    return us.size();
}

int main()
{
    int arr[] = {15,12,13,12,13,13,18};
    int n=sizeof(arr)/sizeof(arr[0]);

    // it can also find distinct elements
    // and count as well
    cout<<Count_Distinct_Elements_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)    
    cout<<endl;
    cout<<Count_Distinct_Elements_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
    cout<<endl;
    cout<<Count_Distinct_Elements_improved(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)

    return 0;
}


