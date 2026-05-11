class Solution {
public:

    int solveRec(vector<int> &arr, int s, int e, map<pair<int, int>, int> &maxi)
    {

        if(s >= e) return 0;

        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int left = maxi[{s, i}];
            int right = maxi[{i + 1, e}];
            ans = min(ans, left * right + solveRec(arr, s, i, maxi) + solveRec(arr, i + 1, e, maxi));
        }

        return ans;
    }

    int solveRecMem(vector<int> &arr, int s, int e, map<pair<int,int>, int> &maxi, vector<vector<int>> &dp)
    {
        if(s >= e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int left = maxi[{s, i}];
            int right = maxi[{i + 1, e}];

            ans = min(ans, left * right + solveRecMem(arr, s, i, maxi, dp) + solveRecMem(arr, i + 1, e, maxi, dp));
        }

        return dp[s][e] = ans;
    }

    int solveTab(vector<int> &arr, map<pair<int,int>, int> &maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // s = 0 -> e || e -> 0;
        // e = n -> s || s -> e;

        for(int s = n - 1; s >= 0; s--)
        {
            for(int e = 0; e < n; e++)
            {
                if(s >= e) continue;

                int ans = INT_MAX;
                for(int i = s; i < e; i++)
                {
                    int left = maxi[{s, i}];
                    int right = maxi[{i + 1, e}];
                    ans = min(ans, left * right + dp[s][i] + dp[i + 1][e]);
                }
                dp[s][e] = ans;

            }
        }

        return dp[0][n - 1];

    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>, int> maxi;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i; j < arr.size(); j++) maxi[{i, j}] = j == i ? arr[i] : max(maxi[{i, j - 1}], arr[j]);
        }

        return solveTab(arr, maxi);
        // return solveRecMem(arr, 0, arr.size() - 1, maxi, dp);
        // return solveRec(arr, 0, arr.size() - 1, maxi);

    }
};