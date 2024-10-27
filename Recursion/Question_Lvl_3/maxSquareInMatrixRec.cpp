#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findMaxSquare(vector<vector<int>> &matrix, int i, int j, int &ans)
{
    if(i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }

    int right = findMaxSquare(matrix, i, j + 1, ans);
    int diagonal = findMaxSquare(matrix, i + 1, j + 1, ans);
    int down = findMaxSquare(matrix, i + 1, j, ans);

    if(matrix[i][j] == 0) return 0;
    else
    {
        int currentAns = min(right, min(down, diagonal)) + 1;
        ans = max(ans, currentAns);

        return currentAns;
    }
}

int main()
{

    vector<vector<int>> matrix = {
        {0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
    };

    int ans = 0;

    findMaxSquare(matrix, 0, 0, ans);

    cout << "Max area of sqare that can be created is " << ans * ans << endl;
    for(auto i : matrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    return 0;
}