class Solution {
public:

    int intValue(char s){
        return (int)(s);
    }

    int rangeSum(string &s, int ind)
    {
        int sum = 0;
        for(int i = ind; i < s.size(); i++) sum += intValue(s[i]);

        return sum;
    }

    int solveRec(string &s1, string &s2, int ind1, int ind2)
    {
        if(ind1 == s1.size() && ind2 == s2.size()) return 0;
        if(ind1 != s1.size() && ind2 == s2.size()) return rangeSum(s1, ind1);
        if(ind1 == s1.size() && ind2 != s2.size()) return rangeSum(s2, ind2);

        if(s1[ind1] == s2[ind2]) return solveRec(s1, s2, ind1 + 1, ind2 + 1);

        int val1 = intValue(s1[ind1]);
        int val2 = intValue(s2[ind2]);

        int inc1 = val1 + solveRec(s1, s2, ind1 + 1, ind2);
        int inc2 = val2 + solveRec(s1, s2, ind1, ind2 + 1);
        int exc = val1 + val2 + solveRec(s1, s2, ind1 + 1, ind2 + 1);

        return min(inc1, min(inc2, exc));
    }
    
    int solveRecMem(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 == s1.size() && ind2 == s2.size()) return 0;
        if(ind1 != s1.size() && ind2 == s2.size()) return rangeSum(s1, ind1);
        if(ind1 == s1.size() && ind2 != s2.size()) return rangeSum(s2, ind2);
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) return solveRecMem(s1, s2, ind1 + 1, ind2 + 1, dp);

        int val1 = intValue(s1[ind1]);
        int val2 = intValue(s2[ind2]);

        int inc1 = val1 + solveRecMem(s1, s2, ind1 + 1, ind2, dp);
        int inc2 = val2 + solveRecMem(s1, s2, ind1, ind2 + 1, dp);
        int exc = val1 + val2 + solveRecMem(s1, s2, ind1 + 1, ind2 + 1, dp);

        return dp[ind1][ind2] = min(inc1, min(inc2, exc));
    }

    int solveTab(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int sum = 0;
        for(int ind1 = n1 - 1; ind1 >= 0; ind1--)
        {
            sum += intValue(s1[ind1]);
            dp[ind1][n2] = sum;
        }

        sum = 0;
        for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
        {
            sum += intValue(s2[ind2]);
            dp[n1][ind2] = sum;
        }

        for(int ind1 = n1 - 1; ind1 >= 0; ind1--)
        {
            for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
            {
                int temp = INT_MAX;
                if(s1[ind1] == s2[ind2]) temp = dp[ind1 + 1][ind2 + 1];

                int val1 = intValue(s1[ind1]);
                int val2 = intValue(s2[ind2]);

                int inc1 = val1 + dp[ind1 + 1][ind2];
                int inc2 = val2 + dp[ind1][ind2 + 1];
                int exc = val1 + val2 + dp[ind1 + 1][ind2 + 1];

                dp[ind1][ind2] = min(min(inc1,temp), min(inc2, exc));
            }
        }

        return dp[0][0];

    }

    int solveTabOp(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        vector<int> curr(n2 + 1, 0);
        vector<int> next(n2 + 1, 0);

        int sum = 0;
        for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
        {
            sum += intValue(s2[ind2]);
            next[ind2] = sum;
        }
        
        sum = 0;

        for(int ind1 = n1 - 1; ind1 >= 0; ind1--)
        {
            sum += intValue(s1[ind1]);
            curr[n2] = sum;
            for(int ind2 = n2 - 1; ind2 >= 0; ind2--)
            {
                int temp = INT_MAX;
                if(s1[ind1] == s2[ind2]) temp = next[ind2 + 1];

                int val1 = intValue(s1[ind1]);
                int val2 = intValue(s2[ind2]);

                int inc1 = val1 + next[ind2];
                int inc2 = val2 + curr[ind2 + 1];
                int exc = val1 + val2 + next[ind2 + 1];

                curr[ind2] = min(min(inc1,temp), min(inc2, exc));
            }
            next = curr;
        }

        return curr[0];

    }

    int minimumDeleteSum(string s1, string s2) {
        return solveTabOp(s1, s2);
        // return solveTab(s1, s2);
        
        // int n1 = s1.size();
        // int n2 = s2.size();

        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // return solveRecMem(s1, s2, 0, 0, dp);
        // return solveRec(s1, s2, 0, 0);
    }
};