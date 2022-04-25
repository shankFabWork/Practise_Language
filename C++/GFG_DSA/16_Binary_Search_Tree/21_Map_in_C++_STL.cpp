#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <int,int> m;
    m.insert({10,200});
    m[15] = 100;
    m.insert({3,300});
    m.insert({4,500});
    m.insert({7,900});
    for(auto &x:m)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    cout<<m.size();
    cout<<endl;
    for(map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    for(auto it = m.find(10);it != m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    m.erase(m.find(10),m.find(15));
    cout<<endl;
    for(map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;

    // Time Complexity all functions is O(log(n)) ->
    // count()
    // find()
    // erase(key)
    // insert()
    // []

    // Time Complexity all functions is O(1) ->
    // begin()
    // end()
    // rbegin()
    // rand()
    // size()
    // empty()

    // Application:
    // 1) sorted stream of data with (key,value) pair
    // 2) doubly ended priority queue of items
    // with (key,value) pairs

    return 0;
}