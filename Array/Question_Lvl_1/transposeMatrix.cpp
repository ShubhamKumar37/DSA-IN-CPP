#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> makeTranspose1(vector<vector<int>> &arr, int row, int col)
{
    vector<vector<int>> temp(col, vector<int>(row));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[j][i] = arr[i][j];
        }
    }

    return temp;
}

vector<vector<int>> makeTranspose2(vector<vector<int>> &arr, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    return arr;
}

int main()
{
    vector<vector<int>> arr(3, vector<int>(4));

    cout << "Before transpose " << endl;

    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = k++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // vector<vector<int>> TMatrix = makeTranspose1(arr, 3, 4);
    vector<vector<int>> TMatrix = makeTranspose2(arr, 3, 3);

    cout << "After transpose " << endl;
    for(auto i : TMatrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}