// 84. Largest Rectangle in Histogram

#include <iostream>
#include <vector>
#include <stack>

    using namespace std;

vector<int> getLeftSmall(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;

    s.push(-1);
    for (int i = 0; i < arr.size(); i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> getRightSmall(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;

    s.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        ans[i] = s.top() == -1 ? arr.size() : s.top();
        s.push(i);
    }

    return ans;
}

int largestArea(vector<int> &arr)
{
    int ans = INT_MIN;
    vector<int> leftSmall = getLeftSmall(arr);
    vector<int> rightSmall = getRightSmall(arr);

    for (int i = 0; i < arr.size(); i++)
        ans = max(ans, (rightSmall[i] - leftSmall[i] - 1) * arr[i]);

    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    cout << "Area of largest rectangle in histogram = " << largestArea(arr) << endl;

    return 0;
}