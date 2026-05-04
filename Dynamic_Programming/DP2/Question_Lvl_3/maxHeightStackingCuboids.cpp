class Solution {
public:
    bool isBigger(vector<int> &first, vector<int> &second)
    {
        for(int i = 0; i < first.size(); i++) if(first[i] > second[i]) return false;
        return true;
    }
    int solveRec(vector<vector<int>> &arr, int ind, int prev)
    {
        if(ind >= arr.size()) return 0;

        int inc = (prev == -1 || isBigger(arr[prev], arr[ind]) ? arr[ind][2] + solveRec(arr, ind + 1, ind) : 0);
        int exc = solveRec(arr, ind + 1, prev);
        return max(inc, exc);
    }
    
    int solveRecMem(vector<vector<int>> &arr, int ind, int prev, vector<vector<int>> &dp)
    {
        if(ind >= arr.size()) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int inc = (prev == -1 || isBigger(arr[prev], arr[ind]) ? arr[ind][2] + solveRecMem(arr, ind + 1, ind, dp) : 0);
        int exc = solveRecMem(arr, ind + 1, prev, dp);
        return dp[ind][prev + 1] = max(inc, exc);
    }

    int solveTab(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        // ind - 0 -> n;
        // prev - -1 -> ind;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j >= -1; j--)
            {
                int inc = (j == -1 || isBigger(arr[j], arr[i]) ? arr[i][2] + dp[i + 1][i + 1] : 0);
                int exc = dp[i + 1][j + 1];
                dp[i][j + 1] = max(inc, exc);
            }
        }

        return dp[0][0];
    }
    
    int solveTabOp(vector<vector<int>> &arr)
    {
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        vector<int> curr(n + 2, 0);
        vector<int> next(n + 2, 0);

        // ind - 0 -> n;
        // prev - -1 -> ind;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j >= -1; j--)
            {
                int inc = (j == -1 || isBigger(arr[j], arr[i]) ? arr[i][2] + next[i + 1] : 0);
                int exc = next[j + 1];
                curr[j + 1] = max(inc, exc);
            }

            next = curr;
        }

        return curr[0];
    }
    
    int solveTabOp2(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> curr(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = -1; j <= i; j++)
            {
                int inc = (j == -1 || isBigger(arr[j], arr[i]) ? arr[i][2] + curr[i + 1] : 0);
                int exc = curr[j + 1];
                curr[j + 1] = max(inc, exc);
            }
        }

        return curr[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i : cuboids) sort(i.begin(), i.end());
        sort(cuboids.begin(), cuboids.end());
        
        return solveTabOp2(cuboids);
        // return solveTabOp(cuboids);
        // return solveTab(cuboids);
        
        // int n = cuboids.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        // return solveRecMem(cuboids, 0, -1, dp);
        // return solveRec(cuboids, 0, -1);
    }
};