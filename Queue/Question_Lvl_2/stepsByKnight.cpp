#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isPossible(pair<int, int> &front, pair<int, int> &tPos, vector<vector<bool>> &visited, queue<pair<int, int>> &q, int &n)
{
    int xAxis[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int yAxis[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for(int i = 0; i < 8; i++)
    {
        int newX = front.first + xAxis[i];
        int newY = front.second + yAxis[i];

        if(newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
        if(!visited[newX][newY])
        {
            visited[newX][newY] = true;
            if(tPos == make_pair(newX, newY)) return true;
            q.push({newX, newY});
        }
    }

    return false;
}

int main()
{
    int n = 6;
    pair<int, int> kPos = {4, 5};
    pair<int, int> tPos = {1, 1};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int step = 0;

    if(kPos == tPos) return 0;

    q.push(kPos);
    q.push({-1, -1});

    visited[kPos.first][kPos.second] = true;

    while(!q.empty())
    {
        auto front = q.front();
        q.pop();

        if(front == make_pair(-1, -1))
        {
            step++;
            if(q.empty()) break;
            q.push({-1, -1});
        }
        else
        {
            if(isPossible(front, tPos, visited, q, n)) 
            {
                cout << step + 1 << endl;
                break;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}