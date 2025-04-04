// 2104. Sum of Subarray Ranges

class Solution {
    public:
        void printArr(vector<int> &arr)
        {
            for(auto i : arr) cout << i << " ";
            cout << endl;
        }
    
        vector<int> getLeftSmall(vector<int> &arr)
        {
            vector<int> ans(arr.size());
            stack<int> s;
            s.push(-1);
    
            for(int i = 0; i < arr.size(); i++)
            {
                while(s.top() != -1 && arr[s.top()] > arr[i]) s.pop();
                ans[i] = s.top();
                s.push(i);
            }
            // printArr(ans);
            return ans;
        }
        vector<int> getRightSmall(vector<int> &arr)
        {
            vector<int> ans(arr.size());
            stack<int> s;
            s.push(-1);
    
            for(int i = arr.size() - 1; i >= 0; i--)
            {
                while(s.top() != -1 && arr[s.top()] >= arr[i]) s.pop();
                ans[i] = s.top() == -1 ? arr.size() : s.top();
                s.push(i);
            }
    
            // printArr(ans);
            return ans;
        }
    
        vector<int> getRightLarge(vector<int> &arr)
        {
            vector<int> ans(arr.size());
            stack<int> s;
            s.push(-1);
    
            for(int i = arr.size() - 1; i >= 0; i--)
            {
                while(s.top() != -1 && arr[s.top()] <= arr[i]) s.pop();
                ans[i] = s.top() == -1 ? arr.size() : s.top();
                s.push(i);
            }
    
            // printArr(ans);
            return ans;
        }
    
        vector<int> getLeftLarge(vector<int> &arr)
        {
            vector<int> ans(arr.size());
            stack<int> s;
            s.push(-1);
    
            for(int i = 0; i < arr.size(); i++)
            {
                while(s.top() != -1 && arr[s.top()] < arr[i]) s.pop();
                ans[i] = s.top();
                s.push(i);
            }
    
            // printArr(ans);
            return ans;
        }
    
        long long subArrayRanges(vector<int>& nums) {
            long long ans = 0;
            long long small = 0;
            long long large = 0;
            vector<int> leftSmall = getLeftSmall(nums);
            vector<int> rightSmall = getRightSmall(nums);
            vector<int> leftLarge = getLeftLarge(nums);
            vector<int> rightLarge = getRightLarge(nums);
    
            for(int i = 0; i < leftLarge.size(); i++)
            {
                long long count = (i - leftLarge[i]) * (rightLarge[i] - i);
                ans += (long long)(count * nums[i]);
            }
    
    
            for(int i = 0; i < leftSmall.size(); i++)
            {
                long long count = (i - leftSmall[i]) * (rightSmall[i] - i);
                ans -= (count * nums[i]);
            }
            return ans;
            // return large - small;
        }
    };