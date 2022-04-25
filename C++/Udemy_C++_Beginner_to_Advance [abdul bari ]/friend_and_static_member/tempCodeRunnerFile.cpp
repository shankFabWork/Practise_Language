#include <iostream>

using namespace std;

class Student
{
    public:
        int rollno;
        string name;

        static int addNo;

        Student(string n)
        {
            addNo++;
            name=n;
            rollno=addNo;
        }

        void display()
        {
            cout<<"name is "<<name<<endl;
            cout<<"rollno is "<<rollno<<endl;
        }

};

int Student::addNo=0;

int main()
{
    Student s1("shank");
    s1.display();
    Student s2("rajan");
    s1.display();

    return 0;
}