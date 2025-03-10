#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validParanthesis(string &str)
{
    stack<char> s;

    for (auto i : str)
    {
        if (i == '(' || i == '{' || i == '[') s.push(i);
        else
        {
            if (s.empty())
                return false;

            char top = s.top();
            if (
                (top == '(' && i == ')') ||
                (top == '{' && i == '}') ||
                (top == '[' && i == ']'))
                s.pop();
            else
                return false;
        }
    }

    return s.empty();
}

int main()
{
    string str = "([{])";

    if (validParanthesis(str))
        cout << "Valid String" << endl;
    else
        cout << "Not valid string" << endl;

    return 0;
}