class Solution {
public:

    int solveRec(vector<int> &arr, int amount)
    {
        if(amount == 0) return 0;

        int currAns = INT_MAX;

        for(int i = 0; i < arr.size(); i++)
        {
            if(amount - arr[i] >= 0)
            {
                int temp = solveRec(arr, amount - arr[i]);
                if(temp != INT_MAX) currAns = min(currAns, temp + 1);
            }
        }

        return currAns;
    }
    int solveRecMem(vector<int> &arr, int amount, vector<int> &dp)
    {
        if(amount == 0) return 0;
        if(dp[amount] != INT_MAX) return dp[amount];

        int currAns = INT_MAX;

        for(int i = 0; i < arr.size(); i++)
        {
            if(amount - arr[i] >= 0)
            {
                int temp = solveRecMem(arr, amount - arr[i], dp);
                if(temp != INT_MAX) currAns = min(currAns, temp + 1);
            }
        }

        return dp[amount] = currAns;
    }

    int solveTab(vector<int> &arr, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            int currAns = INT_MAX;
            for(int j = 0; j < arr.size(); j++)
            {
                if(i - arr[j] >= 0)
                {
                    int temp = dp[i - arr[j]];
                    if(temp != INT_MAX) currAns = min(currAns, temp + 1);
                }
            }
           dp[i] = currAns;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveTab(coins, amount);

        // vector<int> dp(amount + 1, INT_MAX);
        // int ans = solveRecMem(coins, amount, dp);

        // int ans = solveRec(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};