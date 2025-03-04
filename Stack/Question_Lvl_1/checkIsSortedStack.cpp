#include<iostream>
#include<stack>

using namespace std;

bool isSorted(stack<int> &s)
{
    if(s.size() == 0 || s.size() == 1) return true;

    int topEle = s.top();
    s.pop();

    if(topEle > s.top()) return false;
    return isSorted(s);
}

int main()
{
    stack<int> s; 

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    if(isSorted(s)) cout << "Stack is sorted" << endl;
    else cout << "Stack is not sorted" << endl;

    return 0;
}