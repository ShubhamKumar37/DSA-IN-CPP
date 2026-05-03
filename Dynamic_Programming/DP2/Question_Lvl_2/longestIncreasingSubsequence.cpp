class Solution {
public:
    
    int solveRec(vector<int> &arr, int ind, int prevInd)
    {
        if(ind >= arr.size()) return 0;

        int inc = prevInd == -1 || arr[prevInd] < arr[ind] ? 1 + solveRec(arr, ind + 1, ind) : 0;
        int exc = solveRec(arr, ind + 1, prevInd);

        return max(inc, exc);
    }
    
    int solveRecMemo(vector<int> &arr, int ind, int prevInd, vector<vector<int>> &dp)
    {
        if(ind >= arr.size()) return 0;

        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

        int inc = prevInd == -1 || arr[prevInd] < arr[ind] ? 1 + solveRecMemo(arr, ind + 1, ind, dp) : 0;
        int exc = solveRecMemo(arr, ind + 1, prevInd, dp);

        return dp[ind][prevInd + 1] = max(inc, exc);
    }

    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // int prevInd = -1;

        // curr -> 0 -> n;
        // prev -> -1 -> curr;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i - 1; j >= -1; j--)
            {
                int inc = j == -1 || arr[j] < arr[i] ? 1 + dp[i + 1][i + 1] : 0;
                int exc = dp[i + 1][j + 1];

                dp[i][j + 1] = max(inc, exc);

            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return solveTab(nums);
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        // return solveRecMemo(nums, 0, -1, dp);

        // return solveRec(nums, 0, -1);
    }
};