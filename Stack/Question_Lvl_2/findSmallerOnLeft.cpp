#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> getSmaller(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);

    for(int i = 0; i < arr.size(); i++)
    {
        while(s.top() >= arr[i]) s.pop();
        int ele = arr[i];
        arr[i] = s.top();
        s.push(ele);
    }

    return arr;
}

int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    vector<int> ans = getSmaller(arr);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}