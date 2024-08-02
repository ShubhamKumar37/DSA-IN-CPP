#include<iostream>
#include<vector>

using namespace std;

void getSum(vector<vector<int>> array, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        int sum = 0;
        for(int j = 0; j < col; j++)
        {
            sum += array[i][j];
        }

        cout << "Sum of " << i <<"th row = " << sum << endl;
    }
}

int main()
{
    vector<vector<int>> array(4, vector<int> (3));

    cout << "Enter the value :- " << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "This is the 2D array " << endl;

    for(auto i : array)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    getSum(array, 4, 3);



    return 0;
}