#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // method->1
    // Naive Method
    int arr1[]={10,20,34,56};
    int arr2[]={70,78,91,98};
    int i,j,k;
    
    // takes O( (m+n).log(m+n) )
    int m=sizeof(arr1)/sizeof(int);
    int n=sizeof(arr2)/sizeof(int);

    int arr3[m+n];
    for(i=0;i<m;i++)
    {
        arr3[i]=arr1[i];
    }
    for(j=0;j<n;j++)
    {
        arr3[j+m]=arr2[j];
    }

    sort(arr3,arr3+m+n);
    //sort function is by default quick sort
    // quick sort time complexity
    // average case -> O(n.log(n))
    // worst case -> O(n^2)
    //in this case is O( (m+n).log(m+n) )

    for(k=0;k<m+n;k++)
    {
        cout<<arr3[k]<<"\t";
    }

    // takes O( (m+n).log(m+n) )
    i=0;
    j=0;
    cout<<endl;
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            cout<<arr1[i++]<<"\t";
        }
        else
        {
            cout<<arr2[j++]<<"\t";
        }
    }

    while(i<m)
    {
        cout<<arr1[i++]<<"\t";
    }

    while(j<m)
    {
        cout<<arr2[j++]<<"\t";
    }
    return 0;
}