#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//stream is a flow of data
//or
//stream is a flow of character
int main()
{

    //two modes are available
    // ios::app   (append)
    // ios::trunc (default)

    //for writing
    ofstream outfile("my.txt",ios::app);
    outfile<<"shank is"<<endl;
    outfile<<20<<endl;
    outfile.close();

    ifstream infile;
    infile.open("my.txt");

    // << stream extraction or extraction operator
    // >> stream insertion or insertion operator

    //two ways of checking wheteher the file is open
    // if(!infile.is_open())
    if(!infile)
    {
        //as file do not exist
        cout<<endl<<"file can not be open"<<endl;
    }
    else
    {
        string str;
        int val;
        infile>>str;
        infile>>val;
        cout<<str<<" "<<val;
    }

    if(!infile.eof())
    {
        cout<<endl<<"end of file has reached"<<endl;
    }

    infile.close();

    return 0;
}