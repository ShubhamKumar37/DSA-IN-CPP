// 907. Sum of Subarray Minimums

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#ifndef MOD

#define MOD 1000000007

#endif

using namespace std;

vector<int> getLeftPrev(vector<int> &arr)
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

vector<int> getRightPrev(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] > arr[i])
            s.pop();
        ans[i] = s.top() == -1 ? arr.size() : s.top();
        s.push(i);
    }
    return ans;
}

int getMinimumSubArraySum(vector<int> &arr)
{
    vector<int> leftPrev = getLeftPrev(arr);
    vector<int> rightPrev = getRightPrev(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        int minTimes = ((i - leftPrev[i]) * (rightPrev[i] - i)) % MOD;
        ans = ans + (arr[i] * minTimes) % MOD;
    }

    return ans;
}

int main()
{

    return 0;
}