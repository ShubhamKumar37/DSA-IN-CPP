#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

void reverseQueueRec(queue<int> &q)
{
    if(q.empty()) return ;

    int front = q.front();
    q.pop();

    reverseQueueRec(q);
    q.push(front);
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    print(q);

    // reverseQueue(q);
    reverseQueueRec(q);

    print(q);



    return 0;
}