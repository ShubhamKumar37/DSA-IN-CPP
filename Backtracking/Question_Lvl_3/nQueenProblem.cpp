#include<IOSTREAM>
#include<STRING>
#include<VECTOR>

using namespace std;

bool isSafe(vector<string> &grid, int n, int row, int col)
{
    for(int i = col; i >= 0; i--)
    {
        if(grid[row][i] == 'O') return false;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(grid[i][j] == 'O') return false;
    }
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if(grid[i][j] == 'O') return false;
    }

    return true;
    
}

void getPossiblePosition(vector<string> &grid, int n, int col, vector<vector<string> > &ans)
{
    if(col >= n)
    {
        vector<string> temp;

        for(auto i : grid) temp.push_back(i);

        ans.push_back(temp);
        return ;
    }

    // We use loop from 0 because we know if previous column is done with position then we have to start with new column from top of it or from 0th index
    for(int i = 0; i < n; i++)
    {
        if(isSafe(grid, n, i, col))
        {
            grid[i][col] = 'O';
            getPossiblePosition(grid, n, col + 1, ans);
            grid[i][col] = 'X';
        }
    }
}

vector<vector<string>> solve(int n)
{
    vector<vector<string>> ans;
    vector<string> grid;

    for(int i = 0; i < n; i++)
    {
        string tempStr = "";

        for(int j = 0; j < n; j++)
        {
            tempStr += 'X';
        }
        grid.push_back(tempStr);
    }

    getPossiblePosition(grid, n, 0, ans);

    return ans;
}

int main()
{
    int n = 12;

    vector<vector<string>> ans = solve(n);

    for(auto i : ans)
    {
        for(auto j : i)
        {
            for(auto k : j) cout << k << " ";
            cout << endl;
        }
        cout << "-------------------" << endl;
        cout << "-------------------" << endl;
    }

    cout << "HOGYA" << endl;



    return 0;
}