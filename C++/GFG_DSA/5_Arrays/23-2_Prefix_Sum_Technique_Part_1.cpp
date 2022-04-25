#include <iostream>

using namespace std;

// given an array find it has a equilibrium point

// I/P
// 3 4 8 -9 20 6
//           ^
// 3+4+8+(-9) == 6
// 20 seperates them
// 20 is a equilibrium point
// O/P
// 20

// I/P
// 4 -2 2
// ^
// -2+2 == 0
// 4 seperates them
// as on the left nothing is there so 0 == 0
// 4 is a equilibrium point
// O/P
// yes

// in order to find equilibrium point should be greater than 2
// for example : 1 2

void Prefix_Sum_Technique_one(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int leftSum = 0;
        int rightSum = 0;
        for(int j=0;j<i;j++)
        {
            leftSum += arr[j];
        }
        for(int k=i+1;k<n;k++)
        {
            rightSum += arr[k];
        }

        if(leftSum == rightSum)
        {
            cout<<"index is "<<i<<endl;
            cout<<"equilibrium point is "<<arr[i]<<endl;
        }
        
    }
}
// 3 4 8 -9 20 6
// 1
// lsum=3 and rsum=25
// compare lsum nad sum
// 2
// lsum=7 and rsum=17
// compare lsum nad sum
// 3
// lsum=15 and rsum=26
// compare lsum nad sum
// 4
// lsum=6 and rsum=6
// compare lsum nad sum

// index is 4
// equilibrium point is20



void Prefix_Sum_Technique_two(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int lsum = 0;
    for(int i=0;i<n-1;i++)
    {
        sum -= arr[i];
        if( lsum == sum )
        {
            cout<<"index is "<<i<<endl;
            cout<<"equilibrium point is "<<arr[i]<<endl;
        }
        lsum += arr[i];
    }
}

// 3 4 8 -9 20 6
// 0
// lsum =0 and sum=32-3=29
// compare lsum and sum//1
// 1
// lsum =0+3=3 and sum=29-4=25
// compare lsum and sum
// 2
// lsum =3+4=7 and sum=25-8=17
// compare lsum and sum
// 3
// lsum =7+8=15 and sum=17-(-9)=26
// compare lsum and sum
// 4
// lsum =15-9=6 and sum=26-20=6
// compare lsum and sum

// index is 4
// equilibrium point is20


int main()
{
    int arr[] = {3,4,8,-9,20,6};
    int n=sizeof(arr)/sizeof(int);

    // Prefix_Sum_Technique_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    Prefix_Sum_Technique_two(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    return 0;
}