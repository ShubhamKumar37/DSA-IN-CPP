#include<iostream>
#include<vector>
#include<string>

using namespace std;

void findPossiblePath(vector<vector<int>> &maze, int i, int j, string str, vector<string> &ans)
{
    if(i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        ans.push_back(str);
        return ;
    }

    if(
        i < 0 ||
        j < 0 ||
        i >= maze.size() ||
        j >= maze[0].size() ||
        maze[i][j] == 0
    ) return ;

    maze[i][j] = 0;

    findPossiblePath(maze, i - 1, j , str + 'U', ans);
    findPossiblePath(maze, i + 1, j, str + 'D', ans);
    findPossiblePath(maze, i, j - 1, str + 'L', ans);
    findPossiblePath(maze, i, j + 1, str + 'R', ans);

    maze[i][j] = 1;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans;

    findPossiblePath(maze, 0, 0, "", ans);

    cout << "These are the possible path " << endl;
    for(auto i : ans)
    {
        cout << i << endl;
    }




    return 0;
}