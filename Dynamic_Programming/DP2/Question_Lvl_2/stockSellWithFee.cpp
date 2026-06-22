class Solution {
public:


    int solveRec(vector<int> &arr, int fee, int ind, bool buy)
    {
        if(ind == arr.size()) return 0;
        
        int profit = 0;
        if(buy)
        {
            int buySameDay = solveRec(arr, fee, ind + 1, false) - arr[ind];
            int notBuySameDay = solveRec(arr, fee, ind + 1, true);
            profit = max(buySameDay, notBuySameDay);
        }
        else
        {
            int sellSameDay = solveRec(arr, fee, ind + 1, true) + arr[ind] - fee;
            int notSellSameDay = solveRec(arr, fee, ind + 1, false);
            profit = max(sellSameDay, notSellSameDay);
        }

        return profit;
    }
    
    int solveRecMem(vector<int> &arr, int fee, int ind, bool buy, vector<vector<int>> &dp)
    {
        if(ind == arr.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy)
        {
            int buySameDay = solveRecMem(arr, fee, ind + 1, false, dp) - arr[ind];
            int notBuySameDay = solveRecMem(arr, fee, ind + 1, true, dp);
            profit = max(buySameDay, notBuySameDay);
        }
        else
        {
            int sellSameDay = solveRecMem(arr, fee, ind + 1, true, dp) + arr[ind] - fee;
            int notSellSameDay = solveRecMem(arr, fee, ind + 1, false, dp);
            profit = max(sellSameDay, notSellSameDay);
        }

        return dp[ind][buy] = profit;
    }

    int solveTab(vector<int> arr, int fee)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int buySameDay = dp[ind + 1][false] - arr[ind];
                    int notBuySameDay = dp[ind + 1][true];
                    profit = max(buySameDay, notBuySameDay);
                }
                else
                {
                    int sellSameDay = dp[ind + 1][true] + arr[ind] - fee;
                    int notSellSameDay = dp[ind + 1][false];
                    profit = max(sellSameDay, notSellSameDay);
                }

                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
    
    int solveTabOp(vector<int> arr, int fee)
    {
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int buySameDay = next[false] - arr[ind];
                    int notBuySameDay = next[true];
                    profit = max(buySameDay, notBuySameDay);
                }
                else
                {
                    int sellSameDay = next[true] + arr[ind] - fee;
                    int notSellSameDay = next[false];
                    profit = max(sellSameDay, notSellSameDay);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return curr[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));

        return solveTabOp(prices, fee);
        // return solveTab(prices, fee);
        // return solveRecMem(prices, fee, 0, true, dp);
        // return solveRec(prices, fee, 0, true);
    }
};