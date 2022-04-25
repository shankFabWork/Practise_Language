#include <iostream>
#include <algorithm>

using namespace std;

void union_array_first(int arr1[],int arr2[],int n1,int n2)
{
    //quick sort takes n.log(n)
    //in this case it is (m+n).log(m+n)

    int i=0,j=0,k=0,arr3[n1+n2];
    for(i=0;i<n1;i++)
    {
        arr3[i]=arr1[i];
    }
    for(j=0;j<n2;j++)
    {
        arr3[n1+j]=arr2[j];
    }
    sort(arr3,arr3+n1+n2);
    for(k=0;k<(n1+n2);k++)
    {
        if(i!=0 && arr3[k] == arr3[k+1])
        {
            continue;
        }
        else
        {
            cout<<arr3[k]<<" ";
        }
    }
}

void union_array_second(int arr1[],int arr2[],int n1,int n2)
{
    int i=0,j=0,k=0;
    
    while(i<n1 && j<n2)
    {
        if(i>0 && arr1[i] == arr1[i+1])
        {
            i++;
            continue;
        }
        if(j>0 && arr1[j] == arr1[j+1])
        {
            j++;
            continue;
        }
        if(arr1[i] > arr2[j])
        {
            cout<<arr1[j]<<" ";
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }

    while(i<n1)
    {
            cout<<arr1[i++]<<" ";
    }

    
    while(j<n2)
    {
            cout<<arr2[j++]<<" ";
    }


}

int main()
{
    int arr1[]={3,5,10,10,10,15,15,20};
    int arr2[]={5,10,10,15,30};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);

    //it will take 
    // time complexity -> O(m+n).log(m+n)
    // auxilary space -> O(1)
    //quick sort takes n.log(n)
    //in this case it is (m+n).log(m+n)
    // union_array_first(arr1,arr2,n1,n2);

    //it will take 
    // time complexity -> O(n1+n2)
    // auxilary space -> O(1)
    union_array_second(arr1,arr2,n1,n2);

    return 0;
}