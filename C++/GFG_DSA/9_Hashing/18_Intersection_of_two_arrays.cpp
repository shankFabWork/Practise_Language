
// I/P->
// int a[] = {10,15,20,5,30};
// int b[] = {30,5,30,80};
// O/P->
// 2

// I/P->
// int a[] = {10,20};
// int b[] = {20,30};
// O/P->
// 1

// I/P->
// int a[] = {10,10,10};
// int b[] = {10,10,10};
// O/P->
// 1

#include <iostream>
#include <unordered_set>

using namespace std;

void Intersection_of_two_arrays_one(int a[],int b[],int n1,int n2)
{
    int count;  
    int maxSize = max(n1,n2);
    for(int i=0;i<maxSize;i++)
    {
        bool flag = false;
        count = 0;
        for(int j=0;j<i;j++)
        {
            if(a[i] == b[j])
            {
                flag == true;
                break;
            }
        }
        if(flag == false)
        {
            count++;
        }
    }
    cout<<count;
}

void Intersection_of_two_arrays_two(int a[],int b[],int n1,int n2)
{
    unordered_set <int> us(a,a+n1);
    int res = 0;
    for(int i=0;i<n2;i++)
    {
        if(us.find(b[i]) != us.end())
        {
            res++;
            cout<<b[i]<<" ";
            us.erase(b[i]);
        }
    }
    cout<<endl;
    cout<<res;
}

int main()
{
    // int a[] = {10,15,20,5,30};
    // int b[] = {30,5,30,80};

    // int a[] = {10,20};
    // int b[] = {20,30};

    int a[] = {10,10,10};
    int b[] = {10,10,10};

    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);

    for(int i=0;i<n1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n2;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;  
    cout<<endl;  

    Intersection_of_two_arrays_one(a,b,n1,n2);
    //Time Complexity -> O(m*(m+n))
    //Space Complexity -> O(1)
    cout<<endl;
    Intersection_of_two_arrays_two(a,b,n1,n2);
    //Time Complexity -> O(n^2)
    //Space Complexity -> O(1)
    cout<<endl;
    
    return 0;
}


