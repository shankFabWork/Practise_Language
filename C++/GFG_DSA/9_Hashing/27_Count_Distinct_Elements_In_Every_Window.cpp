// I/P->
// int arr[] = {10,20,20,10,30,40,10};
// int k = 4;
// O/P->
// 2 3 4 3

// I/P->
// int arr[] = {10,10,10,10};
// int k = 3;
// O/P->
// 1 1

// I/P->
// int arr[] = {10,20,30,40};
// int k = 3;
// O/P->
// 3 3

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

void Count_Distinct_Elements_In_Every_Window_one(int arr[],int n,int k)
{
    for(int s=0;s<n-k+1;s++)
    {
        int res = 0;
        for(int i=s;i<s+k;i++)
        {
            bool flag = false;
            for(int j=s;j<i;j++)
            {
                if(arr[i] == arr[j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                res++;
            }
        }
        cout<<res<<" ";
    }

}

void Count_Distinct_Elements_In_Every_Window_two(int arr[],int n,int k)
{
    // for(int i=0;i<n-k+1;i++)
    // {
    //     unordered_set <int> us(arr+i,arr+i+4);
    //     cout<<us.size()<<" ";
    //     us.clear();
    // }

    unordered_map <int,int> m;
    for(int i=0;i<k;i++)
    {
        m[arr[i]] += 1;
    }
    cout<<m.size()<<" ";
    for(int i=k;i<n;i++)
    {
        m[arr[i-k]] -= 1;
        if(m[arr[i-k]] == 0)
        {
            m.erase(arr[i-k]);
        }
        m[arr[i]] += 1;
        cout<<m.size()<<" ";
    }
}

int main()
{
    int arr[] = {10,20,20,10,30,40,10};
    int n=sizeof(arr)/sizeof(int);
    int k = 4;

    // first part is same as "16_Count_Distinct_Elements.cpp"
    Count_Distinct_Elements_In_Every_Window_one(arr,n,k);
    //Time Complexity -> O((n-k)*k*k)
    //Space Complexity -> O(1)

    cout<<endl;
    Count_Distinct_Elements_In_Every_Window_two(arr,n,k);
    //Time Complexity -> O((n)
    //Space Complexity -> O((n-k)*k)

    return 0;
}


