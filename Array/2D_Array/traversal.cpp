#include <IOSTREAM>

using namespace std;

void rowTraversal(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void colTraversal(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        cout << arr[i][i] << " ";
    }
    cout << endl;
}

void diagonalTraversal(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

void oppDiagonalTraversal(int arr[3][3], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        cout << arr[i][row - i - 1] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int row = 3, col = 3;

    // rowTraversal(arr, row, col);
    // colTraversal(arr, row, col);
    // diagonalTraversal(arr, row, col);
    oppDiagonalTraversal(arr, row, col);

    return 0;
}