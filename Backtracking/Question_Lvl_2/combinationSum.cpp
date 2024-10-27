#include<IOSTREAM>  
#include<VECTOR>

using namespace std;


void findAllPossible(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int &target, int index)
{
    if(index >= arr.size() || target < 0) return ;

    if(target == 0) 
    {
        ans.push_back(temp);
        return ;
    }

    temp.push_back(arr[index]);
    target -= arr[index];
    findAllPossible(arr, ans, temp, target, index);
    temp.pop_back();
    target += arr[index];


    findAllPossible(arr, ans, temp, target, index + 1);
}

int main()
{
    vector<int> arr = {4, 6, 7, 8};
    vector<int> temp;
    int target = 12;

    vector<vector<int>> ans;
    findAllPossible(arr, ans, temp, target, 0);

    cout << "-----All the pair are given below-----" << endl;
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