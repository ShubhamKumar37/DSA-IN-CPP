#include <IOSTREAM>
#include <VECTOR>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    int totalElement = cols * rows;
    int rowStart = 0;
    int colStart = 0;
    int rowEnd = rows - 1;
    int colEnd = cols - 1;

    while (count < totalElement)
    {
        for (int i = colStart; count < totalElement && i <= colEnd; i++)
        {
            ans.push_back(matrix[rowStart][i]);
            count++;
        }
        rowStart++;

        for (int i = rowStart; count < totalElement && i <= rowEnd; i++)
        {
            ans.push_back(matrix[i][colEnd]);
            count++;
        }
        colEnd--;

        for (int i = colEnd; count < totalElement && i >= colStart; i--)
        {
            ans.push_back(matrix[rowEnd][i]);
            count++;
        }
        rowEnd--;

        for (int i = rowEnd; count < totalElement && i >= rowStart; i--)
        {
            ans.push_back(matrix[i][colStart]);
            count++;
        }
        colStart++;
    }

    return ans;
}

int main()
{
    int rows, cols;
    vector<vector<int>> matrix;
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
    {
        vector<int> temp;
        for (int j = 0; j < cols; j++)
        {
            int element;
            cin >> element;
            temp.push_back(element);
        }
        matrix.push_back(temp);
    }

    vector<int> ans = spirallyTraverse(matrix);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}