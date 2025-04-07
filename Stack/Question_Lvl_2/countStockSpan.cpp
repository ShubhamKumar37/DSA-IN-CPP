#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> getStockSpan(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans;

    s.push(-1);

    for(int i = 0; i < arr.size(); i++)
    {
        while(s.top() != -1 && arr[s.top()] <= arr[i]) s.pop();

        if(i == 0) ans.push_back(1);
        else if(s.top() == -1 && i > 1) ans.push_back(i + 1);
        else ans.push_back(i - s.top());

        s.push(i);
    }

    return ans;
}

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = getStockSpan(arr);

    for(auto i : ans) cout << i << " ";
    cout << endl;
    
    return 0;
}