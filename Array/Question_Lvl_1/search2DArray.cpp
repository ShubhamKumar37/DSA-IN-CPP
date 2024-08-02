#include<iostream>

using namespace std;

void takeInputRowWise(int arr[3][3], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter the value of " << i << "th row , " << j << "th col = ";
            cin >> arr[i][j];
        }
    }
}

void findTarget2DArray(int arr[][3], int row, int col, int target)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == target)
            {
                cout << "Element is found at index = " << i << " , " << j << endl;
                return ;
            }
        }
    }

    cout << "Element is not present in 2D array " << endl;
}

int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    int target = 89;

    takeInputRowWise(arr, row, col);

    findTarget2DArray(arr, row, col, target);

    return 0;
}