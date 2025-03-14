#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> getPrevSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    stack<int> s;
    s.push(-1);

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        while(s.top() >= arr[i]) s.pop();
        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}

int main()
{
    // vector<int> arr = {3, 7, 4, 1, 2, 6, 4, 8};
    vector<int> arr = {3, 2, 6, 4, 2};
    vector<int> ans = getPrevSmallerElement(arr);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}