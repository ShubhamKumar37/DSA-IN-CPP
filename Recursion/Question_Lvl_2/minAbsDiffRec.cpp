#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int getMinAbsDiff(vector<vector<int>> &arr, int target, int index)
{
    if(index >= arr.size()) return abs(target);

    int minAns = INT_MAX;

    for(int i = 0; i < arr[index].size(); i++)
    {
        int tempAns = getMinAbsDiff(arr, target - arr[index][i], index + 1);

        if(tempAns == 0) return tempAns;

        minAns = min(tempAns, minAns);
    }

    return minAns;
}

int main()
{
    vector<vector<int>> arr = {{4, 3, 5}, {6, 7, 8}, {3, 2, 5}};
    int target = 34;

    cout << "Minimum absolute difference between the sum of one element frome very row with target is " << getMinAbsDiff(arr, target, 0);


    return 0;
}