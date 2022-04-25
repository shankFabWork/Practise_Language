#include <iostream>
#include <list>

using namespace std;

class MyHash
{
    private:
        int bucket;
        list <int> *l;
    public:
        MyHash(int size)
        {
            bucket = size;
            l = new list <int> [size];
        }

        void insert(int x)
        {
            int i = (x%bucket);
            l[i].push_back(x);
        }

        void remove(int x)
        {
            int i = (x%bucket);
            l[i].pop_back();
        }

        bool search(int x)
        {
            int i = x%bucket;
            for(int elem:l[i])
            {
                return true;
            }
            return false;
        }
};

int main()
{
    MyHash mh(7);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15);
}