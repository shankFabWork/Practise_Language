#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    // array of character is called as c-styled array

    char str1[] = "gfg";
    // g f g \0 
    // '\0' is put by the compiler itself

    char str2[6] = "gfg";
    // g f g \0 \0 \0

    // character has a byte of 2 each
    cout<<sizeof(str1)<<endl;
    cout<<sizeof(str2)<<endl;

    // if u r using an array using single quotes 
    // then u must to put '\0'
    // it is not a error 
    // but while transversing strng won't stop
    char str3[6] = {'g','f','g'};

    // compare string in c-styld array
    if(strcmp(str2,str3) == 0)
    {
        cout<<str1<<" is equal to "<<str2<<endl;
    }
    else if(strcmp(str2,str3) > 0)
    {
        cout<<str1<<" is greater to "<<str2<<endl;
    }
    else
    {
        cout<<str1<<" is less to "<<str2<<endl;
    }


    // functions

    // strlen
    // strcpy
    // strcmp

    char str4[] = "shank";  



    // u have to use cstring header file
    cout<<strlen(str4)<<endl;

    char s1[] = "data";
    char s2[10];
    strcpy(s2,s1);
    cout<<s2<<endl;

    // use c++ string instead of c-styled string
    // -> Richer Library
    // -> support operator like +,==,>=,<=
    // -> do not have to worry about size
    // -> can be converted into c-tyled string if needed

    string content = "go for it";
    cout<<content.length()<<endl;
    content = content + " my friend";
    cout<<content<<endl;
    // stars with 0 as index
    cout<<content.substr(1,5)<<"  ->substr(1,5) "<<endl;
    cout<<content.find("fo")<<endl;
     

         // compare string in c-styld array
    if(str2 == str3)
    {
        cout<<str1<<" is equal to "<<str2<<endl;
    }
    else if(str2 > str3)
    {
        cout<<str1<<" is greater to "<<str2<<endl;
    }
    else
    {
        cout<<str1<<" is less to "<<str2<<endl;
    }

    // cin always remove word after space 

    // c-styles array
    char data1[100];
    cin.getline(data1,100,'\n');
    cout<<data1<<endl;

    // string in c++
    string data2;
    getline(cin,data2,'\n');
    cout<<data2<<endl;

    // interating in c-styled array
    for(int i=0;data1[i] != '\0';i++)
    {
        cout<<data1[i]<<" ";
    }
    cout<<endl;


    // interating in c++ array
    for(int i=0;i < data2.length();i++)
    {
        cout<<data2[i]<<" ";
    }
    cout<<endl;

    return 0;
}