class Solution {
public:

    int solveRec(vector<int> &arr, int ind, int m, bool alice){
        if(ind == arr.size()) return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int x = 1; x <= 2 * m; x++)
        {
            if(ind + x - 1 == arr.size()) break;
            total += arr[ind + x - 1];
            if(alice) ans = max(ans, total + solveRec(arr, ind + x, max(m, x), !alice));
            else ans = min(ans, solveRec(arr, ind + x, max(m, x), !alice));
        }

        return ans;
    }
    
    int solveRecMem(vector<int> &arr, int ind, int m, bool alice, vector<vector<vector<int>>> &dp){
        if(ind == arr.size()) return 0;

        if(dp[ind][m][alice] != -1) return dp[ind][m][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int x = 1; x <= 2 * m; x++)
        {
            if(ind + x - 1 == arr.size()) break;
            total += arr[ind + x - 1];
            if(alice) ans = max(ans, total + solveRecMem(arr, ind + x, max(m, x), !alice, dp));
            else ans = min(ans, solveRecMem(arr, ind + x, max(m, x), !alice, dp));
        }

        return dp[ind][m][alice] = ans;
    }

    int solveTab(vector<int> &arr)
    {
        vector<vector<vector<int>>> dp(arr.size() + 1, vector<vector<int>>(arr.size() + 1, vector<int>(2, 0)));

        for(int i = arr.size() - 1; i >= 0; i--)
        {
            for(int m = arr.size(); m >= 1; m--)
            {
                for(int alice = 0; alice <= 1; alice++)
                {
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;

                    for(int x = 1; x <= 2 * m; x++)
                    {
                        if(i + x - 1 == arr.size()) break;
                        total += arr[i + x - 1];
                        if(alice) ans = max(ans, total + dp[i + x][max(m, x)][!alice]);
                        else ans = min(ans, dp[i + x][max(m, x)][!alice]);
                    }
                    dp[i][m][alice] = ans;
                }
            }
        }

        return dp[0][1][1];
        
    }

    int stoneGameII(vector<int>& piles) {
        return solveTab(piles);
        // vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        // return solveRecMem(piles, 0, 1, true, dp);
        // return solveRec(piles, 0, 1, true);
    }
};