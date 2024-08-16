#include <IOSTREAM>

using namespace std;

class Student
{
public:
    int marks;
    string name;
    Student(int marks, string name)
    {
        this->marks = marks;
        this->name = name;
    }
};

class First_Functor
{
public:
    bool operator()(Student &a, Student &b)
    {
        // This will sort our array in descending
        return a.marks > b.marks;
    }
    // bool operator()(int a, int b)
    // {
    //     // This will sort our array in descending
    //     return a > b;
    // }
};

int main()
{
    First_Functor cmp;

    Student s1(98, "Shubham Kumar");
    Student s2(95, "Nikhil");

    if (cmp(s1, s2))
    {
        cout << "Marks of student a is greater then b " << endl;
    }
    else
    {
        cout << "Marks of student b is greater than a " << endl;
    }

    // if(cmp(4, 2))
    // {
    //     cout << "4 is greater then 2 " << endl;
    // }
    // else
    // {
    //     cout << "4 is lesser then 2 " << endl;
    // }

    return 0;
}