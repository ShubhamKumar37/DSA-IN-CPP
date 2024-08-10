#include <IOSTREAM>

using namespace std;

void printWave(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        if (i & 1 == 1)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = 0; j < rows; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
    }
}

int main()
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printWave(arr, 3, 3);

    return 0;
}