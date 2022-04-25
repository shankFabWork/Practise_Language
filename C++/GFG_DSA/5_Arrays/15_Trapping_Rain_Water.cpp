// how much water u can collect of given height

#include <iostream>
#include <limits.h>

using namespace std;

// I/P
// 2 0 2
// O/P
// 2

// I/P
// 3 0 1 2 5
// O/P
// 6 

// I/P
// 1 2 3
// O/P
// 0

// I/P
// 3 2 1
// O/P
// 0

// I/P
// 3 0 1 2 5
// O/P
// 6

int max_val(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int min_val(int a,int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

int trappingRainWater_one(int arr[],int n)
{
    int res = 0;
    for(int i=1;i<n-1;i++)
    {
        int lMax = arr[i];
        for(int j=0;j<i;j++)    
        {
            lMax = max(lMax,arr[j]);
        }
        int rMax = arr[i];
        for(int k=i+1;k<n;k++)
        {
            rMax = max(rMax,arr[k]);
        }
        cout<<lMax<<" "<<rMax<<" "<<(min(lMax,rMax)-arr[i])<<endl;

        res = res+(min(lMax,rMax)-arr[i]);
    }
    cout<<endl;
    return res;
}

int trappingRainWater_two(int arr[],int n)
{
    int lMax[n],rMax[n];

    lMax[0] = arr[0];
    for(int i=1;i<n;i++)
    {   
        lMax[i] = max(arr[i],lMax[i-1]);
    }
    
    rMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {   
        rMax[i] = max(arr[i],rMax[i+1]);
    }

    int res = 0;
    for(int i=0;i<n;i++)
    {
        res = res + (min(rMax[i],lMax[i]) - arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {5,0,6,2,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<trappingRainWater_one(arr,n);
    // TC - O(n^2)
    // SC - O(n)
    cout<<endl;
    cout<<trappingRainWater_two(arr,n);
    // TC - O(n)
    // SC - O(n)

    return 0;
}

// 5,0,6,2,3
// 5,5,6,6,6
// 6,6,6,3,3
// 5+0+1

//   |
// | |
// | |
// | | |
// | |||
// | |||
//------