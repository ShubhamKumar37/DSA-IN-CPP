#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxWindow(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++)
    {
        // First Window
        if(i < k) while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        else 
        {
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front() <= (i - k)) dq.pop_front();
            while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        }
        dq.push_back(i);
    }

    if(!dq.empty()) ans.push_back(arr[dq.front()]);
    return ans;
}

int main()
{
    int k = 3;
    vector<int> arr = {1,3,1,2,0,5};
    vector<int> ans = maxWindow(arr, k);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}