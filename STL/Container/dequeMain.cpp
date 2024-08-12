#include<IOSTREAM>
#include<QUEUE>

using namespace std;

int main()
{
    // Created using doubly linked list may be
    // We can traverse deque using iterator

    deque<int> deque1;

    deque1.push_back(100);
    deque1.push_front(40);
    deque1.push_front(20);
    deque1.push_front(30);


    cout << deque1[2] << endl;
    cout << deque1[22] << endl; // Garbage value

    // cout << deque1.back() << endl;
    // cout << deque1.front() << endl;

    // deque1.pop_back();
    // deque1.pop_front();


    // cout << deque1.back() << endl;
    // cout << deque1.front() << endl;
    // cout << deque1.size() << endl;
    // cout << deque1.empty() << endl;

    // deque<int>::iterator it = deque1.begin();

    // while(it != deque1.end())
    // {
    //     cout << *it++ << endl;
    // }



    return 0;
}