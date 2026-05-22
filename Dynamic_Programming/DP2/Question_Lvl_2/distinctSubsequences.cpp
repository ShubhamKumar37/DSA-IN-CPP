class Solution {
public:
    int MOD = 1e9+7;
    int solveRec(string &s, string &t, int i, int j)
    {
        if(j == t.size()) return 1;
        if(i == s.size() && j != t.size()) return 0;

        int inc = s[i] == t[j] ? solveRec(s, t, i + 1, j + 1) : 0;
        int exc = solveRec(s, t, i + 1, j);

        return inc + exc;
    }
    int solveRecMem(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if(j == t.size()) return 1;
        if(i == s.size() && j != t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int inc = s[i] == t[j] ? solveRecMem(s, t, i + 1, j + 1, dp) : 0;
        int exc = solveRecMem(s, t, i + 1, j, dp);

        return dp[i][j] = inc + exc;
    }

    int solveTab(string &s, string &t)
    {
        if(s.size() < t.size()) return 0;
        
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i = 0; i <= n1; i++) dp[i][n2] = 1;

        for(int i = n1 - 1; i >= 0; i--)
        {
            for(int j = n2 - 1; j >= 0; j--)
            {
                int inc = s[i] == t[j] ? dp[i + 1][j + 1] : 0;
                int exc = dp[i + 1][j];

                dp[i][j] = (inc + exc) % MOD;
            }
        }

        return dp[0][0];
    }
    
    int solveTabOp(string &s, string &t)
    {
        if(s.size() < t.size()) return 0;
        
        int n1 = s.size();
        int n2 = t.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        vector<int> curr(n2 + 1, 0);
        vector<int> next(n2 + 1, 0);
        
        curr[n2] = 1;
        next[n2] = 1;

        // for(int i = 0; i <= n1; i++) dp[i][n2] = 1;

        for(int i = n1 - 1; i >= 0; i--)
        {
            for(int j = n2 - 1; j >= 0; j--)
            {
                int inc = s[i] == t[j] ? next[j + 1] : 0;
                int exc = next[j];

                curr[j] = (inc + exc) % MOD;
            }
            next = curr;
        }

        return curr[0];
    }

    int numDistinct(string s, string t) {

        return solveTabOp(s, t);
        // return solveTab(s, t);

        // int n1 = s.size();
        // int n2 = t.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        // return solveRecMem(s, t, 0, 0, dp);
        // return solveRec(s, t, 0, 0);
    }
};