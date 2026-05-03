class Solution {
  public:
  
    int solveRec(int n, int k)
    {
        if(n == 1) return k;
        if(n == 2) return k * k;
        
        return (k - 1) * (solveRec(n - 2, k) + solveRec(n - 1, k));
    }
    
    int solveRecMem(int n, int k, vector<int> &dp)
    {
        if(n == 1) return k;
        if(n == 2) return k * k;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (k - 1) * (solveRecMem(n - 2, k, dp) + solveRecMem(n - 1, k, dp));
    }
    
    int solveTab(int n, int k)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = k;
        dp[2] = k * k;
        
        for(int i = 3; i <= n; i++) dp[i] = (k - 1) * (dp[i - 2] + dp[i - 1]);
        
        return dp[n];
    }
  
    int solveTabOp(int n, int k)
    {
        if(n == 1) return k;
        if(n == 2) return k * k;
        int a = k;
        int b = k * k;
        
        for(int i = 3; i <= n; i++)
        {
            int c = (k - 1) * (a + b);
            a = b;
            b = c;
            
        }
        
        return b;
        
    }
  
    int countWays(int n, int k) {
        // code here
        return solveTabOp(n, k);
        // return solveTab(n, k);
        // vector<int> dp(n + 1, -1);
        // return solveRecMem(n, k, dp);
        
        
        // return solveRec(n, k);
    }
};

class Solution {
  public:
    
    pair<int, int> solveRec(int n, int k)
    {
        if(n == 0) return {0, 0};
        if(n == 1) return {k, 0};
        if(n == 2) return {k, k * (k - 1)};
        
        pair<int, int> lastCall = solveRec(n - 1, k);
        int same = lastCall.second;
        int diff = (k - 1) * (lastCall.first + lastCall.second);
        
        return {same, diff};
        
    }
    
    pair<int,int> solveRecMem(int n, int k, vector<pair<int, int>> &dp)
    {
        if(n == 0) return {0, 0};
        if(n == 1) return {k, 0};
        if(n == 2) return {k, k * (k - 1)};
        if(dp[n].first != -1 && dp[n].second != -1) return dp[n];
        
        pair<int, int> lastCall = solveRecMem(n - 1, k, dp);
        int same = lastCall.second;
        int diff = (k - 1) * (lastCall.first + lastCall.second);
        
        return dp[n] = {same, diff};
    }

    int solveTab(int n, int k)
    {
        vector<pair<int, int>> dp(n + 1, {0, 0});
        
        dp[0] = {0, 0};
        dp[1] = {k, 0};
        dp[2] = {k, k * (k - 1)};
        
        for(int i = 3; i <= n; i++)
        {
            pair<int, int> lastCall = dp[i - 1];
            int same = lastCall.second;
            int diff = (k - 1) * (lastCall.first + lastCall.second);
            
            dp[i] = {same, diff};
        }
        
        return dp[n].first + dp[n].second;
    }
    
    int solveTabOp(int n, int k)
    {
        if(n == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k + k * (k - 1);
        
        pair<int, int> prev = {k, k * (k - 1)};
        
        
        for(int i = 3; i <= n; i++)
        {
            int same = prev.second;
            int diff = (k - 1) * (prev.first + prev.second);
            
            prev = {same, diff};
        }
        
        return prev.first + prev.second;
    }
  
    int countWays(int n, int k) {
        // code here
        return solveTabOp(n, k);
        
        // vector<pair<int, int>> dp(n + 1, {-1, -1});
        
        // pair<int, int> ans = solveRecMem(n, k, dp);
        // pair<int, int> ans = solveRec(n, k);
        // return ans.first + ans.second;
         
    }
};