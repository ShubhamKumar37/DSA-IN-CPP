#include<IOSTREAM>
#include<LIST>

using namespace std;

void printList(list<int> &list1)
{
    list<int>::iterator it = list1.begin();

    while(it != list1.end())
    {
        cout << *it++ << " ";
    }
    cout << endl;
}

int main()
{
    // List is a doubly linked list datastructure

    list<int> list1;    

    list1.push_back(23);
    list1.push_back(234);
    list1.push_back(2);
    list1.push_back(2353);

    list1.push_front(10);

    printList(list1);

    list1.pop_back();

    list1.pop_front();

    printList(list1);

    cout << list1.front() << endl;

    // list1.clear();

    cout << *(list1.begin()) << endl;

    return 0;
}