#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BrowserHistory
{
public:
    stack<string> curr;
    stack<string> next;

    BrowserHistory(string homepage)
    {
        this->curr.push(homepage);
    }

    void visit(string url)
    {
        while (!next.empty())
            next.pop();

        curr.push(url);
    }

    string back(int steps)
    {
        while (curr.size() > 1 && steps != 0)
        {
            string top = curr.top();
            curr.pop();
            next.push(top);

            steps--;
        }

        return curr.top();
    }

    string forward(int steps)
    {
        while (!next.empty() && steps != 0)
        {
            string top = next.top();
            next.pop();
            curr.push(top);

            steps--;
        }

        return curr.top();
    }
};
