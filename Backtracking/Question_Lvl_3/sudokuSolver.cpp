#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int value)
{
    // Row check
    for(int i = 0; i < board.size(); i++)
    {
        if(i != col && board[row][i] == value) return false;
    }

    // Col check
    for(int i = 0; i < board.size(); i++)
    {
        if(i != row && board[i][col] == value) return false;
    }

    // Subgrid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for(int i = startRow; i < startRow + 3; i++)
    {
        for(int j = startCol; j < startCol + 3; j++)
        {
            if(i != row && j != col && board[i][j] == value) return false;
        }
    }

    return true;
}



bool getSolved(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (getSolved(board, i, j))
                        {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> board;

    for (int i = 0; i < 9; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 9; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        board.push_back(temp);
    }

    getSolved(board, 0, 0);

    cout << "-----This is the solution for sudoku-----" << endl;
    for (auto i : board)
    {
        sort(i.begin(), i.end());
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}