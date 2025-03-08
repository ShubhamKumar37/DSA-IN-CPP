#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> &s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void pushEle(stack<int> &s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return ;
    }

    if(s.top() > ele)
    {
        int top = s.top();
        s.pop();
        pushEle(s, ele);
        s.push(top);
    }
    else s.push(ele);
}

int main()
{
    stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    pushEle(s, 1);

    print(s);

    return 0;
}