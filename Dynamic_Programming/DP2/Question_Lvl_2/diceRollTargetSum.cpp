#define MOD 1000000007

class Solution {
  public:
  
    int solveRec(int n, int target, int k)
    {
        if(n == 0) return target == 0 ? 1 : 0;
        
        int ans = 0;
        for(int i = 1; i <= k; i++) if(target - i >= 0) ans += solveRec(n - 1, target - i, k);
        
        return ans;
    }
    
    int solveRecMem(int n, int target, int k, vector<vector<int>> &dp)
    {
        if(n == 0) return target == 0 ? 1 : 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        for(int i = 1; i <= k; i++) if(target - i >= 0) ans = (ans + solveRecMem(n - 1, target - i, k, dp)) % MOD;
        
        return dp[n][target] = ans;
    }
  
    int solveTab(int n, int target, int k)
    {
        vector<vector<int>> dp(n + 2, vector<int>(target + 2, 0));
        
        dp[0][0] = 1;
        
        // n = n -> 0 ->   0 -> n
        // target = target -> 0    0 -> target;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                int ans = 0;
                for(int a = 1; a <= k; a++) if(j - a >= 0) ans = (ans + dp[i][j - a]) % MOD;
                dp[i + 1][j] = ans;
            }
        }
        return dp[n][target];
    }

    
    int solveTabOp(int n, int target, int k)
    {
        // vector<vector<int>> dp(n + 2, vector<int>(target + 2, 0));
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        
        curr[0] = 1;
        
        // n = n -> 0 ->   0 -> n
        // target = target -> 0    0 -> target;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                int ans = 0;
                for(int a = 1; a <= k; a++) if(j - a >= 0) ans = (ans + curr[j - a]) % MOD;
                next[j] = ans;
            }
            curr = next;
        }
        return next[target];
        
    }
  
    int noOfWays(int m, int n, int x) {
        // code here
        return solveTabOp(n, x, m);
        // return solveTab(n, x, m);
        // vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        // return solveRecMem(n, x, m, dp);
        
        // return solveRec(n, x, m);
    }
};