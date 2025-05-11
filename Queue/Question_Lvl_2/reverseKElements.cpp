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

void reverseK(queue<int> &q, int k)
{
    int times = q.size() / k;

    for(int i = 0; i < times; i++)
    {
        stack<int> s;
        for(int j = 0; j < k; j++)
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

    times = q.size() % k; 
    for(int i = 0; i < times; i++)
    {
        q.push(q.front());
        q.pop();
    }
}


int main()
{
    queue<int> q;
    int k = 1;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    
    print(q);

    reverseK(q, k);

    print(q);

    return 0;
}