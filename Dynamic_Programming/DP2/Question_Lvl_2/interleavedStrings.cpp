class Solution {
  public:
  
    bool solveRec(string &s1, string &s2, string &s3, int i, int j)
    {
        if(s1.size() == i && s2.size() == j) return true;
        if(s1.size() == i && s2.size() != j)
        {
            while(i + j < s3.size() && s2[j] == s3[i + j]) j++;
            return (i + j) == s3.size();
        }
        
        if(s1.size() != i && s2.size() == j)
        {
            while(i + j < s3.size() && s1[i] == s3[i + j]) i++;
            return (i + j) == s3.size();
        }

        bool flag = false;
        if(s1[i] == s3[i + j] || s2[j] == s3[i + j])
        {
            if(s1[i] == s3[i + j]) flag = flag || solveRec(s1, s2, s3, i + 1, j);
            if(s2[j] == s3[i + j]) flag = flag || solveRec(s1, s2, s3, i, j + 1);
        }
        else flag = false;
        return flag;
        
    }
    
    bool solveRecMem(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp)
    {
        if(s1.size() == i && s2.size() == j) return true;
        if(s1.size() == i && s2.size() != j)
        {
            while(i + j < s3.size() && s2[j] == s3[i + j]) j++;
            return (i + j) == s3.size();
        }
        
        if(s1.size() != i && s2.size() == j)
        {
            while(i + j < s3.size() && s1[i] == s3[i + j]) i++;
            return (i + j) == s3.size();
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s1[i] == s3[i + j] || s2[j] == s3[i + j])
        {
            if(s1[i] == s3[i + j]) flag = flag || solveRecMem(s1, s2, s3, i + 1, j, dp);
            if(s2[j] == s3[i + j]) flag = flag || solveRecMem(s1, s2, s3, i, j + 1, dp);
        }
        else flag = false;
        return dp[i][j] = flag;
    }
  
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        if(s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return solveRecMem(s1, s2, s3, 0, 0, dp);
        // return solveRec(s1, s2, s3, 0, 0);
    }
};