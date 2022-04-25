#include <iostream>

using namespace std;

int main()
{
    int l,h;

    //binary search works on sorted array
    int arr[]={1,2,5,7,10,13};
    int n=sizeof(arr)/sizeof(int);
    l=0;
    h=n;
    int key,mid;
    cin>>key;
    int check=-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key == arr[mid])
        {
            cout<<"element found  "<<key;
            check=0;
            break;
        }
        else if( arr[mid] <key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }

    if(check == -1)
    {   
        cout<<"element not found";
    }

    return 0;
}