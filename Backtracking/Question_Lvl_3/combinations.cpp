#include<IOSTREAM>
#include<VECTOR>

using namespace std;

void getAllCombination(vector<int> &arr, int n, int k, int index, vector<int> &temp, vector<vector<int>> &ans)
{
    if(k == 0)
    {
        ans.push_back(temp);
        return ;
    }

    for(int i = index; i <= n; i++)
    {
        temp.push_back(i);
        getAllCombination(arr, n, k - 1, i + 1, temp, ans);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 7;
    int k = 3;
    vector<vector<int>> ans;
    vector<int> temp;

    getAllCombination(arr, n, k, 1, temp, ans);

    cout << "-----Printing All Combination-----" << endl;
    for(vector<int> i : ans)
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;   
    }

    return 0;
}