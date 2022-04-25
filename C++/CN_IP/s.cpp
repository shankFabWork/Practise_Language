#include <iostream>

using namespace std;

class Student
{
    private:
    char *name;
    int age;
    static int no_of_student;

    public:

    Student(char *name,int age)
    {
        this->name = name;
        this->age = age;
        Student::no_of_student++;
    }

    static int get_no_of_student()
    {
        return Student::no_of_student;
    }

};

int Student::no_of_student = 0;

int main()
{
    char name[] = "shank";
    Student s1(name,20);
    Student s2(name,20);
    Student s3(name,20);
    Student s4(name,20);
    cout<<Student::get_no_of_student();
    // cout<<s1.get_no_of_student();
}