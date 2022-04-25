#include <iostream>
#include <math.h>

using namespace std;

//loops
//loops are used to repeat a particular task at a given base condition

//types of loops in c++
//while 
//do while
//for
//for each

//in for loops we have
//for(initialization,condition,updation)


//infinite loop
int main()
{

    // for(int i=0;i<6;)
    // {
    //     cout<<"hello";
    // }

    //or

    // int i=0;
    // for(;;)
    // {
    //     cout<<i;
    //     i=i+1;
    //     if(i>10)
    //     {
    //         break;
    //     }
    // }

    int arr1[200];
    int arr2[200];

    int m,n;
    cin>>m>>n;

    int k1=0;
    for(int i=1;i<m;i++)
    {
        if(m%i == 0)
        {
            arr1[k1++]=i;
        }
    }

    
    int k2=0;
    for(int i=1;i<n;i++)
    {
        if(n%i == 0)
        {
            arr2[k2++]=i;
        }
    }

    for(int i=0;i<k1;i++)
    {
        cout<<arr1[i]<<"\t";
    }
    
    cout<<endl;
    for(int i=0;i<k2;i++)
    {
        cout<<arr2[i]<<"\t";
    }

    int k3=0,arr3[200];
    for(int i=0;i<k1;i++)
    {
        for(int j=0;j<k2;j++)
        {
            if( arr1[i] == arr2[j])
            {
                arr3[k3++]=arr1[i];
            }
        }    
    }

    cout<<endl;
    for(int i=0;i<k3;i++)
    {
        cout<<arr3[i]<<"\t";
    }
    cout<<endl;
    cout<<arr3[k3-1];

    return 0;
}