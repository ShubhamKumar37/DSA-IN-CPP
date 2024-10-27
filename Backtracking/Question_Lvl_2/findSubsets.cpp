#include<IOSTREAM>
#include<VECTOR>

using namespace std;

void getSubset(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    ans.push_back(temp);

    for(int i = index; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        getSubset(arr, temp, ans, i + 1);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {2, 3, 4};
    vector<int> temp;
    vector<vector<int>> ans;

    getSubset(arr, temp, ans, 0);

    cout << endl;
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}