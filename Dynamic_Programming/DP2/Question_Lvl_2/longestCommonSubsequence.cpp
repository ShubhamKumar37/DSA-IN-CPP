class Solution {
  public:
    int solveRec(string &str1, string &str2, int ind1, int ind2)
    {
        if(ind1 >= str1.size() || ind2 >= str2.size()) return 0;
        
        int inc = 0;
        int exc1 = 0;
        int exc2 = 0;
        
        if(str1[ind1] == str2[ind2]) inc = 1 + solveRec(str1, str2, ind1 + 1, ind2 + 1);
        else
        {
            exc1 = solveRec(str1, str2, ind1 + 1, ind2);
            exc2 = solveRec(str1, str2, ind1, ind2 + 1);
        }
        
        return max(inc, max(exc1, exc2));
    }
    
    int solveRecMem(string &str1, string &str2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 >= str1.size() || ind2 >= str2.size()) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        int inc = 0;
        int exc1 = 0;
        int exc2 = 0;
        
        if(str1[ind1] == str2[ind2]) inc = 1 + solveRecMem(str1, str2, ind1 + 1, ind2 + 1, dp);
        else
        {
            exc1 = solveRecMem(str1, str2, ind1 + 1, ind2, dp);
            exc2 = solveRecMem(str1, str2, ind1, ind2 + 1, dp);
        }
        
        return dp[ind1][ind2] = max(inc, max(exc1, exc2));
    }
  
    int solveTab(string &str1, string &str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for(int i = n1 - 1; i >= 0; i--)
        {
            for(int j = n2 - 1; j >= 0; j--)
            {
                int inc = 0;
                int exc1 = 0;
                int exc2 = 0;
                
                if(str1[i] == str2[j]) inc = 1 + dp[i + 1][j + 1];
                else
                {
                    exc1 = dp[i + 1][j];
                    exc2 = dp[i][j + 1];
                }
                
                dp[i][j] = max(inc, max(exc1, exc2));
            }
        }
        
        return dp[0][0];
        
    }
    
    int solveTabOp(string &str1, string &str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        vector<int> curr(n2 + 1, 0);
        vector<int> next(n2 + 1, 0);
        
        for(int i = n1 - 1; i >= 0; i--)
        {
            for(int j = n2 - 1; j >= 0; j--)
            {
                int inc = 0;
                int exc1 = 0;
                int exc2 = 0;
                
                if(str1[i] == str2[j]) inc = 1 + next[j + 1];
                else
                {
                    exc1 = next[j];
                    exc2 = curr[j + 1];
                }
                
                curr[j] = max(inc, max(exc1, exc2));
            }
            next = curr;
        }
        
        return curr[0];
        
    }
  
    int lcs(string &s1, string &s2) {
        // code here
        return solveTabOp(s1, s2);
        // return solveTab(s1, s2);
        // int n1 = s1.size();
        // int n2 = s2.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        // return solveRecMem(s1, s2, 0, 0, dp);
        // return solveRec(s1, s2, 0, 0);
    }
};
    