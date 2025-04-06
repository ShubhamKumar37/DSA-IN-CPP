#include<iostream>
#include<stack>
#include<string>

using namespace std;

int minReversal(string &str)
{
    if(str.size() & 1) return -1;

    stack<char> s;
    int ans = 0;

    for(auto i : str)
    {
        if(!s.empty() && s.top() == '(' && i == ')') s.pop();
        else s.push(i);
    }

    while(!s.empty())
    {
        char char1 = s.top(); s.pop();
        char char2 = s.top(); s.pop();
        
        if(char1 != char2) ans++;
        ans++;
    }

    return ans;
}

int main()
{
    string str = "())))()()(()))))()())(((((()(())))))";

    cout << minReversal(str) << endl;

    return 0;
}