#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main()
{
    queue<int> q;
    deque<int> dq;

    q.push(12);
    q.push(13);
    q.push(14);

    cout << q.front() << endl;
    cout << q.back() << endl;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout << "Deque elements: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "Deque after popping front and back: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}