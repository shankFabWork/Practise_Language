#include <iostream>

using namespace std;

int main()
{
    int arr1[3][3]={1,2,3,4,5,6,7,8,9};
    int arr2[3][3]={1,2,3,4,5,6,7,8,9};
    int arr3[3][3];
    int k1=0,k2=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr3[i][j]=arr1[i][j]*arr2[i][j];
        }
    }

    for(auto& x:arr3)
    {
        for(auto& y:x)
            {
                cout<<y<<"\t";
            }
        cout<<endl;
    }

    return 0;
}