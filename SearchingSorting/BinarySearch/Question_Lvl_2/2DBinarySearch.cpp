#include<IOSTREAM>
#include<VECTOR>

using namespace std;

pair<int, int> findTarget(vector<vector<int>> &matrix, int rows, int cols, int target)
{
    int s = 0, e = (rows * cols) - 1;
    int mid = s + ((e - s) >> 1);

    while(s <= e)
    {
        int row = (mid / cols);
        int col = (mid % cols);
        int value = matrix[row][col];

        if(value == target)
        {
            return make_pair(row, col);
        }
        else if(value < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + ((e - s) >> 1);
    }

    return make_pair(-1, -1);
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int target = 150;

    pair<int, int> cordinate = findTarget(matrix, matrix.size(), matrix[0].size(), target);
    cout << "Target found at " << cordinate.first << ", " << cordinate.second << endl;

    return 0;
}