// 739. Daily Temperatures

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> ans(temperatures.size(), -1);
            stack<int> s;
    
            s.push(-1);
    
            for(int i = temperatures.size() - 1; i >= 0; i--)
            {
                while(s.top() != -1 && temperatures[i] >= temperatures[s.top()]) s.pop();
                ans[i] = s.top() == -1 ? 0 : s.top() - i;
                s.push(i);
            }
    
            return ans;
        }
    };