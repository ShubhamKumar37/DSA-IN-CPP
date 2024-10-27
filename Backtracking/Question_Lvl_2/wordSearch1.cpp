#include<IOSTREAM>
#include<VECTOR>
#include<STRING>

using namespace std;

bool findSeq(vector<string> &board, string &target, int row, int col, int index)
{
    if(index == target.size()) return true;

    if(
        row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||board[row][col] != target[index]
    ) return false;

    char value = board[row][col];
    board[row][col] = '@';

    bool ans = findSeq(board, target, row + 1, col, index + 1);
    if(ans) return true;
    
    ans = findSeq(board, target, row - 1, col, index + 1);
    if(ans) return true;

    ans = findSeq(board, target, row, col + 1, index + 1);
    if(ans) return true;

    ans = findSeq(board, target, row, col - 1, index + 1);
    if(ans) return true;


    board[row][col] = value;

    return false;
}

bool possibleSearch(vector<string> &board, string &target)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(findSeq(board, target, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<string> board = {{"bap"}, {"rlc"}, {"ace"}};
    string target = "balu";

    if(possibleSearch(board, target))
    {
        cout << "Target is founded in the board" << endl;
    }
    else
    {
        cout << "Target is not present in board" << endl;
    }

    return 0;
}