#include<iostream>
#include<stack>
#include<string> 

using namespace std;

bool isOperator(char &i)
{
    return (i == '+' || i == '/' || i == '*' || i == '-');
}

bool isRedundant(string &str)
{
    stack<char> S;

    for(auto i : str)
    {
        if(!isOperator(i) && i != '(' && i != ')') continue;
        else if(isOperator(i) || i == '(') S.push(i);
        else
        {
            if(S.empty()) break;
            else if(isOperator(S.top())) 
            {
                while(!S.empty() && isOperator(S.top())) S.pop();
                S.pop();
            }
            else break;
        }
    }

    while(!S.empty() && isOperator(S.top())) S.pop();
    return !S.empty();
}

int main()
{
    // string str = "((a+b))";
    string str = "(c + (a+b))";

    if(isRedundant(str)) cout << "There are redundant paranthesis" << endl;
    else cout << "There are no redundant paranthesis" << endl;

    return 0;
}