// hash map

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // elements are arranged in the <key,value> pair
    unordered_map <int,int> myMap;
    // myMap[1] = 10; 
    // myMap[2] = 12; 
    // myMap[3] = 17; 
    myMap.insert(make_pair(1,10));
    myMap.insert(make_pair(2,12));
    myMap.insert(make_pair(3,17));
    for(auto curr = myMap.begin();curr != myMap.end();curr++)
    {
        cout<<curr->first<<" ";
    }



    return 0;
}