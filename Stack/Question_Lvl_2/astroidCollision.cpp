#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> getAfterCollision(vector<int> &arr)
{
    stack<int> s;

    for(auto i : arr)
    {
        if(i == 0) continue;
        else
        {
            if(i < 0) 
            {
                // Current element will colloid until the stack is empty or it get explode itself
                while(!s.empty() && s.top() > 0 && s.top() < abs(i)) s.pop();

                // Current element will explode with s.top() if both are equal 
                if(!s.empty() && s.top() > 0 && s.top() == abs(i)) s.pop();

                // We can only current element only if the stack is empty - means all element exploded
                // Or the s.top() is also going in same direction in -ve
                else if(s.empty() || s.top() < 0) s.push(i);
            }
            else s.push(i);
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;
    while (!s.empty())
    {
        ans[i--] = s.top();
        s.pop();
    }

    return ans;
}

int main()
{
    // vector<int> arr = {-2,2,1,-2};
    vector<int> arr = {4, -3, 7, 2, 3, -4, 8, -9};
    vector<int> ans = getAfterCollision(arr);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}