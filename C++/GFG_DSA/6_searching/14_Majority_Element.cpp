// Majority element is an element that appears more than n/2 times 
// in an array of size n. In this video, 
// two methods to find majority element in an array are discussed.

// I/P->
// 8 3 4 8 8
// O/P->
// 0 or 3 or 4 (any index of 8)

// I/P->
// 3 7 4 7 7 5
// O/P->
// -1
// no majority

// I/P->
// 20 30 40 50 50 50 50
// O/P->
// 3 or 4 or 5 or 6 (any index of 50)

#include <iostream>

using namespace std;

// naive solution
void Majority_Element_one(int arr[],int n)
{
    int data = 0; 
    for(int i=0;i<n;i++)
    {
        int count = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                count = count + 1;
            }
        }
        if(count > n/2)
        {
            data = 1;
            cout<<i<<endl;
        }
    }

    if(data == 0)
    {
        cout<<"No Majority Element Found "<<endl;
    }
}

// efficient solution
void Majority_Element_two(int arr[],int n)
{
    int res = 0;
    int count = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[res] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0 )
        {
            res = i;
            count = 1;
        }
    }

    int occur = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[res] == arr[i])
        {
            occur++;
        }
    }
    if(occur > n/2)
    {
        cout<<res<<endl;
    }
    else
    {
        cout<<"No Majority Element Found "<<endl;
    }

}


    

int main()
{
    int arr[]={8,7,6,8,6,6,6,6};
    int n=sizeof(arr)/sizeof(int);

    // Majority_Element_one(arr,n);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)

    Majority_Element_two(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)
    
    return 0;
}



