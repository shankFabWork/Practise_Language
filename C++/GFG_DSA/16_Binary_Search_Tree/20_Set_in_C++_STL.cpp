// Applications 
// a) sorted stream of data
// b) doubly ended priority queue

#include <iostream>
#include <set>

using namespace std;

int main()
{
    // in ascending order
    set <int> s;
    // in descending order
    // set <int,greater::iterator> s;
    s.insert(10);
    s.insert(5);
    s.insert(45);
    s.insert(95);
    s.insert(20);

    // for(auto it = s.begin();it != s.end();it++)
    for(set <int>::iterator it = s.begin();it != s.end();it++)
    {
        cout<<*it<<" ";
    }
    // Upper Bound - always greater than
    // Lower Bound - equal or greater than


    // lower bound
    // 5 10 20
    // s.lower_bound(5) -> 5
    // s.lower_bound(6) -> 10   
    // if element is not found it will return 
    // greater element than the current element

    // upper bound 
    // 1 2 4 5 6 
    // s.upper_bound(2) -> 4
    // s.upper_bound(4) -> 5
    // s.upper_bound(3) -> 4

    cout<<endl;
    if(s.upper_bound(20) != s.end())
    {
        cout<<"upper bound of 20 is "<<*s.upper_bound(20);
    }
    else
    {
        cout<<"upper bound of 20 is not found";
    }
    cout<<endl;
    if(s.upper_bound(40) != s.end())
    {
        cout<<"upper bound of 40 is "<<*s.upper_bound(40);
    }
    else
    {
        cout<<"upper bound of 40 is not found";
    }
    cout<<endl;
    if(s.lower_bound(90) != s.end())
    {
        cout<<"lower bound of 90 is "<<*s.lower_bound(90);
    }
    else
    {
        cout<<"lower bound of 90 is not found";
    }
    cout<<endl;
    if(s.lower_bound(100) != s.end())
    {
        cout<<"lower bound of 100 is "<<*s.lower_bound(100);
    }
    else
    {
        cout<<"lower bound of 100 is not found";
    }
    cout<<endl;    
    if(s.count(20))
    {
        cout<<"20 is present"<<endl;
    }
    else
    {
        cout<<"20 is not present"<<endl;
    }
    
    auto it = s.find(20);
    s.erase(it);
    for(auto it:s)
    {
        cout<<it<<" ";
    }

    it = s.find(10);
    s.erase(it,s.end());
    cout<<endl;
    for(int it:s)
    {
        cout<<it<<" ";
    }
    
    // Time Complexity all functions is log(n)
    // begin() , end()
    // rbegin() , rend()
    // cbegin() , cend()
    // size() , empty()

    // Time Complexity all functions is O(log(n))
    // insert() , find()
    // upper_bound() , lower_bound()
    // count() , erase()


    return 0;
}