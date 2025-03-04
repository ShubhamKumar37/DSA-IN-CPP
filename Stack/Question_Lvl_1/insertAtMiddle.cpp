#include<iostream>
#include<stack>

using namespace std;

void insertAtMiddle(stack<int> &s, int n, int ele)
{
    if(n == 0)
    {
        cout << ele << " ";
        s.push(ele);
        return ;
    }

    int topEle = s.top();
    s.pop();
    cout << topEle << " ";
    insertAtMiddle(s, n - 1, ele);
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

    insertAtMiddle(s, (s.size() >> 1), 10);
    cout << endl;

    cout << s.size() << endl;

    return 0;
}