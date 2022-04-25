#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <int,string> m;
    m.insert(pair<int,string>(1,"Shank") );
    m.insert(pair<int,string>(2,"Rajan") );
    m.insert(pair<int,string>(3,"Janu") );

    map <int,string>::iterator it1;
    for(it1=m.begin();it1 != m.end() ;it1++)
    {
        cout<<it1->first<<" "<<it1->second<<"\t";
    }
    
    cout<<endl;

    map <int,string>::iterator it2;
    it2=m.find(3);
    cout<<it2->first<<" "<<it2->second<<"\t";


    return 0;
}