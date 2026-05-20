class Solution {

  public:
  
    int solveRec(string &s1, string &s2, int &x, int &y, int ind1, int ind2)
    {
        if(ind1 == s1.size() && ind2 == s2.size()) return 0;
        if(ind1 != s1.size() && ind2 == s2.size()) return x * (s1.size() - ind1);
        if(ind1 == s1.size() && ind2 != s2.size()) return y * (s2.size() - ind2);
        
        if(s1[ind1] == s2[ind2]) return solveRec(s1, s2, x, y, ind1 + 1, ind2 + 1);
        
        int inc1 = x + solveRec(s1, s2, x, y, ind1 + 1, ind2);
        int inc2 = y + solveRec(s1, s2, x, y, ind1, ind2 + 1);
        int exc = x + y + solveRec(s1, s2, x, y, ind1 + 1, ind2 + 1);
        
        return min(inc1, min(inc2, exc));
        
    }
    
    int solveRecMem(string &s1, string &s2, int &x, int &y, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 == s1.size() && ind2 == s2.size()) return 0;
        if(ind1 != s1.size() && ind2 == s2.size()) return x * (s1.size() - ind1);
        if(ind1 == s1.size() && ind2 != s2.size()) return y * (s2.size() - ind2);
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) return solveRecMem(s1, s2, x, y, ind1 + 1, ind2 + 1, dp);
        
        int inc1 = x + solveRecMem(s1, s2, x, y, ind1 + 1, ind2, dp);
        int inc2 = y + solveRecMem(s1, s2, x, y, ind1, ind2 + 1, dp);
        int exc = x + y + solveRecMem(s1, s2, x, y, ind1 + 1, ind2 + 1, dp);
        
        return dp[ind1][ind2] = min(inc1, min(inc2, exc));
        
    }
  
    int solveTab(string &s1, string &s2, int x, int y, int n1, int n2)
    {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for(int i = 0; i < n1; i++) dp[i][n2] = x * (n1 - i);
        for(int i = 0; i < n2; i++) dp[n1][i] = y * (n2 - i);
        
        for(int ind1 = n1 - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
            {
                int temp = INT_MAX;
                if(s1[ind1] == s2[ind2]) temp = dp[ind1 + 1][ind2 + 1];
                
                int inc1 = x + dp[ind1 + 1][ind2];
                int inc2 = y + dp[ind1][ind2 + 1];
                int exc = x + y + dp[ind1 + 1][ind2 + 1];
                
                dp[ind1][ind2] = min(min(inc1, temp), min(inc2, exc));
                
            }
        }
        
        return dp[0][0];
        
    }
    
    int solveTabOp(string &s1, string &s2, int x, int y, int n1, int n2)
    {
        vector<int> curr(n2 + 1, 0);
        vector<int> next(n2 + 1, 0);
        
        for(int i = 0; i < n2; i++) next[i] = y * (n2 - i);
        
        for(int ind1 = n1 - 1; ind1 >= 0; ind1--)
        {
            curr[n2] = x * (n1 - ind1);
            
            for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
            {
                int temp = INT_MAX;
                if(s1[ind1] == s2[ind2]) temp = next[ind2 + 1];
                
                int inc1 = x + next[ind2];
                int inc2 = y + curr[ind2 + 1];
                int exc = x + y + next[ind2 + 1];
                
                curr[ind2] = min(min(inc1, temp), min(inc2, exc));
                
            }
            next = curr;
        }
        
        return curr[0];
    }
  
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n1 = x.size();
        int n2 = y.size();
        
        return solveTabOp(x, y, costX, costY, n1, n2);
        // return solveTab(x, y, costX, costY, n1, n2);
        
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        // return solveRecMem(x, y, costX, costY, 0, 0, dp);
        // return solveRec(x, y, costX, costY, 0, 0);
    }
};
