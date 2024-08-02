#include<IOSTREAM>

using namespace std;


void print2DArray(int arr[3][2], int row, int col)
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

int main()
{
    // int arr[3][2] = {
    //     {1, 2},
    //     {3, 4},
    //     {5, 6}
    // };
    // int arr[3][2] = {1, 2, 3, 4, 5};
    int arr[3][2];

    // cout << arr[254][1] << endl; Give garbage value or unexpected behaviour if declared statically

    fill(arr[0], arr[0] + 2, 10);
    fill(arr[1], arr[1] + 2, 20);
    fill(arr[2], arr[2] + 2, 30);

    print2DArray(arr, 3, 2);


    return 0; 
}