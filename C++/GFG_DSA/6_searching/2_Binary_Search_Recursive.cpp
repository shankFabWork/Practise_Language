#include <iostream>

using namespace std;

// I/P->

// O/P->

int binary_search_one(int arr[],int elem,int left,int right)
{
    int mid = (left + right)/2;
    if(left > right)
    {
        return -1;
    }
    if(arr[mid] == elem)
    {
        return mid;
    }
    else if(arr[mid] > elem)
    {
        binary_search_one(arr,elem,left,mid - 1);
    }
    else
    {
        binary_search_one(arr,elem,mid + 1,right);
    }
}
//ignore warning
int main()
{
    //array must be sorted
    int arr[]={10,20,40,50,60};
    int n=sizeof(arr)/sizeof(int);
    int elem = 50;

    cout<<binary_search_one(arr,elem,0,n-1);
    //Time Complexity -> O(log(n))
    //Space Complexity -> O(log(n))

    // in worst case 
    //Time Complexity -> O(n)
    //Space Complexity -> O(log(n))


    
    return 0;
}



