#include<IOSTREAM>
#include<VECTOR>

using namespace std;

void minSum1(vector<vector<int>> &arr, int index, int curr, int sum, int &ans)
{
    if(index > arr.size()) return ;
    if(index == arr.size()) 
    {
        ans = min(ans, sum);
        return ;
    }

    if(curr == arr[index].size()) return ;
    minSum1(arr, index + 1, curr, sum + arr[index][curr], ans);

    if(curr + 1 == arr[index].size()) return ;
    minSum1(arr, index + 1, curr + 1, sum + arr[index][curr + 1], ans);
}

int minSum2(vector<vector<int>> &arr, int index, int curr)
{
    if(index == arr.size()) return 0;

    int currIndexValue = arr[index][curr] + minSum2(arr, index + 1, curr);
    int nextIndexValue = arr[index][curr] + minSum2(arr, index + 1, curr + 1);

    return min(currIndexValue, nextIndexValue);
}

int main()
{
    vector<vector<int>> arr = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    
    // int ans = INT_MAX;
    // minSum1(arr, 0, 0, 0, ans);

    // cout << "Minimum sum = " << ans << endl;
    cout << "Minimum sum = " << minSum2(arr, 0, 0) << endl;

    return 0;
}