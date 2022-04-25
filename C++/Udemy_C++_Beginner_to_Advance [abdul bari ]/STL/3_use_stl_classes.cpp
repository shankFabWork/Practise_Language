#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>

using namespace std;

int main()
{
    vector <int> arr1={1,2,3,4,5};
    arr1.push_back(10);
    arr1.push_back(20);

    for(auto x:arr1)
        cout<<x<<"\t";

    cout<<endl;

    arr1.pop_back();

    for(auto x:arr1)
        cout<<x<<"\t";

    cout<<endl;

    for(int i=0;i<arr1.size();i++)
    {
        cout<<arr1[i]<<"\t";
    }

    cout<<endl;

    for(int i=0;i<arr1.size();i++)
    {
        cout<<arr1.at(i)<<"\t";
    }

    cout<<endl;

    for(vector <int>::iterator it=arr1.begin();it != arr1.end()  ; it++)
    {
        cout<<*it<<"\t";
    }

    cout<<endl;

    list <int> arr2={20,53,12};
    arr2.push_back(23);
    arr2.push_back(20);

    for(auto x:arr2)
        cout<<x<<"\t";

    cout<<endl;

    forward_list <int> arr3={20,53,12};
    arr3.push_front(23);
    arr3.push_front(20);

    for(auto x:arr3)
        cout<<x<<"\t";

    cout<<endl;

    forward_list <int> arr4={20,53,12};
    arr4.push_front(23);
    arr4.push_front(20);

    for(auto x:arr4)
        cout<<x<<"\t";

    cout<<endl;

    set <int> arr5={20,53,12};
    arr5.insert(23);
    arr5.insert(20);

    for(auto x:arr5)
        cout<<x<<"\t";


    return 0;
}