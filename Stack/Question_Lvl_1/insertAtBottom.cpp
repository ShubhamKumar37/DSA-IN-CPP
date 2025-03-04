#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int ele)
{
    if(s.empty())
    {
        cout << ele << " ";
        s.push(ele);
        return ;
    }

    int topEle = s.top();
    s.pop();
    cout << topEle << " ";
    insertAtBottom(s, ele);
    s.push(topEle);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(11);
    s.push(112);
    s.push(1123);
    s.push(1124);

    insertAtBottom(s, 10);
    cout << endl;

    cout << s.size() << endl;

    return 0;
}