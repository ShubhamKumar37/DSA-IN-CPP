#include <iostream>
#include <queue>

using namespace std;

queue<int> interleaveFirstSecondHalf(queue<int> &q)
{
    int n = q.size();
    queue<int> q1;
    queue<int> q2;

    if(n < 1) return q1;

    int i = 0; 
    while(i < (n >> 1))
    {
        q1.push(q.front());
        q.pop(); 
        i++;
    }
    while(i < n)
    {
        q2.push(q.front());
        q.pop(); 
        i++;
    }

    while(!q1.empty())
    {
        q.push(q1.front());
        q1.pop();

        q.push(q2.front());
        q2.pop();
    }

    return q;
}

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);

    queue<int> ans = interleaveFirstSecondHalf(q);

    print(ans);

    return 0;
}