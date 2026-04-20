class Solution {
  public:
    
    int rec(int n)
    {
        if(n <= 1) return 1;
        
        return rec(n - 1) * n;
    }
  
    int recMemo(int n, vector<int> &dp)
    {
        if(n <= 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = recMemo(n - 1, dp) * n;
    }
    
    int solveTabu(int n)
    {
        if(n <= 1) return 1;
        
        vector<int> dp(n + 1, -1);
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] * i;
        
        return dp[n];
    }
  
    int factorial(int n) {
        // code here
        // vector<int> dp(n + 1, -1);
        
        // return recMemo(n, dp);
        // return solveTabu(n);
        // return rec(n);
        if(n <= 1) return 1;
        int a = 1;
        
        for(int i = 2; i <= n; i++) a = a * i;
        
        return a;
    }
};