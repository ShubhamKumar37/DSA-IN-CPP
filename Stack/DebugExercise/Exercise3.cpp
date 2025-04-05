#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int> &nums)
{
    stack<int> s;
    vector<int> result(nums.size(), -1);
    s.push(-1);

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && nums[i] > s.top())
        {
            s.pop();
        }
        result[i] = s.top();
        s.push(nums[i]);
    }

    return result;
}

int main()
{
    vector<int> nums = {2, 1, 3, 4, 5};
    vector<int> result = nextGreaterElement(nums);
    for (int num : result)
        cout << num << " ";
    return 0;
}