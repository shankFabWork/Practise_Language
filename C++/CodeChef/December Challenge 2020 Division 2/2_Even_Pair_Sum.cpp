#include <iostream>

using namespace std;

int recur(int a[], int b[], int n, int m) 
{ 
    int odd1 = 0, even1 = 0; 
    int odd2 = 0, even2 = 0; 
  
    for (int i = 0; i < n; i++) { 
        if (a[i] % 2 == 1) 
            odd1++; 
        else
            even1++; 
    }   
    for (int i = 0; i < m; i++) { 
        if (b[i] % 2 == 1) 
            odd2++; 
        else
            even2++; 
    } 
  
    int pairs = min(odd1, odd2) + min(even1, even2); 
  
    return pairs; 
} 

int main()
{
    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        int a,b;
        cin>>a>>b;
        int arr1[a],arr2[b];
        for(int i=1;i<=a;i++)
        {
            arr1[i] = i;
        }
        for(int i=1;i<=b;i++)
        {
            arr2[i] = i;
        }
        cout<<"--"<<recur(arr1,arr2,a,b)<<"--";
    }



    return 0;
}

        // int data = 0;

        // for(int k=0;k<n;k++)
        // {
        //     for(int i=1;i<=arr[k].first;i++)
        //     {
        //         for(int j=1;j<=arr[k].second;j++)
        //         {
        //             if( (i+j) % 2 == 0)
        //             {
        //                 data++;
        //             }
        //         }
        //     }
        // recur(a,b,val);
        // cout<<data<<endl;
        // data = 0;
        // }
