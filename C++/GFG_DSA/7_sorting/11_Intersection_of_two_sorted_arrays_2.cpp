#include <iostream>

using namespace std;

void intersection_array_first(int arr1[],int arr2[],int n1,int n2)
{
    int i=0,j=0,k=0;
    for(i=0;i<n1;i++)
    {
        if( i>0 && arr1[i-1] == arr1[i])
        {
            continue;
        }
        for(j=0;j<n2;j++)
        {
            if(arr1[i] == arr2[j])
            {
                cout<<arr1[i]<<"\t";
                break;
            }
        }   
    }
}

void intersection_array_second(int arr1[],int arr2[],int n1,int n2)
{
    int i=0,j=0,k=0;
    
    while(i<n1 && j<n2)
    {
        if(i>0 && arr1[i] == arr1[i+1])
        {
            i++;
            continue;
        }

        if(j>0 && arr2[j] == arr2[j+1])
        {
            j++;
            continue;
        }
        
        if(arr1[i] > arr2[j])
        {
            cout<<arr1[i]<<" ";
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

    while(i!=0 && i < n1)
    {
        if(arr1[i] == arr1[i+1])
        {
            i++;
            continue;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
        }
    }

    while(j!=0 && j < n2)
    {
        if(arr2[j] == arr2[j+1])
        {
            j++;
            continue;
        }
        else
        {
            cout<<arr2[j]<<" ";
            j++;
        }
    }

}

int main()
{
    int arr1[]={3,5,10,10,10,15,15,20};
    int arr2[]={5,10,10,15,30};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);

    //it will take 
    // time complexity -> O(n1*n2)
    // auxilary space -> O(1)
    // intersection_array_first(arr1,arr2,n1,n2);

    //it will take 
    // time complexity -> O(n1+n2)
    // auxilary space -> O(1)
    // either u will increment i or increment j
    // so the time complexity is O(n1+n2) or O(m+n)
    intersection_array_second(arr1,arr2,n1,n2);

    return 0;
}