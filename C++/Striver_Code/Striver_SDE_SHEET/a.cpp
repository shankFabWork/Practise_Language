#include <bits/stdc++.h>

using namespace std;

void displayValuesPairs(int Array[],int n) 
{
    vector <int> arr(Array,Array+n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]-arr[i] %2 == 0)
            {
                cout<<"("<<arr[j]<<","<<arr[i]<<")"<<" ";
            }
        }
    }
}

long int findLeastValue (int Array1 [], int Array2 [],int S) 
{
    vector <int> arr1(Array1,Array1+S);
    vector <int> arr2(Array2,Array2+S,greater<int>());
    int sum = 0;
    for(int i=0;i<S;i++)
    {
        sum += (arr1[i]*arr2[i]);
    }
    return sum;

}

int main()
{
    // string str = "my name is shank";
    // int n = str.length();
    // vector <string> str_vector;
    // vector <int> v;
    // int s = 0;
    // int e;
    // int count = 1;
    // for(int i=0;i<str.length();i++)
    // {
    //     if(str[i] == ' ')
    //     {
    //         e = i-1;
    //         v.push_back(e-s+1);
    //         str_vector.push_back(str.substr(s,e-s+1));
    //         s = i+1;
    //         count++;
    //     }
    // }
    // v.push_back(n-1-s+1);
    // str_vector.push_back(str.substr(s,n-1-s+1));
    // if(count%2 != 0)
    // {
    //     return str_vector[count/2];
    // }
    // else
    // {
    //     int mid1 = count/2-1;
    //     int mid2 = count/2;
    //     if(str_vector[mid1].length()  > str_vector[mid2].length())
    //     {
    //         return str_vector[mid1];
    //     }
    //     else
    //     {
    //         str_vector[mid2]
    //     }
    // }


    return 0;
}