#include <iostream>

using namespace std;

void odd_appering_one(int arr[],int n)
{
    int t = 2;
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
            }
        }
        if(count % 2 != 0)
        {
            if(t != 0)
            {
                cout<<arr[i]<<" ";
                t--;
            }
        }
    }
}

void odd_appering_two(int arr[],int n)
{
    // I/P
    // arr[] = {3,4,3,4,5,4,4,6,7,7}
    // O/P
    // 5 6
    // XOR of all number will be 5^6 = 3
    // 3 => 011
    // last set bit , sn = 1
    // do & of sn with all number 
    // if it gives 1 -> put in grp 1
    // if it gives 0 -> put in grp 2
    // group 1 -> last bit is set 
    // {3,3,5,7,7}
    // group 2 -> 
    // {4,4,4,6}

    // do xor of all the element in group 1
    // and do its xor of group 1 , we got ->5
    // and do its xor of group 2 , we got ->6

    int XOR=0;
    for(int i=0;i<n;i++)
    {
        XOR = XOR^arr[i];
    }

    // used to find right most set bit
    // XOR is 3 (011)
    // 011 - 1 = 010
    // 11..1101
    // 11..1101 & 011
    // 0001

    // last set bit
    int sn=XOR&(~(XOR-1));

    int res1=0;
    int res2=0;
    for(int i=0;i<n;i++)
    {
        // apart from 8 find all elements XOR
        if( (sn & arr[i]) != 0)  
        {
            res1=res1 ^ arr[i];
        }
        else
        {
            res2=res2 ^ arr[i];
        }
    }
    cout<<res1<<" "<<res2<<" ";
}

int main()
{
    // works only if array has given 
    // two odd occuring element
    // otherwise it will not work
    int arr[]={3,4,3,4,8,4,4,32,7,7};
    // int arr[]={3,4,3,4,5,4,4,6,7,7};
    // int arr[]={3,4,3,4,8,4,4,32,7,7};
    int n=sizeof(arr)/sizeof(int);

    // odd_appering_one(arr,n);
    // Time Complexity -> O(n^2)
    // Space Complexity -> O(1)

    odd_appering_two(arr,n);
    // Time Complexity -> O(n)    
    // Space Complexity -> O(1)

    return 0;
}