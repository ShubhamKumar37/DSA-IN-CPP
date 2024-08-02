#include<IOSTREAM>

using namespace std;


// Giving one value is must because in memory 2D array is stored in linear format whose formualt is (C * i + j) that why providing C is must 
// when passing the 2D array in function
void print2DArray(int arr[][3], int row, int col) 
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

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

void takeInputColWise(int arr[3][3], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter the value of " << j << "th row , " << i << "th col = ";
            cin >> arr[j][i];
        }
    }
}

int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;

    // takeInputRowWise(arr, row, col);
    takeInputColWise(arr, row, col);

    print2DArray(arr, row, col);

    // int arr[3][2] = {
    //     {1, 2},
    //     {3, 4},
    //     {5, 6}
    // };
    // int arr[3][2] = {1, 2, 3, 4, 5};
    // int arr[3][2];

    // cout << arr[254][1] << endl; Give garbage value or unexpected behaviour if declared statically

    // fill(arr[0], arr[0] + 2, 10);
    // fill(arr[1], arr[1] + 2, 20);
    // fill(arr[2], arr[2] + 2, 30);

    // print2DArray(arr, 3, 2);


    return 0; 
}