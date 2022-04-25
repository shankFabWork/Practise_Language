#include <iostream>
using namespace std;

// Also called Linear Probing
class MyHash
{
    private:
        int *arr;
        int cap;
        int size;
    public:

    MyHash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        fill(arr,arr+cap,-1);
    }

    int hash(int val)
    {
        return (val%cap);
    }

    bool search(int val)
    {
        int h = hash(val);
        int i = h;
        while(arr[i] != -1)
        {
            if(arr[i] == val)
            {
                return true;
            }
            i = (i+1)%cap;
            if(i == h)
            {
                return false;
            }
        }
        return false;
    }

    bool insert(int key)
    {
        int h = hash(key);
        int i = h;
        if(size == cap)
        {
            return false;
        }
        while(arr[i] != -1 && arr[i] != -2 && arr[i] != key)
        {
            i = (i+1)%cap;
        }
        if(arr[i] == key)
        {
            return false;
        }
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
        return false;
    }

    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        while(arr[i] != -1)
        {
            if(arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i+1)%cap;
            if(i == h)
            {
                return false;
            }
        }
        return false;
    }

};

int main()
{
    MyHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);
    if(mh.search(56)==true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    mh.erase(56);
    if(mh.search(56)==true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}