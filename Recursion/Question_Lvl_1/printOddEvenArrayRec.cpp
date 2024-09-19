#include<IOSTREAM>
#include<vector>

using namespace std;

void printOdd(vector<int> &arr, int index, vector<int> &ans)
{
    if(index == arr.size()) return ;

    if(arr[index] & 1) ans.push_back(arr[index]);

    printOdd(arr, index + 1, ans);
}

void printEven(vector<int> &arr, int index, vector<int> &ans)
{
    if(index == arr.size()) return ;

    if((arr[index] & 1) == 0) ans.push_back(arr[index]);

    printEven(arr, index + 1, ans);
}

void printVec(vector<int> &arr)
{
    for(auto i : arr) cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 5, 4, 3, 3, 2, 5, 6};
    vector<int> ans;

    printOdd(arr, 0, ans); 

    printVec(ans);
    ans.erase(ans.begin(), ans.end());

    printEven(arr, 0, ans);
    printVec(ans);


    return 0;
}