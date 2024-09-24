#include <IOSTREAM>
#include <VECTOR>

using namespace std;

bool canJump(vector<int> &arr, int index)
{
    if(index >= arr.size()) return false;
    if(index == arr.size() - 1) return true;

    for(int i = 1; i <= arr[index]; i++)
    {
        bool tempAns = canJump(arr, index + i);

        if(tempAns) return true;
    }

    return false;
}

int minJumps(vector<int> &arr, int index, int jumps)
{
    if(index >= arr.size()) return INT_MAX;
    if(index == arr.size() - 1) return jumps;

    int tempJumps = INT_MAX;

    for(int i = 1; i <= arr[index]; i++)
    {
        int tempAns = minJumps(arr, index + i, jumps + 1);
        tempJumps = min(tempJumps, tempAns);
    }

    return tempJumps;
}

int main()
{
    vector<int> arr = {2, 3, 1, 1, 4};
    // vector<int> arr = {4, 3, 1, 1, 0, 0, 3};

    // if(canJump(arr, 0))
    // {
    //     cout << "It is possible to reach at the last index" << endl;
    // }
    // else
    // {
    //     cout << "Not possible to jump at last index" << endl;
    // }

    cout << minJumps(arr, 0, 0) << endl;

    return 0;
}