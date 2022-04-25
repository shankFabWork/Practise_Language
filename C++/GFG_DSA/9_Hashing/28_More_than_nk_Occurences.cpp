#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void More_than_nk_Occurences_one(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int i = 1;
    while(i < n)
    {
        int res = 1;
        while(i<n && arr[i] == arr[i-1])
        {
            res++;
            i++;
        }
        if(res > (n/k) )
        {
            cout<<arr[i-1]<<" ";
        }
        i++;
    }
}

void More_than_nk_Occurences_two(int arr[],int n,int k)
{
    // for(int i=0;i<n;i++)
    // {
    //     bool flag = false;
    //     for(int j=0;j<i;j++)
    //     {
    //         if(arr[i] == arr[j])
    //         {
    //             flag = true;
    //         }
    //     }
    //     if(flag == false)
    //     {
    //         int res = 0;
    //         for(int k=i;k<n;k++)
    //         {   
    //             if(arr[k] == arr[i])
    //             {
    //                 res++;
    //             }
    //         }
    //         if(res > n/k)
    //         {
    //             cout<<arr[i]<<" ";
    //         }
    //     }
    // }

    unordered_map <int,int> um;
    for(int i=0;i<n;i++)
    {
        um[arr[i]]++;
    }
    for(auto val:um)
    {
        if(val.second > (n/k))
        {
            cout<<val.first<<" ";
        }
    }

    // it is not ideal for large array
    // in large array making hashmap is not 
    // a good idea

}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30};
    // 10 10 20 20 20 30 30 30
    int n = sizeof(arr)/sizeof(int);
    int k = 4;

    More_than_nk_Occurences_one(arr,n,k);
    //Time Complexity -> O(n*log(n)) + O(n) => O(n*log(n))
    //Space Complexity -> O(1)

    cout<<endl;
    More_than_nk_Occurences_two(arr,n,k);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
}

// here our hashmap size is atmost (k-1)

// suppose u have 1 lakh elements so 
// hashmap will only store atmost (k-1)