#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<double> getTime(vector<vector<int>> &arr)
{
    vector<double> ans(arr.size(), -1);
    stack<int> s;

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        while(!s.empty() && arr[i][1] <= arr[s.top()][1]) s.pop();
        while(!s.empty())
        {
            double time = (double)(arr[s.top()][0] - arr[i][0]) / (double)(arr[i][1] -  arr[s.top()][1]);
            if(time <= ans[s.top()] || ans[s.top()] == -1) 
            {
                ans[i] = time;
                break;
            }
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {3, 5},
        {7, 2},
        {12, 6},
        {13, 8},
        {18, 3}
    };

    vector<double> ans = getTime(arr);
    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}