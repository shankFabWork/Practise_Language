// pointer is a type of variable used to store address of another variable

#include <iostream>

using namespace std;

int main()
{

    //declaration
    int *a;          
    int b=10;

    //initialization
    a=&b;


    cout<<"value of a pointer ";
    //dereferencing
    cout<<*a;


    // in  c++
    
    //stack
    int arr1[5]={1,2,3,4,5};
    
    //heap
    int *p;
    p=new int[5];

    // can be written like this
    int *q=new int[5];
    q[0]=10;
    cout<<endl<<"value of a q heap  ";

    cout<<q[0];

    //we can delete heap like this
    // delete []q;
    // q=NULL;

    //we can not write like this
    q=NULL;
    delete []q;


    //please read this
    //this will give u error and leads to memory leak
    //reason
    // 'q' was pointing towards heap 
    //suppose [1,2,3,4] as heap
    // if q=NULL
    // 'q' is not pointing anywhere because of which if u delete []q;
    //it will give us error 
    //as 'q' is not pointing anywhere

     
    // removing delete []q;
    //won't give u error
    // but leads to memory leak

    //in modern c++ 
    //we use 'nullptr' instead of 'NULL'
    cout<<endl;
    int size1;
    cout<<"enter the no of element u want-> ";
    cin>>size1;
    int arr[size1];
    cout<<sizeof arr;
    // 20 -> 80
    //5 -> 20
    //sizeof array can not be modify 

    //so we have heap
    cout<<endl<<"heap"<<endl;
    int size2;
    cout<<"enter the no of element u want-> ";
    cin>>size2; //size like 20
    int *arr_heap1=new int[size2];
    
    delete []arr_heap1;
    //it is good practise to delete array
    //if it is of no use
    
    cin>>size2;    //size like 40
    int *arr_heap2=new int[size2];


    //with heap u can change the size as u want







    return 0;
}