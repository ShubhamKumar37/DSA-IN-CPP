class Solution {
  public:
    
    int solveRec(string &s, int i, int j)
    {
        if(i >= j) return 0;
        
        if(s[i] != s[j])
        {
            return 1 + min(solveRec(s, i + 1, j), solveRec(s, i, j - 1));
        }
        else return solveRec(s, i + 1, j - 1);
    }

    int solveRecMem(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] != s[j])
        {
            return dp[i][j] = 1 + min(solveRecMem(s, i + 1, j, dp), solveRecMem(s, i, j - 1, dp));
        }
        else return dp[i][j] = solveRecMem(s, i + 1, j - 1, dp);
    }

    int solveTab(string &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = 0; j < n; j++)
            {
                if(i >= j) continue;
                if(s[i] != s[j])
                {
                    dp[i][j + 1] = 1 + min(dp[i + 1][j + 1], dp[i][j]);
                }
                else dp[i][j + 1] = dp[i + 1][j];
            }
        }

        return dp[0][n];
    }

    int solveTabOp(string &s)
    {
        int n = s.size();
        vector<int> curr(n + 2, 0);
        vector<int> next(n + 2, 0);

        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = 0; j < n; j++)
            {
                if(i >= j) continue;
                if(s[i] != s[j])
                {
                    curr[j + 1] = 1 + min(next[j + 1], curr[j]);
                }
                else curr[j + 1] = next[j];
            }
            next = curr;
        }

        return curr[n];

    }
  
    int findMinInsertions(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return solveTabOp(s);
        // return solveTab(s);
        // return solveRecMem(s, 0, n - 1, dp);

        // return solveRec(s, 0, n - 1);
    }
};