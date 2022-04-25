#include <iostream>

using namespace std;

int main()
{
    //will add automatically
    // int arr[3][3]={ {1,2,3},{4,5,6},{8} };
    // 1       2       3
    // 4       5       6
    // 8       0       0


    int arr[3][3]={ {1,2,3},{4,5,6},{8} };
    int n=3;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl;

    // int arr1[3][3]={ 1,2,3,4,5,6,7,8,9 };
    int arr1[3][3];
    for(auto & x:arr1 )
    {
        for(auto & y:x )
        {
            cin>>y;
        }
        cout<<endl;
    }


    for(auto & x:arr1 )
    {
        for(auto & y:x )
        {
            cout<<y<<"\t";
        }
        cout<<endl;
    }



    return 0;
}