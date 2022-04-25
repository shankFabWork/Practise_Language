#include <iostream>

using namespace std;

int main()
{

    int arr[]={50,20,40,60,10,30};
    cout<<sizeof(arr)/sizeof(int);
    cout<<endl;    
    cout<<"Before Sorting";
    cout<<endl;    
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        cout<<arr[i]<<"\t";
    }


    for(int i=1;i<sizeof(arr)/sizeof(int);i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    cout<<endl;    
    cout<<"After Sorting";
    cout<<endl;    
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        cout<<arr[i]<<"\t";
    }

    // time complexity 
    //     worst case -> n^2
    //     average case -> n

    


    return 0;
}