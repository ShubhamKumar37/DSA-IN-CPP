class Solution {
  public:
    
    bool solveRec(string &s, string &p, int ind1, int ind2)
    {
        if(ind1 == s.size() && p.size() == ind2) return true;
        if(ind1 != s.size() && p.size() == ind2) return false;
        if(ind1 == s.size() && p.size() != ind2)
        {
            while(ind2 < p.size() && p[ind2] == '*') ind2++;
            return ind2 == p.size();
        }
        
        if(s[ind1] == p[ind2] || p[ind2] == '?') return solveRec(s, p, ind1 + 1, ind2 + 1);
        if(p[ind2] == '*') return solveRec(s, p, ind1 + 1, ind2) || solveRec(s, p, ind1, ind2 + 1);
        return false;
    }
    
    bool solveRecMem(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 == s.size() && p.size() == ind2) return true;
        if(ind1 != s.size() && p.size() == ind2) return false;
        if(ind1 == s.size() && p.size() != ind2)
        {
            while(ind2 < p.size() && p[ind2] == '*') ind2++;
            return ind2 == p.size();
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        bool flag = false;
        if(s[ind1] == p[ind2] || p[ind2] == '?') flag = solveRecMem(s, p, ind1 + 1, ind2 + 1, dp);
        else if(p[ind2] == '*') flag = solveRecMem(s, p, ind1 + 1, ind2, dp) || solveRecMem(s, p, ind1, ind2 + 1, dp);
        else flag = false;
        
        return dp[ind1][ind2] = flag;
    }
    
    bool solveTab(string &s, string &p, int m, int n)
    {
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[m][n] = true;
        for(int ind2 = 0; ind2 < n ; ind2++)
        {
            int temp = ind2;
            while(ind2 < p.size() && p[temp] == '*') temp++;
            dp[m][ind2] = temp == p.size();
        }
        
        for(int ind1 = m - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n - 1; ind2 >= 0; ind2--)
            {
                bool flag = false;
                if(s[ind1] == p[ind2] || p[ind2] == '?') flag = dp[ind1 + 1][ind2 + 1];
                else if(p[ind2] == '*') flag = dp[ind1 + 1][ind2] || dp[ind1][ind2 + 1];
                else flag = false;
                
                dp[ind1][ind2] = flag;
            }
        }
        
        return dp[0][0];
    }
    
    bool solveTabOp(string &s, string &p, int m, int n)
    {
        vector<bool> curr(n + 1, false);
        vector<bool> next(n + 1, false);
        
        next[n] = true;
        for(int ind2 = 0; ind2 < n ; ind2++)
        {
            int temp = ind2;
            while(ind2 < p.size() && p[temp] == '*') temp++;
            next[ind2] = temp == p.size();
        }
        
        for(int ind1 = m - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n - 1; ind2 >= 0; ind2--)
            {
                bool flag = false;
                if(s[ind1] == p[ind2] || p[ind2] == '?') flag = next[ind2 + 1];
                else if(p[ind2] == '*') flag = next[ind2] || curr[ind2 + 1];
                else flag = false;
                
                curr[ind2] = flag;
            }
            next = curr;
        }
        
        return curr[0];
        
    }
  
    bool wildCard(string &txt, string &pat) {
        // code here
        int m = txt.size();
        int n = pat.size();
        return solveTabOp(txt, pat, m, n);
        // return solveTab(txt, pat, m, n);
        
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solveRecMem(txt, pat, 0, 0, dp);
        // return solveRec(txt, pat, 0, 0);
    }
};