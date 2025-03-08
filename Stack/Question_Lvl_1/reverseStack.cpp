#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int top)
{
    if (s.empty())
    {
        s.push(top);
        return;
    }

    int ele = s.top();
    s.pop();
    insertAtBottom(s, top);
    s.push(ele);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int ele = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, ele);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}