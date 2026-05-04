class Solution {
  public:
  
    int solveRec(vector<int> &arr, int sum, int index)
    {
        if(index >= arr.size()) return 0;
        if(sum == 0) return 1;
        
        int inc = 0;
        if(sum - arr[index] >= 0) inc = solveRec(arr, sum - arr[index], index);
        int exc = solveRec(arr, sum, index + 1);
        
        return inc + exc;
        
    }
    
    int solveRecMem(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
    {
        if(index >= arr.size()) return 0;
        if(sum == 0) return 1;
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int inc = 0;
        if(sum - arr[index] >= 0) inc = solveRecMem(arr, sum - arr[index], index, dp);
        int exc = solveRecMem(arr, sum, index + 1, dp);
        
        return dp[index][sum] = inc + exc;
        
    }
    
    int solveTab(vector<int> &arr, int sum)
    {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, 0));
        for(int i = 0; i <= arr.size(); i++) dp[i][0] = 1;
        
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            for(int j = 1; j <= sum; j++)
            {
                int inc = 0;
                if(j - arr[i] >= 0) inc = dp[i][j - arr[i]];
                int exc = dp[i + 1][j];
                
                dp[i][j] = inc + exc;
            }
        }
        
        return dp[0][sum];
        
    }
    
    int solveTabOp(vector<int> &arr, int sum)
    {
        vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);
        curr[0] = next[0] = 1;
        
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            for(int j = 1; j <= sum; j++)
            {
                int inc = 0;
                if(j - arr[i] >= 0) inc = curr[j - arr[i]];
                int exc = next[j];
                
                curr[j] = inc + exc;
            }
            next = curr;
        }
        
        return curr[sum];
        
    }
    
    int solveTabOp2(vector<int> &arr, int sum)
    {
        vector<int> curr(sum + 1, 0);
        curr[0] = 1;
        
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            for(int j = arr[i]; j <= sum; j++)
            {
                int inc = 0;
                if(j - arr[i] >= 0) inc = curr[j - arr[i]];
                int exc = curr[j];
                
                curr[j] = inc + exc;
            }
        }
        
        return curr[sum];
        
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        return solveTabOp2(coins, sum);
        // return solveTabOp(coins, sum);
        // return solveTab(coins, sum);
        // vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
        // return solveRecMem(coins, sum, 0, dp);
        // return solveRec(coins, sum, 0);
    }
};