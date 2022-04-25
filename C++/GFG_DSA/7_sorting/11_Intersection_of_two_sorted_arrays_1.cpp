#include <iostream>

using namespace std;

int main()
{
    // int arr1[]={10,60,20,40,70};
    // int arr2[]={20,60,20,20,10};
    int arr1[]={3,5,10,10,10,15,15,20};
    int arr2[]={5,10,10,15,30};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);
    int arr3[n1],i=0,j=0,k=0,c=0;

    for(i=0;i<n1;i++)
    {
        c=0;
        for(j=0;j<n2;j++)
        {
            if(arr1[i] == arr2[j])
            {
                arr3[i]=(++c);
            }
            else
            {
                arr3[i]=c;            
            }
        }
        
    }

    cout<<endl;

    i=0;
    j=0;
    k=0;

    cout<<endl;
    for(i=0;i<(n1);i++)
    {
        cout<<arr1[i]<<"\t";
    }
    cout<<endl;
    for(j=0;j<(n2);j++)
    {
        cout<<arr2[j]<<"\t";
   }

    cout<<endl;
    cout<<"solution 1 ::::";
    cout<<endl;
    for(i=0;i<(n1);i++)
    {
        if(arr3[i] != 0)
        {
            cout<<arr1[i]<<"\t";
        }
    }

    cout<<endl;
    cout<<"solution 2 ::::";
    cout<<endl;

    i=0,j=0;
    for(i=0;i<(n1);i++)
    {
        if(arr3[i] == arr3[i+1])
        {
            continue;
        }
        if(arr3[i] != 0)
        {
            cout<<arr1[i]<<"\t";
        }
    }

    return 0;
}