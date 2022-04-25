// range 0 <= arr[i] dep[i] < = 2359

// I/P
// arr[] = {900,940}
// dep[] = {1000,1030}
// O/P
// 2

// I/P
// arr[] = {800,700,600,500}
// dep[] = {840,820,830,530}
// O/P
// 3

// I/P
// arr[] = {900,940,950,1100,1500,1800}
// dep[] = {910,1200,1120,1130,1900,2000}
// O/P
// 3

// 1030 means 10:30
// 940 means 9:40

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int Meeting_the_maximum_guests(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    // Time Complexity -> O(n.log(n)) 
    sort(dep,dep+n);
    // Time Complexity -> O(n.log(n)) 

    int curr = 0 ;
    int i = 0;
    int j = 0;
    int res = 0;

    // or
    // int curr = 1;
    // int i = 1;
    // int j = 0;
    // int res = 1;
        
    while(i<n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            i++;
            curr++;
        }
        else
        {
            j++;
            curr--;
        }
        res = max_val(res,curr);
    }
    return res;
}

int main()
{
    // int arr[]={900,940};
    // int dep[]={1000,1030};

    // int arr[] = {800,700,600,500};
    // int dep[] = {840,820,830,530};

    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};


    int n=sizeof(arr)/sizeof(arr[0]);
    int res = Meeting_the_maximum_guests(arr,dep,n);
    // Time Complexity -> O(n.log(n)) 
    // Space Complexity -> O(1)

    cout<<res;

    return 0;
}

// dry run
// arr[] = {900,940,950,1100,1500,1800}
// dep[] = {910,1200,1120,1130,1900,2000}

// sort both array
// 900 940 950 1100 1500 1800
// 910 1120 1130 1200 1900 2000

// DRY RUN OF THE ABOVE SORTED ARRAY
// 900 A 1
// 910 D 0
// 940 A 1
// 950 A 2
// 1100 A 3
// 1120 D 2
// 1130 D 1
// 1200 D 0
// 1500 A 1
// 1800 A 2
// 1900 D 1
// 2000 D 0

// max = 3 
// 3 is the answer