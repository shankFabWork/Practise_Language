#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    for(int i=0;i<50;i++)
    {
        cout<<v.size()<<" "<<v.capacity()<<endl;
        v.push_back(i);
    }
}