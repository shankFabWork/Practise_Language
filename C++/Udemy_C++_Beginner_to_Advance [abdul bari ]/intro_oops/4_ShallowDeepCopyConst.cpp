#include <iostream>

using namespace std;

// problem with shallow copy constructor
class Test1
{

    private:
        int size;
        int *arr;
        int *data;

    public:

        Test1(int n)
        {
            size=n;
            arr=new int[n];
            data=new int;
        }

        Test1(Test1 &t)
        {
            size=t.size;
            arr=t.arr;
            data=t.data;
        }

        void dispArray()
        {
            cout<<endl<<"array elements is "<<endl;
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<endl<<"data value is "<<*data<<endl;
        }

        auto getArray()
        {
            return arr;
        }

        auto getData()
        {
            return data;
        }

        

};

// problem with deep copy constructor
class Test2
{

    private:
        int size;
        int *arr;
        int *data;

    public:

        Test2(int n)
        {
            size=n;
            arr=new int[n];
            data=new int;
        }

        Test2(Test2 &t)
        {
            size=t.size;
            arr=new int[t.size];
            data=new int;
        }

        void dispArray()
        {
            cout<<endl<<"array elements is "<<endl;
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<endl<<"data value is "<<*data<<endl;
        }

        auto getArray()
        {
            return arr;
        }

        auto getData()
        {
            return data;
        }

};

int main()
{
    int n1;
    cout<<"\n"<<"enter the size of the array"<<"\n";
    cin>>n1;
    Test1 t1(n1);

    int *arr1=t1.getArray();
    cout<<endl;
    cout<<"plz enter the elements";
    cout<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<endl<<"enter data "<<endl;
    int *data1=t1.getData();
    cin>>*data1;
    t1.dispArray();

    Test1 t2(t1);
    t2.dispArray();





    int n2;
    cout<<"\n"<<"enter the size of the array"<<"\n";
    cin>>n2;

    Test2 t3(n2);
    int *arr2=t3.getArray();
    cout<<endl;
    cout<<"plz enter the elements";
    cout<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    cout<<endl<<"enter data "<<endl;
    int *data2=t3.getData();
    cin>>*data2;
    t3.dispArray();

    Test2 t4(t3);
    t4.dispArray();

    return 0;
}



// 2
// 1 3
// 4
// 2
// 1 3 
// 4
