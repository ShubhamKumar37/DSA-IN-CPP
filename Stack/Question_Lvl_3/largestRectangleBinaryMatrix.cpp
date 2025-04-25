// 85. Maximal Rectangle

class Solution {
    public:
    
        vector<int> getLeftSmall(vector<int> &arr)
        {
            stack<int> s;
            s.push(-1);
            vector<int> ans;
    
            for(int i = 0; i < arr.size(); i++)
            {
                while(s.top() != -1 && arr[i] <= arr[s.top()]) s.pop();
                int val = s.top();
                ans.push_back(val);
                s.push(i);
            }
    
            return ans;
        }
    
        vector<int> getRightSmall(vector<int> &arr)
        {
            stack<int> s;
            s.push(-1);
            vector<int> ans(arr.size());
    
            for(int i = arr.size() - 1; i >= 0; i--)
            {
                while(s.top() != -1 && arr[i] <= arr[s.top()]) s.pop(); 
                int val = s.top() == -1 ? arr.size() : s.top();
                ans[i] = val;
                s.push(i);
            }
    
            return ans;
        }
    
        int getMaxRectangle(vector<int> &arr)
        {
            int ans = 0;
            vector<int> leftSmall = getLeftSmall(arr);
            vector<int> rightSmall = getRightSmall(arr);
    
            for(int i = 0; i < leftSmall.size(); i++) ans = max(ans, ((rightSmall[i] - leftSmall[i] - 1) * arr[i]));
            return ans;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            int ans = 0;
            vector<vector<int>> tempMat;
    
            for(int i = 0; i < matrix.size(); i++)
            {
                vector<int> temp;
                for(int j = 0; j < matrix[i].size(); j++)temp.push_back((int)(matrix[i][j] - '0'));
                tempMat.push_back(temp);
            }
    
            ans = max(ans, getMaxRectangle(tempMat[0]));
    
            for(int i = 1; i < tempMat.size(); i++)
            {
                for(int j = 0; j < tempMat[i].size(); j++) if(tempMat[i][j] != 0) tempMat[i][j] = tempMat[i][j] + tempMat[i - 1][j];
                ans = max(ans, getMaxRectangle(tempMat[i]));
            }
    
            return ans;
        }
    };