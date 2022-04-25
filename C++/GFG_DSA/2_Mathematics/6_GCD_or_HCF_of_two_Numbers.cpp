#include <iostream>
#include <vector>

using namespace std;

// I/P
// a = 4 , b = 6
// O/P
// 2

// I/P
// a = 100 , b = 200
// O/P
// 100

// I/P
// a = 7 , b = 13
// O/P
// 1

void gcf_hcf_1(int no1,int no2)
{
    vector <int> v,arr1,arr2;
    int i=0,j=0;

    for(i=1;i<=no1;i++)
    {
        if(no1 % i == 0)
        {
            arr1.push_back(i);
        }
    }

    for(i=1;i<=no2;i++)
    {
        if(no2 % i == 0)
        {
            arr2.push_back(i);
        }
    }

    for(i=0;i<arr1.size();i++)
    {
        for(j=0;j<arr2.size();j++)
        {
            if(arr1[i] == arr2[j])
            {
                v.push_back(arr1[i]);
            }
        }
    }

    cout<<endl;    
    for(i=0;i<arr1.size();i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
    cout<<endl;    
    for(i=0;i<arr2.size();i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    cout<<endl;    
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<endl<<"GCF is "<<v[v.size()-1]<<endl;
}

int gcf_hcf_2(int no1,int no2)
{
    int res = min(no1,no2);
    while(res > 0)
    {
        if(no1%res == 0 && no2%res == 0)
        {
            break;
        }
        res--;
    }   
    return res;
}

// this is Simple euclidien algorithm
int gcf_hcf_3(int no1,int no2)
{
    while(no1 != no2)
    {
        if(no1 > no2)
        {
            no1=no1-no2;
        }
        else
        {
            no2=no2-no1;
        }
    }
    return no1;
    // return no2;
    // both will be same
}

// this is optimized Euclidien algorithm
// ==> Euclidien algorithm
int gcf_hcf_4(int no1,int no2)
{
    if(no2 == 0)
    {
        return no1;
    }
    else
    {
        return gcf_hcf_4(no2,no1%no2);
    }
}

int main()
{
    // int no1=7,no2=13;
    // int no1=10,no2=20;
    // int no1=4,no2=6;
    // int no1=100,no2=200;
    int no1=100,no2=50;

    cout<<endl;
    gcf_hcf_1(no1,no2);

    cout<<gcf_hcf_2(no1,no2)<<endl;
    // Time Complexity -> O(min(a,b))
    // Space Complexity -> O(1)

    cout<<gcf_hcf_3(no1,no2)<<endl;
    // Time Complexity -> O(log(min(a,b)))
    // Space Complexity -> O(1)
    
    cout<<gcf_hcf_4(no1,no2);
    // Time Complexity -> O(log(min(a,b)))
    // Space Complexity -> O(1)
    // but take some less time    

    return 0;
}