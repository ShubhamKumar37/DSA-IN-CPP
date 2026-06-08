class Solution {
public:

    int solveRec(vector<int> &arr, int s, int e)
    {
        if(s > e) return 0;

        int ans = INT_MIN;
        for(int i = s; i <= e; i++) ans = max(ans, (arr[s - 1] * arr[i] * arr[e + 1]) + solveRec(arr, s, i - 1) + solveRec(arr, i + 1, e));
        
        return ans;
    }

    int solveRecMem(vector<int> &arr, int s, int e, vector<vector<int>> &dp)
    {
        if(s > e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MIN;
        for(int i = s; i <= e; i++) ans = max(ans, (arr[s - 1] * arr[i] * arr[e + 1]) + solveRecMem(arr, s, i - 1, dp) + solveRecMem(arr, i + 1, e, dp));

        return dp[s][e] = ans;
    }

    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int s = n - 2; s >= 1; s--)
        {
            for(int e = s; e <= n - 2; e++)
            {

                int ans = INT_MIN;
                for(int i = e; i >= s; i--) ans = max(ans, (arr[s - 1] * arr[i] * arr[e + 1]) + dp[s][i - 1] + dp[i + 1][e]);

                dp[s][e] = ans;
            }
        }

        return dp[1][n - 2];

    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return solveTab(nums);
        // return solveRecMem(nums, 1, n, dp);
        // return solveRec(nums, 1, n);
    }
};