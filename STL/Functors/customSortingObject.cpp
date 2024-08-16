#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

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

class Comparator
{
public:
    bool operator()(const Student &s1, const Student &s2)
    {
        if (s1.marks == s2.marks)
        {
            return s1.name < s2.name;
        }

        return s1.marks > s2.marks;
    }
};

int main()
{
    vector<Student> arr;
    arr.push_back(Student(90, "John"));
    arr.push_back(Student(95, "Mathew"));
    arr.push_back(Student(95, "Rock"));
    arr.push_back(Student(97, "Siwa"));

    sort(arr.begin(), arr.end(), Comparator());

    for (Student i : arr)
    {
        cout << i.name << " = " << i.marks << endl;
    }

    return 0;
}
