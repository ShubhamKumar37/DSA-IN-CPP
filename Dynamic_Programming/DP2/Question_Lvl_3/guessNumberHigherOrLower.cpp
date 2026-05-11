class Solution {
public:
    int solveRec(int s, int e)
    {
        if(s >= e) return 0;
         
        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int lowRange = i + solveRec(s, i - 1);
            int highRange = i + solveRec(i + 1, e);
            ans = min(ans, max(lowRange, highRange));
        }

        return ans;
    }
    
    int solveRecMem(int s, int e, vector<vector<int>> &dp)
    {
        if(s >= e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int lowRange = i + solveRecMem(s, i - 1, dp);
            int highRange = i + solveRecMem(i + 1, e, dp);
            ans = min(ans, max(lowRange, highRange));
        }

        return dp[s][e] = ans;
    }

    int solveTab(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int s = n; s >= 1; s--)
        {
            for(int e = s; e <= n; e++)
            {
                if(s >= e) continue;   

                int ans = INT_MAX;
                for(int i = s; i < e; i++)
                {
                    int lowRange = i + dp[s][i - 1];
                    int highRange = i + dp[i + 1][e];
                    ans = min(ans, max(lowRange, highRange));
                }

                dp[s][e] = ans;

            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveTab(n);
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // return solveRecMem(1, n, dp);
        // return solveRec(1, n);
    }
};