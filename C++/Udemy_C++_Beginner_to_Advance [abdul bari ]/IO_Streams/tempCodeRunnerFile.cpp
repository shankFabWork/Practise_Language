#include <iostream>
#include <fstream>

using namespace std;

class Student
{
    public:
        string name;
        int roll_no;
        string branch;

        Student(string name,int roll_no,string branch)
        {
            this->name=name;
            this->roll_no=roll_no;
            this->branch=branch;
        }

        friend ofstream& operator<<(ofstream &outfile,Student &s);
        friend ifstream& operator>>(ofstream &infile,Student &s);
};

ofstream& operator<<(ofstream &outfile,Student &s)
{
    outfile<<s.name<<endl;
    outfile<<s.roll_no<<endl;
    outfile<<s.branch<<endl;
    outfile<<endl;
    
    return outfile;
}

ifstream& operator>>(ifstream &infile,Student &s)
{
    infile>>s.name;
    infile>>s.roll_no;
    infile>>s.branch;
    // infile>>NULL;
    return infile;
}


int main()
{
    //serialization is process of storing and 
    // retreiving the state of the object
    Student s1("shank",20,"CSE");
    // s1.name="shank";
    // s1.roll_no=20;
    // s1.branch="CSE";

    ofstream outfile("data.txt",ios::app);
    outfile<<s1;

    Student s2("shank",20,"CSE");
    outfile<<s2;

    outfile.close();

    ifstream infile;
    infile.open("data.txt");
    infile>>s1;

    // if(!infile)
    if(!infile.is_open() )
    {
        cout<<endl<<"file can not be open"<<endl;
    }
    else
    {
        cout<<s1.name<<endl<<s1.roll_no<<endl<<s1.branch;
    }
    
    return 0;
}