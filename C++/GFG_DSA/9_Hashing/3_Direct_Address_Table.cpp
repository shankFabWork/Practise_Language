// Imagine a situation where u hav 1000 keys 
// with values from (0 to 999)

// how would u implement following in O(1) time ->
// -> Search
// -> Insert
// -> Delete


// Disadvantages ->

// 1) do not work for floating point numbers
// for example -> u can use these indexes as an array

// 2) can not handle large keys

// 3) can not use with string
// suppose "gfg" as string 
// (how will u use them)

#include <iostream>

using namespace std;

int arr[1000];

// Direct Address Table
class DAT
{
    private:
    int *arr;
    public:

    DAT()
    {
        arr = new int[1000];
        fill(arr,arr+1000,0);
    }

    void insert(int a)
    {
        arr[a] = 1;
    }

    bool search(int a)
    {
        if(arr[a] == 1)
        {
            return true;
        }
        return false;
    }

    void del(int a)
    {
        arr[a] = 0;
    }

};


int main()
{
    // range must be between 0 - 1000
    // insert()
    DAT dat;
    dat.insert(10);
    dat.insert(20);
    dat.insert(119);
    cout<<dat.search(10)<<endl;
    cout<<dat.search(20)<<endl;
    dat.del(119);
    cout<<dat.search(119)<<endl;
}