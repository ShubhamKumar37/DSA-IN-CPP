#include<IOSTREAM>
#include<QUEUE>
#include<VECTOR>

using namespace std;

class Student
{
    public:
    int marks = 0;
    string name;

    Student(int marks, string name)
    {
        this -> marks = marks;
        this -> name = name;
    }
};

class Comparator
{
    public:
    bool operator()(const Student &a, const Student &b) 
    {

        // if we use "<" operator then according to normal sorting comparator it should make it as min_heap but concept of heap says that the most priority element will be found on the end of the vector so the in case of heap it will work in reverse way which is using ">"
        return a.marks > b.marks;
        // return a.marks < b.marks;
    }
};


int main()
{  
    // Both of these are same as they will create a max heap by default;
    // priority_queue<int> p1;
    // priority_queue<int, vector<int>, less<int>> pq;

    priority_queue<Student, vector<Student>, Comparator > pq;

    pq.push(Student(98, "Shubham"));
    pq.push(Student(93, "Nikhil"));
    pq.push(Student(94, "Prabal"));
    pq.push(Student(96, "Nitin"));

    while(!pq.empty())
    {
        Student obj = pq.top();
        pq.pop();

        cout << obj.name << " = " << obj.marks << endl;
    }

    return 0;
}