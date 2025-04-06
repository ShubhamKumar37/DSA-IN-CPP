#include <iostream>
#include <stack>

using namespace std;

bool isCelebrity(int arr[3][3], int n, int p)
{
    int count0 = 0;
    int count1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][p] == 1)
            count1++;
        if (arr[p][i] == 0)
            count0++;
    }

    return (count1 == n && count0 == (n - 1));
}

int findCelebrity(int arr[3][3], int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int p1 = s.top();
        s.pop();
        int p2 = s.top();
        s.pop();

        if (arr[p1][p2] == 1)
            s.push(p2);
        else
            s.push(p1);
    }

    return isCelebrity(arr, n, s.top()) == true ? s.top() : -1;
}

int main()
{
    int arr[3][3] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1},
    };

    int n = 3;
    cout
        << "Celebrity = " << findCelebrity(arr, n) << endl;

    return 0;
}