class Solution {
public:

    bool solveRec(vector<int> &arr, int sum, int index)
    {
        if(index >= arr.size()) return sum == 0;
        if(sum == 0) return true;

        bool inc = sum - arr[index] >= 0 ? solveRec(arr, sum - arr[index], index + 1) : false;
        bool exc = solveRec(arr, sum, index + 1);

        return inc || exc;
    }

    bool solveRecMem(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
    {
        if(index >= arr.size()) return sum == 0;
        if(sum == 0) return true;

        if(dp[index][sum] != -1) return dp[index][sum];

        bool inc = sum - arr[index] >= 0 ? solveRecMem(arr, sum - arr[index], index + 1, dp) : false;
        bool exc = solveRecMem(arr, sum, index + 1, dp);

        return dp[index][sum] = inc || exc;
    }

    int solveTab(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));
        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool inc = j - arr[i] >= 0 ? dp[i + 1][j - arr[i]] : false;
                bool exc = dp[i + 1][j];

                dp[i][j] = inc || exc;
            }
        }

        return dp[0][sum];
    }
    int solveTabOp(vector<int> &arr, int sum)
    {
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));
        vector<int> prev(sum + 1, false);
        vector<int> curr(sum + 1, false);
        prev[0] = true;
        curr[0] = true;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool inc = j - arr[i] >= 0 ? prev[j - arr[i]] : false;
                bool exc = prev[j];

                curr[j] = inc || exc;
            }
            prev = curr;
        }

        return curr[sum];
    }
    int solveTabOp2(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<int> curr(sum + 1, false);
        curr[0] = true;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = sum; j >= 1; j--)
            {
                bool inc = j - arr[i] >= 0 ? curr[j - arr[i]] : false;
                bool exc = curr[j];

                curr[j] = inc || exc;
            }
        }

        return curr[sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums) sum += i;
        if(sum & 1) return false;
        sum = (sum >> 1);
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return solveTabOp2(nums, sum);
        // return solveTabOp(nums, sum);
        // return solveTab(nums, sum);
        // return solveRecMem(nums, sum, 0, dp);
        // return solveRec(nums, sum, 0);
    }
};