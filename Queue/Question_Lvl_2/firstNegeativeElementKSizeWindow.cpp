#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> findNegative(vector<int> &arr, int k)
{
    vector<int> ans;
    queue<int> q;

    for(int i = 0; i < arr.size(); i++)
    {
        if(i < k)
        {
            if(arr[i] < 0) q.push(i);
        }
        else
        {
            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
            
            while(!q.empty() && q.front() <= (i - k)) q.pop();
            if(arr[i] < 0) q.push(i);
        }
    }
    if(q.empty()) ans.push_back(0);
    else ans.push_back(arr[q.front()]);

    return ans;
}

int main()
{ 
    int k = 2;
    vector<int> arr = {-8, 2, 3, -6, 10};
    vector<int> ans = findNegative(arr, k);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}