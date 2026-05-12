class Solution {
public:

    bool solveRec(string &s, string &p, int ind1, int ind2)
    {
        if(ind1 == s.size() && ind2 == p.size()) return true;
        if(ind1 != s.size() && ind2 == p.size()) return false;
        if(ind1 == s.size() && ind2 != p.size())
        {
            while(ind2 < p.size() && ('*' == p[ind2] || (ind2 + 1 < p.size() && '*' == p[ind2 + 1]))) ind2++;
            return ind2 == p.size();
        }

        if(ind2 + 1 < p.size() && p[ind2 + 1] == '*')
        {
            int exc = solveRec(s, p, ind1, ind2 + 2);
            int inc = s[ind1] == p[ind2] || p[ind2] == '.' ? solveRec(s, p, ind1 + 1, ind2) : false;
            return inc || exc;
        }
        else if(s[ind1] == p[ind2] || p[ind2] == '.') return solveRec(s, p, ind1 + 1, ind2 + 1);

        return false;
    }

    bool solveRecMem(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 == s.size() && ind2 == p.size()) return true;
        if(ind1 != s.size() && ind2 == p.size()) return false;
        if(ind1 == s.size() && ind2 != p.size())
        {
            while(ind2 < p.size() && ((ind2 + 1 < p.size() && '*' == p[ind2 + 1]))) ind2 += 2;
            return ind2 == p.size();
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(ind2 + 1 < p.size() && p[ind2 + 1] == '*')
        {
            int exc = solveRecMem(s, p, ind1, ind2 + 2, dp);
            int inc = s[ind1] == p[ind2] || p[ind2] == '.' ? solveRecMem(s, p, ind1 + 1, ind2, dp) : false;
            return dp[ind1][ind2] = inc || exc;
        }
        else if(s[ind1] == p[ind2] || p[ind2] == '.') return dp[ind1][ind2] = solveRecMem(s, p, ind1 + 1, ind2 + 1, dp);

        return dp[ind1][ind2] = false;
        
    }

    bool solveTab(string &s, string &p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 2, vector<bool>(n + 2, false));
        dp[m][n] = true;

        for(int ind2 = 0; ind2 < n + 1; ind2++)
        {
            int i = ind2;
            while(i < p.size() && ((i + 1 < p.size() && '*' == p[i + 1]))) i += 2;
            dp[m][ind2] = i == p.size();
        }

        for(int ind1 = m - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n - 1; ind2 >= 0; ind2--)
            {
                bool flag = false;
                if(ind2 + 1 < p.size() && p[ind2 + 1] == '*')
                {
                    bool exc = dp[ind1][ind2 + 2];
                    bool inc = s[ind1] == p[ind2] || p[ind2] == '.' ? dp[ind1 + 1][ind2] : false;
                    flag = inc || exc;
                }
                else if(s[ind1] == p[ind2] || p[ind2] == '.') flag = dp[ind1 + 1][ind2 + 1];
                else flag = false;
                
                dp[ind1][ind2] = flag;
            }
        }

        return dp[0][0];
    }
    
    bool solveTabOp(string &s, string &p)
    {
        int m = s.size();
        int n = p.size();
        vector<bool> curr(n + 2, false);
        vector<bool> next(n + 2, false);

        next[n] = true;

        for(int ind2 = 0; ind2 < n + 1; ind2++)
        {
            int i = ind2;
            while(i < p.size() && ((i + 1 < p.size() && '*' == p[i + 1]))) i += 2;
            next[ind2] = i == p.size();
        }

        for(int ind1 = m - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n - 1; ind2 >= 0; ind2--)
            {
                bool flag = false;
                if(ind2 + 1 < p.size() && p[ind2 + 1] == '*')
                {
                    bool exc = curr[ind2 + 2];
                    bool inc = s[ind1] == p[ind2] || p[ind2] == '.' ? next[ind2] : false;
                    flag = inc || exc;
                }
                else if(s[ind1] == p[ind2] || p[ind2] == '.') flag = next[ind2 + 1];
                else flag = false;
                
                curr[ind2] = flag;
            }
            next = curr;
        }

        return curr[0];
    }

    bool isMatch(string s, string p) {
        return solveTabOp(s, p);
        // return solveTab(s, p);
        // vector<vector<int>> dp(s.size() + 2, vector<int>(p.size() + 2, -1));

        // return solveRecMem(s, p, 0, 0, dp);
        // return solveRecMem(s, p, 0, 0);
    }
};