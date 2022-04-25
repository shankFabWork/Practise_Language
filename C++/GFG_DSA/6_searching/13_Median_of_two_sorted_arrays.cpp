// I/P->
// 10 20 30 40 50
// 5 15 25 35 45
// O/P->
// 27.5
// as (20+25)/2
// 5 10 15 20 25 30 35 40 45 50

// I/P->
// 1 2 3 4 5 6
// 10 20 30 40 50
// O/P->
// 6
// as (6)
// 1 2 3 4 5 6 10 20 30 40 50

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

// array used is alredy sorted

// naive approach
void Median_of_two_sorted_arrays_one(int arr1[],int arr2[],int n1,int n2)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int arr3[n2+n1];
    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while(i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while(j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    for(int i=0;i<n1+n2;i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;

    int mid;
    if( (n1+n2)%2 == 0)
    {
        mid = ( arr3[((n1+n2)/2)-1] + arr3[ ((n1+n2)/2)] ) / 2;
    }
    else
    {
        mid = arr3[(n1+n2)/2];
    }
    cout<<mid<<endl;

}

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

void Median_of_two_sorted_arrays_two(int arr1[],int arr2[],int n1,int n2)
{
    int begin = 0;
    int end = n1;

    while(begin < end)
    {
        int i1 = (begin + end)/2;
        int i2 = (n1+n2+1)/2 - i1;

        int min1 = (i1 == n1)?INT_MIN:arr1[i1];
        int max1 = (i1 == 0)?INT_MAX:arr1[i1-1];

        int min2 = (i2 == n2)?INT_MIN:arr2[i2];
        int max2 = (i2 == 0)?INT_MAX:arr2[i2-1];

        if( max1 <= min2 && max2 <= min1)
        {
            if((n1+n2) % 2 == 0)
            {
                cout<<(max_val(max1,max2) + min_val(min1,min2))/2;
                break;
            }
            else
            {
                cout<<max_val(max1,max2);
                break;
            }
        }
        else if(max1 > min2 )
        {
            end = i1 - 1;
        }
        else
        {
            begin = i1 + 1;
        }

    }

}

int main()
{
    int arr1[] = {10,20,30,40,50};
    int arr2[] = {5,15,25,35,45};    
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);
    // 5 10 15 20 25 30 35 40 45 50
    // 25+30
    // 55


    Median_of_two_sorted_arrays_one(arr1,arr2,n1,n2);
    //Time Complexity -> O( (n1+n2).log(n1+n2) ) 
    //Space Complexity -> O(1)

    Median_of_two_sorted_arrays_two(arr1,arr2,n1,n2);
    //Time Complexity -> O( log(n1) )
    //Space Complexity -> O(1)

    return 0;
}

// I/P->
// 10 20 30 40 50
// 5 15 25 35 45