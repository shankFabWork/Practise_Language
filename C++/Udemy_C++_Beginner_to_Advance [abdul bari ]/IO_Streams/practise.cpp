#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    string str1;
    getline(cin,str1);
    ofstream outfile("a.txt");
    outfile<<str1<<endl<<20;
    outfile.close();

    ifstream infile;
    infile.open("a.txt");
    // if(!infile)
    if(!infile.is_open() )
    {
        cout<<endl<<"file do not exist"<<endl;
    }
    else
    {
        // string str2;
        // int val2;
        // infile>>str2;
        // infile>>val2;
        // cout<<endl<<str2<<endl<<val2;


        //for reading whole line
        // char str2[255];
        // while(infile) {
        //     infile.getline(str2,100);  // delim defaults to '\n'
        //     if(infile) cout << str2 << endl;

        // }
        //or

        string str3;
        while(infile) {
            getline(infile,str3);  // delim defaults to '\n'
            if(infile) cout << str3 << endl;
        }
        
    }

    if(infile.eof() )
    {
        cout<<endl<<"file has reached the end of the file"<<endl;
    }

    infile.close();
    

    return 0;
}