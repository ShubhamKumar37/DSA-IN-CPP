class Solution {
  public:
  
    int solveRec(vector<int> &val, vector<int> &wt, int W, int ind)
    {
        if(ind < 0) return 0;
        
        int inc = W - wt[ind] >= 0 ? val[ind] + solveRec(val, wt, W - wt[ind], ind - 1) : 0;
        int exc = solveRec(val, wt, W, ind - 1);
        return max(inc, exc);
    }
    int solveRecMem(vector<int> &val, vector<int> &wt, int W, int ind, vector<vector<int>> &dp)
    {
        if(ind < 0) return 0;
        if(dp[W][ind] != -1) return dp[W][ind];
        
        int inc = W - wt[ind] >= 0 ? val[ind] + solveRecMem(val, wt, W - wt[ind], ind - 1, dp) : 0;
        int exc = solveRecMem(val, wt, W, ind - 1, dp);
        return dp[W][ind] = max(inc, exc);
    }
  
    int solveTab(vector<int> &val, vector<int> &wt, int W)
    {
        int n = val.size();
        // vector<vector<int>> dp(W + 1, vector<int>(n + 2, 0));
        vector<vector<int>> dp(n + 2, vector<int>(W + 1));
        // cout << dp[1][-1] << endl;
        // ind = n - 1 -> -1;
        // W = W -> 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                int inc = j - wt[i] >= 0 ? val[i] + dp[i][j - wt[i]] : 0;
                int exc = dp[i][j];
                // cout << dp[j][i - 1] << " i = " << i - 1 << endl;
                
                dp[i + 1][j] = max(inc, exc);
            }
            
        }
        
        return dp[n][W];
    }
  
    int solveTabOp(vector<int> &val, vector<int> &wt, int W)
    {
        int n = val.size();
        vector<int> arr1(W + 1, 0);
        vector<int> arr2(W + 1, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                int inc = j - wt[i] >= 0 ? val[i] + arr1[j - wt[i]] : 0;
                int exc = arr1[j];
                
                arr2[j] = max(inc, exc);
            }
            arr1 = arr2;
        }

        return arr2[W];
    }
    int solveTabOp2(vector<int> &val, vector<int> &wt, int W)
    {
        int n = val.size();
        vector<int> arr1(W + 1, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = W; j >= 0; j--)
            {
                int inc = j - wt[i] >= 0 ? val[i] + arr1[j - wt[i]] : 0;
                int exc = arr1[j];
                
                arr1[j] = max(inc, exc);
            }
        }

        return arr1[W];
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        return solveTabOp2(val, wt, W);
        // return solveTabOp(val, wt, W);
        // return solveTab(val, wt, W);
        
        // int n = val.size();
        // vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        
        // return solveRecMem(val, wt, W, val.size() - 1, dp);
        // return solveRec(val, wt, W, val.size() - 1);
    }
};