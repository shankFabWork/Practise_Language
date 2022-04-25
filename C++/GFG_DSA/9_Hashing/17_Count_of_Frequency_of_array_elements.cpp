
// I/P->
// int arr[] = {10,12,10,15,10,20,12,12};
// O/P->
// 10 3
// 12 3
// 15 1
// 20 1


// I/P->
// int arr[] = {10,10,10,10};
// O/P->
// 10 4

// I/P->
// int arr[] = {10,20};
// O/P->
// 10 1
// 20 1

#include <iostream>
#include <unordered_map>

using namespace std;

void Count_of_Frequency_of_array_elements_one(int arr[],int n)
{

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
            int count = 0;
            for(int k=i;k<n;k++)
            {
                if(arr[i] == arr[k])
                {
                    count++;
                }
            }
            cout<<arr[i]<<" "<<count<<endl;
        }
    }
}

void Count_of_Frequency_of_array_elements_two(int arr[],int n)
{
    unordered_map <int,int> hm;
    for(int i=0;i<n;i++)
    {
        hm[arr[i]]++;       
    }
    for(auto val:hm)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
}

int main()
{
    int arr[]={10,20,20,30,10};
    int n=sizeof(arr)/sizeof(int);

    Count_of_Frequency_of_array_elements_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)
    cout<<endl;
    Count_of_Frequency_of_array_elements_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) 

    return 0;
}


