#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std;

void findAllPossible(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int &target, int index)
{
    // if(index >= arr.size()) 
    // {
    //     ans.push_back(temp);
    //     return;
    // }
    if(target == 0)
    {
        ans.push_back(temp);
        return ;
    }
    if(index >= arr.size() || target < 0) return ;

    for(int i = index; i < arr.size(); i++)
    {
        if(i != index && arr[i] == arr[i - 1]) continue;
        
        target -= arr[i];
        temp.push_back(arr[i]);
        findAllPossible(arr, ans, temp, target, i + 1);
        target += arr[i];
        temp.pop_back();

    }
}

int main()
{
    vector<int> arr = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> ans;
    vector<int> temp;

    sort(arr.begin(), arr.end());

    findAllPossible(arr, ans, temp, target, 0);

    cout << "-----Printing all possible solution-----" << endl;

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