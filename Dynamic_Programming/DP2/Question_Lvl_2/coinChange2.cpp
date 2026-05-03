class Solution {
public:

    int solveRec(vector<int> &arr, int amount, int index)
    {
        if(index >= arr.size() || amount < 0) return 0;
        if(amount == 0) return 1;

        int inc = amount - arr[index] >= 0 ? solveRec(arr, amount - arr[index], index) : 0;
        int exc = solveRec(arr, amount, index + 1);

        return inc + exc;
    }

    int solveRecMem(vector<int> &arr, int amount, int index, vector<vector<int>> &dp)
    {
        if(index >= arr.size() || amount < 0) return 0;
        if(amount == 0) return 1;
        if(dp[amount][index] != -1) return dp[amount][index];

        int inc = amount - arr[index] >= 0 ? solveRecMem(arr, amount - arr[index], index, dp) : 0;
        int exc = solveRecMem(arr, amount, index - 1, dp);

        return dp[amount][index] = inc + exc;
    }

    int solveTab(vector<int> &arr, int amount)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int j = 0; j < n; j++)
        {
            for(int i = 1; i <= amount; i++)
            {
                long long inc = i - arr[j] >= 0 ? dp[j + 1][i - arr[j]] : 0;
                long long exc = dp[j][i];

                dp[j + 1][i] = inc + exc;
            }
        }

        return dp[n][amount];

    }

    int solveTabOp(vector<int> &arr, int amount)
    {
        int n = arr.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        prev[0] = 1;
        curr[0] = 1;
        
        for(int j = 0; j < n; j++)
        {
            for(int i = 1; i <= amount; i++)
            {
                long long inc = i - arr[j] >= 0 ?  curr[i - arr[j]] : 0;
                long long exc = prev[i];

                curr[i] = inc + exc;
            }
            prev = curr;
        }

        return curr[amount];

    }
    int solveTabOp2(vector<int> &arr, int amount)
    {
        int n = arr.size();
        vector<int> curr(amount + 1, 0);
        curr[0] = 1;
        
        for(int j = 0; j < n; j++) for(int i = arr[j]; i <= amount; i++) curr[i] += (long long)(curr[i - arr[j]]);

        return curr[amount];

    }

    int change(int amount, vector<int>& coins) {
        return solveTabOp2(coins, amount);
        // return solveTabOp(coins, amount);
        // return solveTab(coins, amount);
        // int n = coins.size();
        // vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
        // return solveRecMem(coins, amount, n - 1, dp);
        // return solveRec(coins, amount, 0);
    }
};